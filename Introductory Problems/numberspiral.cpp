// solution link: https://www.youtube.com/watch?v=zwbffeEX1b0

#include <bits/stdc++.h>
#define int long long

using namespace std;

void sol() {
    int t; cin >> t;
    while(t--) {
        int i_r, j_r; cin >> i_r >> j_r; i_r--; j_r--;
        
        int n = max(i_r+1, j_r+1); // section number
        int mini = ((n-1)*(n-1)) + 1; // sum of n-1 odd number
        int maxi = mini + (2*n) - 2; // nth odd number
        
        if(i_r >= j_r) {
            if(n%2 == 0) {
                cout << maxi - j_r << endl;
            } else {
                cout << mini + j_r << endl;
            }
        } else {
            if(n%2 == 0) {
                cout << mini + i_r << endl;
            } else {
                cout << maxi - i_r << endl;
            }
        }
    }
}

int32_t main() {
	// your code goes here
	
	sol();
	
    return 0;
}
