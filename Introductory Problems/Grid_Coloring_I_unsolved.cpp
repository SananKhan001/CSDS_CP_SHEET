/*
 Not solved yet
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

char colors[4] = {'A', 'B', 'C', 'D'};
int x[4] = {+1, -1, 0, 0};
int y[4] = {0, 0, +1, -1};
vector<vector<char>> initialClr;
bool gridColoring(vector<vector<char>> &grid, int n, int m, int i, int j, vector<vector<int>> &path) {
    path[i][j] = 1;
    for(int p = 0; p < 4; p++) {
        bool isColliding = false;
        for(int q = 0; q < 4; q++) {
            int nxt_i = i+x[q], nxt_j = j+y[q];
            if((nxt_i >= 0 && nxt_j >= 0 && nxt_i < n && nxt_j < m &&
                path[nxt_i][nxt_j] == 1 && grid[nxt_i][nxt_j] == colors[p]) ||
                (initialClr[i][j] == colors[p])) {
                    isColliding = true; break;
                }
        }
        if(isColliding) continue;
        grid[i][j] = colors[p];
        for(int q = 0; q < 4; q++) {
            int nxt_i = i+x[q], nxt_j = j+y[q];
            if(nxt_i >= 0 && nxt_j >= 0 && nxt_i < n && nxt_j < m &&
               path[nxt_i][nxt_j] == 0 && !gridColoring(grid, n, m, nxt_i, nxt_j, path)) {
                    path[i][j] = 0;
                    grid[i][j] = initialClr[i][j];
                    return false;
            }
        }
    }
    path[i][j] = 0;
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m, 'A'));
    vector<vector<int>> path(n, vector<int> (m, 0));
    initialClr.resize(n, vector<char> (m, 'A'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            initialClr[i][j] = grid[i][j];
        }
    }

    bool isPossible = gridColoring(grid, n, m, 0, 0, path);
    if(isPossible) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.precision(10);
   cout << fixed;

   solve();

   return 0;
}