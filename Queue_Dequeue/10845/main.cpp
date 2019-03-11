#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int N;
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;
		if (op == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (op == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (op == "size") cout << q.size() << endl;
		else if (op == "empty") cout << q.empty() << endl;
		else if (op == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else if (op == "back") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
	return 0;
}