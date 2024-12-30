// NlogN : 실패
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
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // possible?
        tmp = abs(A[0]-B[0]);
        for (int i=1; i<N; i++) {
            tmp = max(tmp, abs(A[i]-B[i]));
        }
        if (tmp > L) {
            cout << "Case #" << test_case << '\n';
    		cout << ans << '\n';
            continue;
        }

        // only possible
        ans = max(abs(A[0]-B[N-1]), abs(A[N-1]-B[0]));


        cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
    }

	return 0;
}