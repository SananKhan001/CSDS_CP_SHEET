/*
    Using Binary Search

    l = 1, h = k;
    count position of each mid
    then analyse
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

vector<int> countDigit(19, 0); // gives total characters till countDigit[i]-1
vector<int> nDigitNum(19, 0); // gives smalles nDigit num
void setCount() {
    nDigitNum[0] = 0;
    nDigitNum[1] = 1;
    for(int i = 2; i < 19; i++) {
        nDigitNum[i] = (nDigitNum[i-1]*10);
    }

    for(int i = 2; i < 19; i++) {
        countDigit[i] = countDigit[i-1] + ((((nDigitNum[i]-1) - (nDigitNum[i-1]))+1)*(i-1));
    }
}

int getDigit(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int check(int m, int pos, int k) {
    while(m > 0 && pos > k) {
        m /= 10;
        pos--;
    }
    if(pos == k && m > 0) return m%10;
    return -1;
}

void solve() {
    int q; cin >> q;
    while(q--) {
        int k; cin >> k;
        int l = 1, h = k;
        while(l <= h) {
            int m = l + (h - l) / 2;

            int totalDigit = getDigit(m);
            // this will give position of last digit of m
            int position = (((m - nDigitNum[totalDigit])+1)*totalDigit) + countDigit[totalDigit];
            
            if(position < k) l = m+1;
            else {
                int chek_num = check(m, position, k);
                if(chek_num != -1) {
                    cout << chek_num << endl;
                    break;
                } 
                else h = m-1;
            }
        }
    }
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.precision(10);
   cout << fixed;
   setCount();
   solve();

   return 0;
}