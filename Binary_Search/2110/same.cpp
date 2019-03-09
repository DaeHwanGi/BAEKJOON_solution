#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int N, C;
	cin >> N >> C;
	int *pos = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}
	sort(pos, pos + N);
	ll left = 1, right = 1000000000;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int count = 1;
		int start = pos[0];
		for (int i = 1; i < N; i++) {
			if (pos[i] - start >= mid) {
				count++;
				start = pos[i];
			}
		}
		if (count >= C) left = mid + 1;
		else right = mid - 1;
	}
	cout << right << endl;
	return 0;
}