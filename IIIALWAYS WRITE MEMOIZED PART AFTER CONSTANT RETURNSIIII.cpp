#include<bits/stdc++.h>
using namespace std;

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
#define fio             ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define mii             map<int,int>
#define pqb             priority_queue<int>
//Below is implementation of min heap
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             100000000 
#define inf             LLONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ini             const int
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

int n1,n2,k1,k2;
int dp[101][101][11][11];

//ALWAYS WRITE MEMOIZED PART AFTER CONSTANT RETURNS

int f(int n1,int n2, int cck1, int cck2)
{
    if(n1==0 && n2==0 && cck1<=k1 && cck2<=k2) return 1;
    if(n1<0 || n2<0) return 0;
    if(cck1>k1) return 0;
    else if (cck2>k2) return 0;
    if(dp[n1][n2][cck1][cck2]!=-1) return dp[n1][n2][cck1][cck2];
    return dp[n1][n2][cck1][cck2]=(f(n1-1,n2,cck1+1,0)+f(n1,n2-1,0,cck2+1))%mod;
}

int32_t main()
{
	fio;
	memset(dp,-1,sizeof(dp));
    cin>>n1>>n2>>k1>>k2;
    cout<<f(n1,n2,0,0)<<endl;
	return 0;
}
