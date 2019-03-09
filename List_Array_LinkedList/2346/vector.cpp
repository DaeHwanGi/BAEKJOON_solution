#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<pair<int,int>> v;

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		v.push_back(make_pair(i, temp));
	}

	while (v.size()) {
		pair<int, int> front = v.front();
		cout << front.first << " ";
		v.erase(v.begin());
		if (v.size() == 0) {
			break;
		}
		if (front.second < 0) {
			for (int i = 0; i < -front.second; i++) {
				pair<int, int> temp = v.back();
				v.pop_back();
				v.insert(v.begin(), temp);
			}
		}
		else {
			for (int i = 1; i < front.second; i++) {
				pair<int, int> temp = v.front();
				v.erase(v.begin());
				v.push_back(temp);
			}
		}

		for (int i = 0; i < v.size(); i++) cout << v[i].first << ",";
		cout << endl;
	}
	return 0;
}