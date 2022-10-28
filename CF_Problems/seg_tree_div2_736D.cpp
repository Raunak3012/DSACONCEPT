// C++ Program to find GCD of a number in a given Range
// using segment Trees
#include <bits/stdc++.h>
using namespace std;

typedef std::numeric_limits< double > dbl;

typedef long long ll;
typedef unsigned long long ull;

#define pf push_front
#define pb push_back


ll gcd(ll a, ll b){
  if (b == 0){ return a; }
  return gcd(b, a % b);
}



// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
ll build(ll start,ll end,ll index, vector<ll> &seg,vector<ll> &arr){
 
    if(start > end){
        return 0;
    } 
 
    if(start == end){
        return seg[index] = arr[start];
    }
 
    ll mid = (start+end)/2;
 
    //return seg[index] = gcd(left_child ,right_child)); 
    return seg[index] = gcd(build(start,mid,2*index,seg,arr),build(mid+1,end,2*index+1,seg,arr));
 
}
 
/* 

E.g 
** implies returned 

for query (1,3) inclusive for length 5 array

Here   (0,4)
      /  \   
     /     \
    /       \
    (0,2)  (3,4)
                /\
    /  \       /  \
   /    \    (3,3)**  (4,4)
 (0,1)   (2,2)**
  / \ 
 /   \
(0,0) (1,1)**


Clearly, gcd of positions (1,2,3) will be returned by the tree.

*/

ll query(ll start,ll end,ll query_start,ll query_end,ll index, vector<ll> &seg){
    
    // if query_range not in current range
    if(query_start > end  or  query_end < start){
        return 0;
    } 
    
    if(start > end){
        return 0;
    } 
 
    // if current_range (of index ) is a subset of query_range
    if(query_start <=start and query_end >= end){
        return seg[index];
    } 
 
    ll mid = (start+end)/2;
 
    ll left_gcd = query(start,mid,query_start,query_end,2*index,seg);
    ll right_gcd = query(mid+1,end,query_start,query_end,2*index+1,seg);

    return gcd(left_gcd,right_gcd);
 
}


// with help of editorial, https://codeforces.com/contest/1549/submission/124584384

// https://www.youtube.com/watch?v=y35TUit_STQ
// https://www.geeksforgeeks.org/gcds-of-a-given-index-ranges-in-an-array/



// Driver program to test above functions
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif

    //cout<<gcd(1,2)<<"\n";

    // handle corner cases well..

    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        else if(n==2){
            if(v[0]==1 or v[1]==1){
                cout<<1<<"\n";
                continue;
            }
            cout<<2<<"\n";
            continue;
        }
        vector<ll> diff(n-1);
        
        for (ll i = 0; i < n-1; i++)
        {
            diff[i] = abs(v[i+1]-v[i]);
        }

        vector<ll> seg(4*n+1,0);

        build(0,n- 2, 1,seg, diff );

        ll max_len=1;

        ll start=0;
        ll end= 0;

        ll curr = diff[0];
        // sliding window
        while(end<n-1){
            
            if(abs(diff[end]) == 1){
 
                 start = end +1;
                 end = start;
                 if(end<n-1)
                    curr  = diff[end];
                 continue;
             }

            max_len = max(max_len, end-start+2);

            if(end+1<n-1 and abs(gcd(curr,diff[end+1]))>1){
                end++;
                curr = abs(gcd(curr,diff[end ]));
                
                
            }
            else if(end+1<n-1 and abs(gcd(curr,diff[end+1]))==1){
                start++;
                if(end<start){
                    end++;
                    
                }
                curr = query(0,n-2,start,end,1,seg);
                
            }
            else if(end+1==n-1){
                //max_len = max(max_len, end-start+2);
                break;
            }
                
        }

        cout<<max_len<<"\n";
    }
    
    /*
	vector<ll>  a  = {2, 3, 6, 9, 5};
	ll n = sizeof(a)/sizeof(a[0]);



	
    // To store segment tree
	vector<ll> seg(4*n+1,0);

    
    // Build segment tree from given array
    build(0,n-1, 1,seg, a );


	// Starting index of range. These indexes are 0 based.
	ll l = 1;

	// Last index of range.These indexes are 0 based.
	ll r = 3;
	cout << "GCD of the given range is:";
	cout << query(0,n-1,l, r, 1, seg) << "\n";

    */


	return 0;
}
