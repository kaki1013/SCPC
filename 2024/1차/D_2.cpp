// N^2 : 실패
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

        // 
        int l, r;
        for (int i = 0; i < N; i++) {
            l = lower_bound(B.begin(), B.end(), A[i]-L) - B.begin();
            r = lower_bound(B.begin(), B.end(), A[i]+L) - B.begin();
            // cout << i << " " << l << " " << r << '\n';
            l = l%N;
            r = r%N;

            // (i, l)
            tmp = (abs(A[i]-B[l]) <= L) ? abs(A[i]-B[l]) : (-1);
            int idxA = i, idxB = 0;
            bool flag=true;
            for (int j=0; j<N; j++) {
                idxA = (idxA+1)%N;
                idxB = (idxB+1)%N;
                if (j == i) idxA = (idxA+1)%N;
                if (j == l) idxB = (idxB+1)%N;
                if (abs(A[idxA]-B[idxB]) > L) {
                    flag = false;
                    break;
                }
                tmp = max(tmp, abs(A[idxA]-B[idxB]));
            }
            if (!flag) continue;
            // cout << 111 << i << " " << ans << " " << tmp << '\n';
            ans = max(ans, tmp);

            // (i, r)
            // cout << 22222 << i << " " << r << " " << abs(A[i]-B[r]) << '\n';
            tmp = (abs(A[i]-B[r]) <= L) ? abs(A[i]-B[r]) : (-1);
            // cout << 22223 << i << " " << r << " " << tmp << '\n';
            idxA = i; idxB = 0;
            flag=true;
            for (int j=0; j<N; j++) {
                idxA = (idxA+1)%N;
                idxB = (idxB+1)%N;
                if (j == i) idxA = (idxA+1)%N;
                if (j == l) idxB = (idxB+1)%N;
                if (abs(A[idxA]-B[idxB]) > L) {
                    flag = false;
                    break;
                }
                tmp = max(tmp, abs(A[idxA]-B[idxB]));
            }
            if (!flag) continue;
            // cout << 222 << i << " " << ans << " " << tmp << '\n';
            ans = max(ans, tmp);
        }

        cout << "Case #" << test_case <<  endl;
		cout << ans <<  endl;
    }

	return 0;
}