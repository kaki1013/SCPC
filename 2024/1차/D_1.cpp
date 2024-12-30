// N!
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, L, tmp;
        int ans = -1;
        vector <int> A, B;
		cin >> N >> L;

        // input
        for (int i=0; i<N; i++) {
            cin >> tmp;
            A.push_back(tmp);
        }

        for (int i=0; i<N; i++) {
            cin >> tmp;
            B.push_back(tmp);
        }

        // sort
        // sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // brute-force
        do {
            tmp = 0;
            for (int i=0; i<N; i++) {
                tmp = max(tmp, abs(A[i]-B[i]));
            }
            if (tmp <= L) ans = max(ans, tmp);

        } while (next_permutation(B.begin(), B.end()));


        cout << "Case #" << test_case <<  endl;
		cout << ans <<  endl;
    }

	return 0;
}