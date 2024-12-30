#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int target) {	// left idx
	int l = 1, r = v.size()-1;
	if (target < v[l]) return 0;
	if (target >= v[r]) return r;
	while (l < r) {
		int m = (l+r)/2;
		if (target == v[m]) return m;
		else if (target < v[m]) {
			r = m-1;
		}
		else if (target > v[m]) {
			l = m+1;
		}
	}
	if ((v[l-1] < target) && (target < v[l])) return l-1;
	else if ((v[l] < target) && (target < v[l+1])) return l;
	else return l+1;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, D, ans = 0;
		cin >> N >> D;
		vector<int> pos, neg;

        for (int i=0; i<N; i++) {
			int temp;
			cin >> temp;
			if ((temp > 0) && (temp <= D)) pos.push_back(temp);
			else if (temp == 0) ans += 1;
			else if ((temp < 0) && (-temp <= D)) neg.push_back(-temp);
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());

		vector<int> sum_pos_e = {0}, sum_pos_count = {0}, sum_neg_e = {0}, sum_neg_count = {0};
		for (int i=0; i<pos.size(); i++) {
			if (sum_pos_e[sum_pos_e.size()-1] != pos[i]) {
				sum_pos_e.push_back(pos[i]);
				sum_pos_count.push_back(sum_pos_count[sum_pos_count.size()-1] + 1);
			}
			else {
				sum_pos_count[sum_pos_count.size()-1] += 1;
			}
		}

		for (int i=0; i<neg.size(); i++) {
			if (sum_neg_e[sum_neg_e.size()-1] != neg[i]) {
				sum_neg_e.push_back(neg[i]);
				sum_neg_count.push_back(sum_neg_count[sum_neg_count.size()-1] + 1);
			}
			else {
				sum_neg_count[sum_neg_count.size()-1] += 1;
			}
		}


		for (int i=0; i<sum_pos_e.size(); i++) {
			int idx = binary_search(sum_neg_e, D-2*sum_pos_e[i]);
			ans = max(ans, sum_pos_count[i] + sum_neg_count[idx]);
		}

		cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
	}

	return 0;
}