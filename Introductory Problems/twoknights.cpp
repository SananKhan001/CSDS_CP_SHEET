/*

total possible arrangement of two knights = ((n^4) - (n^2))/2 ---1
    => (n*n((n*n) - 1))/2 
    --> got this by this logic, 
        total number of blocks = n^2 
        say, x = n*n
        therefore in n*n blocks we have to choose two blocks 
        i.e xC2 will endup with above formula

now we have to calculate invalid positions,---2
    --> now, in each 2*3 or 3*2 box there will be two invalid
        positions.
        so we have to count number of boxes with dimensions, 
        2*3 or 3*2
        
    --> considering number of adjacent 2 vertical lines and 3 horizontal 
        lines and vice versa we will endup with
        no. of invalid combinations = 2*(2*(n-2)*(n-3)) = 4*(n-1)*(n-2)
        
now simply do (1)-(2) = ((n*n((n*n) - 1))/2) - (4*(n-1)*(n-2))

*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

void sol() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << ((((i*i)*((i*i) - 1))/2) - (4*(i-1)*(i-2))) << endl;
    }
}

int32_t main() {
	// your code goes here
	sol();
    return 0;
}
