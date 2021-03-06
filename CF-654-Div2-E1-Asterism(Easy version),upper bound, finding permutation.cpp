#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;//which means policy based DS

#define endl            "\n"
#define int             long long
#define ff              first
#define ss              second
#define fl(i,a,b)       for(int i=a; i<b; i++)
#define bfl(i,a,b)      for(int i=a-1; i>=b; i--)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vt(type)        vector<type>
#define omniphantom     ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define sz(v)           ((int)(v).size())
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define ppii            pair<int,pii>

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n,p;
    cin>>n>>p;
    vi v(n);
    fl(i,0,n) cin>>v[i];
    //Sort to apply binary search (Since all the stl's upper,lower bounds are binary search algorithms only
    sort(v.begin(),v.end());
    //Brute force and check for all x's
    vi ans;
    fl(x,1,2001){
        //Definitely this x+i will range from x to x+n-1
        //In contiguous fashion
        //We generate all the options
        bool flag = true;
        fl(i,0,n){
            int val = upper_bound(v.begin(),v.end(),x+i)-v.begin()-i;//The '-i' in the end removes the already used up options
            if(val%p==0){
                flag = false;
                break;
            }
        }
        if(flag) ans.pb(x);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
}

int32_t main()
{
	omniphantom
    solve();
	return 0;
}
