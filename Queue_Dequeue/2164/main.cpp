#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int N;
	queue<int> q;
	cin >> N;
	for (int i = 1; i <= N; i++) q.push(i);

	while (q.size() > 1) {
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}
	cout << q.front() << endl;
	return 0;
}