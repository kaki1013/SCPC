#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, v1, v2;
        long long ans = 0, m = 0, n = 0;

        vector <vector <int>> adj(300001, vector<int>(0));
		cin >> N;

        for (int i=0; i<N+1; i++) {
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        int s = -1, e = -1;
        for (int i=1; i<=N; i++) {
            if (adj[i].size() == 3) {
                if (s == -1) s = i;
                else e = i;
            }
        }
        
        vector<int> vst(300001, 0);
        int curr = s;
        vst[curr] = 1;

        // determine direction
        for (auto node: adj[curr]) {
            if (node == e) continue;  // no matter which direction, except for 's-e'
            curr = node;
            vst[curr] = 1;
            m++;
            break;
        }

        while (curr != e) {
            // determine nxt
            for (auto node: adj[curr]) {
                if (vst[node] == 1) continue;  // no matter which direction, except for 's-e'
                curr = node;
                vst[curr] = 1;
                m++;
            }
        }
        m--; // e

        n = N - m - 2;
        ans  = m*(m+1)/2 + n*(n+1)/2;

        cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
    }

	return 0;
}