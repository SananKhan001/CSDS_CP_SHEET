/*
   |f(n)  |    = {{1 1},^(n-1) * {{f(1)},
   |f(n-1)|       {1 0}}          {f(0)}}
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
const int MOD = 1e9+7;

vector<vector<int>> matMUL(vector<vector<int>> mat1, vector<vector<int>> mat2) {
    int a = mat1[0][0]%MOD, b = mat1[0][1]%MOD, c = mat1[1][0]%MOD, d = mat1[1][1]%MOD;
    int e = mat2[0][0]%MOD, f = mat2[0][1]%MOD, g = mat2[1][0]%MOD, h = mat2[1][1]%MOD;

    int A = ((a*e)%MOD + (b*g)%MOD)%MOD, 
        B = ((a*f)%MOD + (b*h)%MOD)%MOD, 
        C = ((c*e)%MOD + (d*g)%MOD)%MOD, 
        D = ((c*f)%MOD + (d*h)%MOD)%MOD;

    return {{A, B},
            {C, D}};
}

vector<vector<int>> matrixBinaryExponentiation(vector<vector<int>> mat, int n) {
    if(n == 0) return {{1, 0}, 
                       {0, 1}};

    vector<vector<int>> res = matrixBinaryExponentiation(mat, n/2);
    if(n%2 == 0) return matMUL(res, res);
    else return matMUL(matMUL(res, res), mat);
}

void solve() {
    int n; cin >> n;
    if(n == 0) {
        cout << n << endl;
        return;
    }
    vector<vector<int>> res = matMUL(matrixBinaryExponentiation({{1, 1}, {1, 0}}, n-1), {{1}, {0}});

    cout << res[0][0] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}