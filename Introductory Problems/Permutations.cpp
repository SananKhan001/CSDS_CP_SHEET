#include <bits/stdc++.h>
#define int long long

using namespace std;

void sol() {
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    } else if(n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    } else if(n == 4) {
        cout << "2 4 1 3" << endl;
        return;
    }

    vector<int> arr(n, 0);
    
    int count = 1;
    for(int i = 0; i < n; i += 2) {
        arr[i] = count; count++;
    }
    for(int i = 1; i < n; i += 2) {
        arr[i] = count; count++;
    }
    
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int32_t main() {
	// your code goes here
	
	sol();
	
    return 0;
    "sanan"
}
