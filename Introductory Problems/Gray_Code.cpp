/*
    5 into binary --> 1 0 1
    convert 1 0 1 into gray code
    -> first write left most bit as it is
        i.e 1
    -> then from left most bit to just before do this
        say i from left to (right_end - 1)
        do -> (bit[i]^bit[i+1])
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

vector<int> n_size_bit(int num, int n) {
    vector<int> ans(n, 0);
    int i = n-1;
    while(num > 0) {
        ans[i] = num%2;
        num /= 2;
        i--;
    }
    return ans;
}

vector<int> binary_to_gray(vector<int> &binary) {
    vector<int> ans; ans.push_back(binary[0]);
    int n = binary.size();
    for(int i = 0; i < n-1; i++) ans.push_back(binary[i]^binary[i+1]);

    return ans;
}

void solve() {
    int n; cin >> n;
    
    vector<int> bit;
    vector<int> gray;
    for(int i = 0; i < (1 << n); i++) {
        bit = n_size_bit(i, n);
        gray = binary_to_gray(bit);
        for(int el: gray) cout << el;
        cout << endl;
        bit.clear(); gray.clear();
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