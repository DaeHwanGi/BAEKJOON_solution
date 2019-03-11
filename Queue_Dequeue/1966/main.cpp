#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int test_case, arr[101];
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		int N, target, cnt = 0;
		queue<int> q;
		cin >> N >> target;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
			q.push(j);
		}
		while (!q.empty()) {
			int idx = q.front();
			int priority = arr[idx];
			bool first_print = true;
			for (int j = 0; j < N; j++) {
				if (arr[j] > priority) {
					first_print = false;
					break;
				}
			}
			if (first_print) {
				arr[idx] = -1;
				q.pop();
				cnt++;
				if (idx == target) {
					cout << cnt << endl;
					break;
				}
			}
			else {
				q.pop();
				q.push(idx);
			}
		}
	}
}