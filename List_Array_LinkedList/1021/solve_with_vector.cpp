#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int N, M, target, count=0;
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; i++) v.push_back(i);

	
	while(M--) {
		cin >> target;
		if (target == v.front()) {
			v.erase(v.begin());
			N--;
			continue;
		}

		bool start_from_front = false;
		for (int i = 0; i < N; i++) {
			if (v[N - 1 - i] == target) {
				start_from_front = false;
				break;
			}
			if (v[i + 1] == target) {
				start_from_front = true;
				break;
			}
		}
		if (start_from_front) {
			while (v.front() != target) {
				int temp = v.front();
				v.erase(v.begin());
				v.push_back(temp);
				count++;
			}
			v.erase(v.begin());
		}
		else {
			while (v.front() != target) {
				int temp = v.back();
				v.pop_back();
				v.insert(v.begin(), temp);
				count++;
			}
			v.erase(v.begin());
		}
		N--;
	}
	cout << count << endl;
	return 0;
}