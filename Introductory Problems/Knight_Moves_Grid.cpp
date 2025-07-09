/*
    Simple BFS
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

int x[8] = {-2, -2, -1, +1, +2, +2, +1, -1};
int y[8] = {+1, -1, -2, -2, -1, +1, +2, +2};
bool isSafe(vector<vector<int>> &visited, int n, int i, int j) {
    if(i >= 0 && j >= 0 && i < n && j < n && visited[i][j] == 0) return true;
    return false;
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> visited(n, vector<int> (n, 0)), step(n, vector<int> (n, 0));
    queue<vector<int>> q; // {i, j, curr_step}
    q.push({0, 0, 0});
    visited[0][0] = 1;

    while(!q.empty()) {
        int curr_i = q.front()[0];
        int curr_j = q.front()[1];
        int curr_stp = q.front()[2];
        q.pop();

        step[curr_i][curr_j] = curr_stp;

        for(int p = 0; p < 8; p++) {
            int next_i = curr_i + x[p], next_j = curr_j + y[p];
            if(isSafe(visited, n, next_i, next_j)) {
                visited[next_i][next_j] = 1;
                q.push({next_i, next_j, curr_stp+1});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << step[i][j] << " ";
        }
        cout << endl;
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