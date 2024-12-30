#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, ans = 0, last = -1;
        string S;
        
		cin >> N;
        cin >> S;
        
        // first A
        for (int i=0; i<N; i++) {
            if (S[i] == 'A') {
                last = i;
                break;
            }
        }

        // calc
        if (last > -1) {
            for (int i=last+1; i<N; i++) {
                if (S[i] == 'A') {
                    if (i-last < 3) {
                        // ABA : ok, ABBA : pass
                        ans += (3-(i-last));
                    }
                    
                    last = i;
                }
            }
        }

        cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
    }

	return 0;
}