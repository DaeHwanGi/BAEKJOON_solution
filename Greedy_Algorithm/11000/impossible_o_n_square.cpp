#include <iostream>
#include <vector>
#include <queue>
#include<functional>
#include <algorithm>

using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

class Solution {
public:
	int meetingroom_alloc() {
		int N;
		cin >> N;
		pair<int, int> *p = new pair<int, int>[N];
		for (int i = 0; i < N; i++)
			cin >> p[i].first >> p[i].second;

		sort(&p[0], &p[N], compare);

		for (int i = 0; i < N; i++)
			cout << p[i].first << "," << p[i].second << endl;
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < N; i++) {
			int start = p[i].first, end = p[i].second;
			if (!pq.empty()) {
				if (pq.top() > start) {
					pq.push(end);
				}
				else {
					pq.pop();
					pq.push(end);
				}
			}
			else {
				pq.push(end);
			}
		}

		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.meetingroom_alloc();
	return 0;
}