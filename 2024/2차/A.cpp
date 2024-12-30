/*
가능한 경우
0
1
01
10
010
 */
#include <bits/stdc++.h>

using namespace std;

int arr[400001];
int ones[400000];
vector<int> v;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
        long long ans = 9223372036854775807, S, E;
		cin >> N >> S >> E;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        arr[N] = -1;

        // make length list
        v.clear();
        int last = arr[0], length = 1;
        for (int i = 1; i <= N; i++) {
            if (arr[i] == last) {
                length++;
            }
            else {
                last = arr[i];
                v.push_back(length);
                length = 1;
            }
        }

        // no side zeroes is needed
        if (arr[0] == 0) {
            v.erase(v.begin());
        }
        if (arr[N-1] == 0) {
            if (v.size() != 0)
                v.pop_back();
        }
        // v : empty / starts and ends with 1
        
        if (v.size() > 2) {  // 1 0 [10]* 1
            //0
            // never -> 010 is better
            
            //1
            int zero = 0;
            for (int i = 1; i < v.size(); i+=2) {
                zero += v[i];
            }
            ans = min(ans, S * zero);

            // 전처리
            // ones[i] := i번째 까지 1의 개수의 합, zeros[i] := i번째 까지 0의 개수의 합 : 메모리 초과 -> 하나만 사용
            ones[0] = v[0];
            for (int i = 1; i < v.size(); i++) {
                if (i%2==1) {
                    ones[i] = ones[i-1];
                }
                else {
                    ones[i] = ones[i-1] + v[i];
                }
            }
            // 누적합 (= ones + zeros 임을 이용)
            for (int i = 1; i < v.size(); i++) {
                v[i] = v[i-1] + v[i];
            }
            
            //01
            //ex. 1010101 -> (101010)(1)/(10101)(01)/(1010)(101)/(101)(0101)/(10)(10101)/(1)(010101)
            long long tmp;
            for (int i = 0; i < v.size()-1; i++) {
                // E : 1->0, S : 0->1 
                tmp = E * (ones[i]) + S * ((v[v.size()-1] - ones[v.size()-1]) - (v[i] - ones[i]));  // (zeros[v.size()-1] - zeros[i])
                ans = min(ans, tmp);
                // cout << 111 << ans << ' ' << tmp << endl;
            }
            
            //10
            for (int i = 0; i < v.size()-1; i++) {
                tmp = S * (v[i] - ones[i]) + E * (ones[v.size()-1] - ones[i]);  // S : 0->1, E : 1->0 
                ans = min(ans, tmp);
                // cout << 222 << ans << ' ' << tmp << endl;
            }

            //010 : make all ones zero, except largest ones
            int one = 0, largest = -1;
            for (int i = 0; i < v.size(); i+=2) {
                one += v[i];
                largest = max(largest, v[i]);
            }
            ans = min(ans, E * (one-largest));
        }

        else {
            ans = 0;
        }

        cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
    }

	return 0;
}