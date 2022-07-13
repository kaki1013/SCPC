#include <iostream>
#include <set>

using namespace std;

int par[100001];

int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void link(int x, int y) {
    par[find(y)] = find(x);
}

int main() {
	int T, test_case, N, i, D;
	set<int> s;

	cin >> T;
	for(test_case = 1; test_case  <= T; test_case++) {
	    cin >> N;
        for (i = 1; i <= N; i++) par[i] = i;
        
        for (i = 1; i <= N; i++) {
            cin >> D;
            if (i+D > N) continue;
            link(i, i+D);
        }
        
        s.clear();
        for (i = 1; i <= N; i++) s.insert(find(i));
        
		cout << "Case #" << test_case << "\n";
		cout << s.size() << "\n";
	}

	return 0;
}
