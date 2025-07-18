/*
    video: https://www.youtube.com/watch?v=R0O3kloGb7Q
    ss: https://drive.google.com/drive/folders/1I6W2Asyiskh2wO_iHnAwXNdyVgvA2iM6 
    modulo inverse:
        p modulo inverse = (p^(mod-2))%mod

    
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

class Factorial {
    private:
        vector<int> factorial, inverseFactorial;
        int modulo;
    public:

        // int moduloBinaryExponentiation(int base, int exponent) {
        //     if(exponent == 0) return 1;

        //     int result = moduloBinaryExponentiation(base, exponent/2)%modulo;
        //     if(exponent%2) return (((result * result)%modulo) * (base%modulo))%modulo;
        //     else return (result*result)%modulo;
        // }
        int moduloBinaryExponentiation(int base, int exponent) {
            int result = 1;
            base = base % modulo;
            while (exponent > 0) {
                if (exponent % 2 == 1)
                    result = (result * base) % modulo;
                base = (base * base) % modulo;
                exponent /= 2;
            }
            return result;
        }

        Factorial(int n, int mod) {
            factorial.resize(n+1, 1);
            inverseFactorial.resize(n+1, 1);
            this->modulo = mod;

            for(int i = 2; i <= n; i++) {
                factorial[i] = ((factorial[i-1]%modulo) * (i%modulo))%modulo;
                inverseFactorial[i] = moduloBinaryExponentiation(factorial[i], modulo-2);
            }
        }

        int factorialOf(int n) {
            return this->factorial[n];
        }

        int inverseFactorialOf(int n) {
            return this->inverseFactorial[n];
        }

        int binomialCoefficientOf(int a, int b) {
            return ((((factorial[a]%modulo)*(inverseFactorial[a-b]%modulo))%modulo)*(inverseFactorial[b]%modulo))%modulo;
        }

};

void solve() {
    int n; cin >> n;
    Factorial* fac = new Factorial(1e6, 1e9+7);
    while(n--) {
        int a, b; cin >> a >> b;
        cout << fac->binomialCoefficientOf(a, b) << endl;
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