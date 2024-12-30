/*
Ax+By=N (A > B)
max(x+y) = ?
-> maximize y == minimize x, but x >= 0
x or y can be 0
*/

#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

tuple<int, int, int> gcd(int a, int b) {
    // ax+by=g, (a, b) = (b, a%b)
    if (b==0) return {1, 0, a};
    int x, y, g;
    tie(x, y, g) = gcd(b, a%b);
    return {y, x-(a/b)*y, g};
}

int Answer;

int main(int argc, char** argv) {
	int T, N, A, B;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> A >> B;
        tie(A, B) = make_tuple(max(A, B), min(A, B));
        
        int x, y, g;
        tie(x, y, g) = gcd(A, B);
        x *= (N/g); y *= (N/g);
        if (x > 0) {
            while (x > 0) {
                x -= (B/g);
                y += (A/g);
            }
        }
        if (x < 0) {
            while (x < 0) {
                x += (B/g);
                y -= (A/g);
            }
        }
        
		cout << "Case #" << test_case << '\n';
		cout << x+y << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}