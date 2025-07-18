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

const int MOD = 1e9+7;
Factorial* fac = new Factorial(1e6, MOD);

int f(int a, int b) {
    int numerator = b+a-1;
    int denomenator1 = b;
    int denomenator2 = a-1;
    int fac_num = 1;
    for(int i = numerator; i >= 1; i--) {
        if(i > 1e6) fac_num = ((fac_num%MOD)*(i%MOD))%MOD;
        else {
            fac_num = ((fac_num%MOD) * (fac->factorialOf(i)%MOD))%MOD;
            break;
        }
    }
    // cout << "fac_num: " << fac_num << endl;

    int inv_fac_d1 = 1;
    for(int i = denomenator1; i >= 1; i--) {
        if(i > 1e6) inv_fac_d1 = ((inv_fac_d1%MOD)*(i%MOD))%MOD;
        else {
            inv_fac_d1 = ((inv_fac_d1%MOD) * (fac->factorialOf(i)%MOD))%MOD;
            break;
        }
    }
    inv_fac_d1 = fac->moduloBinaryExponentiation(inv_fac_d1, MOD-2);

    int inv_fac_d2 = 1;
    for(int i = denomenator2; i >= 1; i--) {
        if(i > 1e6) inv_fac_d2 = ((inv_fac_d2%MOD)*(i%MOD))%MOD;
        else {
            inv_fac_d2 = ((inv_fac_d2%MOD) * (fac->factorialOf(i)%MOD))%MOD;
            break;
        }
    }
    inv_fac_d2 = fac->moduloBinaryExponentiation(inv_fac_d2, MOD-2);

    return ((((fac_num%MOD) * (inv_fac_d1%MOD))%MOD) * (inv_fac_d2%MOD))%MOD;
}

void solve() {
    int a, b; cin >> a >> b;
    cout << f(a, b) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}