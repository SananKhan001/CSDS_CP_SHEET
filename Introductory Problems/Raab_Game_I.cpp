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

void doit() {
    int n; cin >> n; 
    int a, b; cin >> a >> b;

    if(a+b > n || ((a == 0 && b != 0) || (a != 0 && b == 0))) {
        cout << "NO" << endl;
        return;
    }

    int a_low = 1, b_low = 1, a_high = n, b_high = n;
    vector<int> a_step;
    vector<int> b_step;

    int draw = n - (a+b);
    for(int i = 0; i < draw; i++) {
        a_step.push_back(a_high); a_high--;
        b_step.push_back(b_high); b_high--;
    }
    while(a--) {
        a_step.push_back(a_high); a_high--;
        b_step.push_back(b_low); b_low++;
    }
    while(a_low <= a_high) a_step.push_back(a_low++);
    while(b_low <= b_high) b_step.push_back(b_low++);

    cout << "YES" << endl;
    for(int el: a_step) cout << el << " ";
    cout << endl;
    for(int el: b_step) cout << el << " ";
    cout << endl;
}

void solve() {
    int t; cin >> t; 
    while(t--) {
        doit();
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