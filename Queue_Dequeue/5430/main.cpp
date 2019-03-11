#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr[100001];
vector<string> split(const string &s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int num, start, end, op_size;
		string op, str;
		bool start_front = true;
		bool error_occur = false;
		cin >> op >> num >> str;

		if(str.size()-2 == 0) str = "";
		else str = str.substr(1, str.size() - 2);
		vector<string> v = split(str, ',');
		for (int i = 0; i < v.size(); i++) arr[i] = stoi(v[i]);

		start = 0; end = v.size() - 1;
		op_size = op.size();
		for (int i = 0; i < op_size; i++) {
			if (op.at(i) == 'R') {
				start_front = !start_front;
			}
			else { // D
				if (start > end) {
					error_occur = true;
					cout << "error" << endl;
					break;
				}
				else {
					if (start_front) start++;
					else end--;
				}
			}
		}
		if (!error_occur) {
			if (start_front) {
				cout << "[";
				for (int i = start; i <= end; i++) {
					cout << arr[i];
					if (i != end) cout << ",";
				}
				cout << "]" << endl;
			}
			else {
				cout << "[";
				for (int i = end; i >= start; i--) {
					cout << arr[i];
					if (i != start) cout << ",";
				}
				cout << "]" << endl;
			}
		}
	}
	return 0;
}