/*
    application of inclusion-exclusion 
    video: https://www.youtube.com/watch?v=2H65yrmM0wY&t=1596s
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

void solve() {
    int n; cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int maxi = 0;
    for(int el: arr) maxi = max(maxi, el);

    vector<vector<int>> primeDivisorsOf(maxi+1, vector<int>());
    for(int i = 2; i <= maxi; i++) {
        if(primeDivisorsOf[i].empty()) {
            for(int j = i; j <= maxi; j+=i) {
                primeDivisorsOf[j].push_back(i);
            }
        }
    }

    vector<int> arrElementsDivisibleBy(maxi+1, 0);
    vector<int> noOfPrimesIn(maxi+1, 0);

    for(int el: arr) {
        auto divisors = primeDivisorsOf[el];
        int size = divisors.size();
        for(int i = 1; i < (1 << size); i++) {
            int mul = 1, count = 0, setBits = 0;
            int temp = i;
            while(temp > 0) {
                int curr = temp%2; temp /= 2;
                count++;
                if(curr) {
                    setBits++;
                    mul *= divisors[size-count];
                }
            }
            noOfPrimesIn[mul] = setBits;
            arrElementsDivisibleBy[mul]++;
        }
    }

    int invalid_ss = 0;
    for(int i = 2; i <= maxi; i++) {
        if(noOfPrimesIn[i]%2) invalid_ss += (arrElementsDivisibleBy[i]*(arrElementsDivisibleBy[i]-1))/2;
        else invalid_ss -= (arrElementsDivisibleBy[i]*(arrElementsDivisibleBy[i]-1))/2;
    }

    cout << ((n*(n-1))/2) - invalid_ss << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}