/*

    pow(a, pow(b, c)) this will be wrong bcz, 
    let say a = 2, pow(b,c) = 1e9+7
    therefore pow(b,c)%1e9+7 = 0
    => pow(2, 0) = 1
    which is wrong 
    
    pow(a, pow(b, c)) = pow(a, r)
    r = pow(b, c)%(M-1)
    proof --> https://www.youtube.com/watch?v=YPJ38aWeyGI
*/

#include <bits/stdc++.h>  // This will work only for g++ compiler.
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
//short hand for usual tokens
#define pb push_back
#define fi first
#define se second
#define int long long

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
// const int M = 1e9+7;

int doit(int a, int b, int M) {
    if(b == 1) return a;
    if (b == 0 || a == 1) return 1;

    if(b%2 == 0) {
        int pow_hlf = (doit(a, b/2, M)%M);
        return (pow_hlf*pow_hlf)%M;
    } else {
        int pow_hlf = doit(a, (b-1)/2, M)%M;
        return (((pow_hlf*pow_hlf)%M)*a)%M;
    }
}

void solve() {
    int n; cin >> n;
    int M = 1e9+7;
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        int r = doit(b, c, M-1)%(M-1);
        cout << doit(a, r, M) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}