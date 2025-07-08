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

void solve() {
    string str; cin >> str;
    vector<int> mp(26, 0);
    for(char ch: str) mp[ch-'A']++;

    int count = 0;
    char odd_ch = '$';
    for(int i = 0; i < 26; i++) {
        if(mp[i] % 2 == 1) {
            count++;
            odd_ch = i+'A';
            if(count > 1) {
                cout << "NO SOLUTION" << endl;
                return;
            }
        }
    }

    // string pal = "";
    // if(odd_ch != '$') {
    //     for(int i = 0; i < mp[odd_ch-'A']; i++) pal = pal + odd_ch;
    //     mp[odd_ch-'A'] = 0;
    // }

    // for(int i = 0; i < 26; i++) {
    //     for(int j = 0; j < (mp[i]/2); j++) {
    //         pal = char('A'+i) + pal + char('A'+i);
    //     }
    // }
    // cout << pal << endl;

    string left = "", middle = "";

    // Add middle character (odd frequency)
    if (odd_ch != '$') {
        middle = string(mp[odd_ch - 'A'], odd_ch);
        mp[odd_ch - 'A'] = 0;
    }

    // Build half of the palindrome
    for (int i = 0; i < 26; i++) {
        left += string(mp[i] / 2, char('A' + i));
    }

    string right = left;
    reverse(right.begin(), right.end());

    cout << left + middle + right << endl;
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.precision(10);
   cout << fixed;

   solve();

   return 0;
}