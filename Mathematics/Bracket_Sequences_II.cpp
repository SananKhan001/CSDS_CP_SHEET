/*
    if n is odd then, 0 solution
    then we have to check prefix, prefix should not go negative at any index

    then, for n-k length we have to calculate number of ')' we have to put 
        -> which will be given by this formula, r = (n-k + #'(')/2 ; #'(' is number of extra '('
        if we do not have enough space to put r ')' then we can't have solution
        
        first of all from n-k positions we have to choose r positions to put ')'
        (n-k)Cr____(1)
        now we have to get invalid permutations
        if we will turn '(' of invalid permutations into ')' after the position where it fails
        we will see r+1 ')' brackets
        those permutations will be, (n-k)Cr+1 ____(2)
    therefore we have to do (1)-(2)
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
            if (b > a || b < 0) return 0;
            return ((((factorial[a]%modulo)*(inverseFactorial[a-b]%modulo))%modulo)*(inverseFactorial[b]%modulo))%modulo;
        }

};

int check(string str) {
    int count = 0;
    for(char ch: str) {
        if(ch == '(') count++;
        else count--;

        if(count < 0) return count;
    }

    return count;
}

const int MOD = 1e9+7;
Factorial fc(1e6, MOD);
void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int k = str.length();
    int ans = 0;
    int extra_o = check(str);
    int r = (n-k+extra_o)/2;
    if(n%2 == 0 && extra_o >= 0 && r <= (n-k)) {
        ans = ((fc.binomialCoefficientOf(n-k, r) - fc.binomialCoefficientOf(n-k, r+1))+MOD)%MOD;
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    solve();

    return 0;
}