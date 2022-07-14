#include <iostream>

using namespace std;

int main() {
	int T, test_case, n, Answer, x;
	
	cin >> T;
	for(test_case = 1; test_case  <= T; test_case++) {
	    cin >> n;
		Answer = 0;
		for (int i=0; i<n; i++) {
		    cin >> x;
		    Answer ^= x;
		}
		cout << "Case #" << test_case << "\n";
		cout << Answer << "\n";
	}

	return 0;
}
