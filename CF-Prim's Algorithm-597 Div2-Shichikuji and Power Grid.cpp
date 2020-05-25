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

const double pi = acos(-1.0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ini mx=2e3+5;
int p[mx];

int f(int a)
{
    if(p[a]<=0) return a;
    return p[a] = f(p[a]);//Like dp // path compression
}

void u(int a, int b)
{
    p[a]=-(max(abs(p[a]),abs(p[b])));
    p[b]=a;
}

void mst(vector<pair<int,pii>> &g,int n)
{
    sort(g.begin(),g.end());//sorted by the first element
    int ans=0;
    fl(i,1,n+1) p[i]=-i;
    vi power_plant;
    vt(pii) connection;
    for(auto x:g){
        int N1 = x.ss.ff;
        int N2 = x.ss.ss;
        if(f(N1)!=f(N2)){
            u(f(N1),f(N2));
            ans+=x.ff;
            if(N1==0) power_plant.pb(N2);
            else if(N2==0) power_plant.pb(N1);
            else connection.pb({N1,N2});
        }
    }
    cout<<ans<<endl;
    cout<<power_plant.size()<<endl;
    for(auto x:power_plant) cout<<x<<" ";
    cout<<endl;
    cout<<connection.size()<<endl;
    for(auto x:connection) cout<<x.ff<<" "<<x.ss<<endl;
}

void solve()
{
    int n;
    cin>>n;
    vt(pii) pos(n+1);//1 based indexing
    vi c(n+1),k(n+1);
    vector<pair<int,pii>> g;
    fl(i,1,n+1) cin>>pos[i].ff>>pos[i].ss;
    fl(i,1,n+1) cin>>c[i];
    fl(i,1,n+1) cin>>k[i];
    fl(i,1,n+1){
        g.pb({c[i],{i,0}});
        fl(j,i+1,n+1){
            int w = abs(pos[i].ff-pos[j].ff)+abs(pos[i].ss-pos[j].ss);
            w*=(k[i]+k[j]);
            g.pb({w,{i,j}});
        }
    }
    mst(g,n);
}

int32_t main()
{
	omniphantom
	solve();
	return 0;
}