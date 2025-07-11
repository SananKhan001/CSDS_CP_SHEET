/*
    solution : https://www.youtube.com/watch?v=lIr78Tj1qww
    if n is even say, 2*m
    then, f(n) = f(2*m) = 2f(m) - 1;
    else if n is odd say, 2m+1
    then, f(n) = f(2*m) + 1;

    for n = 1, f(1) = 1
    ==> above solution will take time comp - log(n)
    
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

int doit(int n, int k) {
    if(n == 1) return 1;
    if(k <= (n+1)/2) {
        if(2*k > n) return (2*k)%n;
        else return 2*k;
    }

    if(n%2 == 0) return (2*doit(n/2, k - ((n+1)/2)))-1;
    else return (2*doit(n/2, k - ((n+1)/2))) + 1;
}

void solve() {
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        cout << doit(n, k) << endl;
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