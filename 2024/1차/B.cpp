#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, input;
		long long ans = 0;
		cin >> N;
		vector <int> v;
		for (int i=0; i<N; i++) {
			cin >> input;
			v.push_back(input);
		}

		sort(v.begin(), v.end());

		for (int i=0; i<N/4; i++) {
			ans += (v[N-1-i]-v[i]);
		}
		ans *= 2;

        cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
    }

	return 0;
}