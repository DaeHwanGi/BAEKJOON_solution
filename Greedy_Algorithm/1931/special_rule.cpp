#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
class Solution {
public:
	int meetingroom_alloc() {
		int N;
		int cnt = 0;
		int last_use = -1;
		cin >> N;
		pair<int, int> *p = new pair<int, int>[N];
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			p[i] = make_pair(a, b);
		}
		sort(&p[0], &p[N], compare);
		for (int i = 0; i < N; i++) {
			if (p[i].first >= last_use) {
				cnt++;
				last_use = p[i].second;
			}
		}
		cout << cnt << endl;
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.meetingroom_alloc();
	return 0;
}