#include<bits/stdc++.h>
using namespace std;

//#define endl            "\n"
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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
//#define mod             100000000
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

void solve()
{
    int n,x;
    int ans=0;
    map<int,pii> my;
    my[0]={1,0};//{cnt, sum} count followed by sum till current point
    int xs=0;
    cin>>n;
    fl(i,1,n+1){
        cin>>x;
        xs^=x;
        if(my.find(xs)!=my.end()){
            auto it = my.find(xs);
            auto p = it->ss;
            ans += p.ff*i-p.ss-p.ff;
            p.ff++,p.ss+=i;
            my[xs]=p;
        }
        else my[xs]={1,i};//Initializing with 1 i.e., the count we prepare it or the next sum
    }
    cout<<ans<<endl;
}

int32_t main()
{
	fio;
	w(t) solve();
	return 0;
}
