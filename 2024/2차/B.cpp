/*
w1 < w2 <.. < wn 이라고 하면
1 : w1
2 : w2
...
n : wn
...
(w1-1)*n + 1 : w1 (삭제)
...
w1 + (w2-1)*(n-1) + 1 : w2 (삭제)
...
w1 + w2 + (w3-1)*(n-2) + 1 : w3(삭제)
...

각각의 위치를 이분탐색으로 찾고
offset 만큼을 반복하는 동안은 원소가 삭제되지 않음을 이용
*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
        int N, Q;
        ll ans = 0;
		cin >> N >> Q;

        vector<ll> W;
        for (int i = 0; i < N; i++) {
            cin >> W[i];
        }

        vector<ll> pp;  // pre_process

        int arr[300000];

        ll x;
        for (int i = 0; i < Q; i++) {
            cin >> x;
        }



        cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
    }

	return 0;
}