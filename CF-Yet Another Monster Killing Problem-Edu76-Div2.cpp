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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;
    int a[n+5]={};
    fl(i,0,n) cin>>a[i];
    int m;
    cin>>m;
    int h[n+5]={};
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        h[y]=max(h[y],x);
    }
    for(int i=n-1;i>=0;i--){
        h[i]=max(h[i+1],h[i]);
    }
    int pos = 0;
    int ans = 0;
    int flag = true;
    while(pos<n){
        int newpos=pos;
        int mx = 0;
        while(true){
            mx=max(mx,a[newpos]);
            if(mx>h[newpos-pos+1]) break;
            newpos++;
        }
        if(newpos==pos){
            flag = false;
            break;
        }
        pos=newpos;
        ans++;
    }
    if(flag) cout<<ans<<endl;
    else cout<<-1<<endl;
}

int32_t main()
{
	omniphantom
	w(t) solve();
	return 0;
}
