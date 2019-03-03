#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int repairman() {
		int N, L;
		cin >> N >> L;
		int *arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		vector<int> v;
		for (int i = 0; i < N; i++) {
			if (!v.empty()) {
				if (arr[i] - v.back() > L - 1) {
					v.push_back(arr[i]);
				}
			}
			else {
				v.push_back(arr[i]);
			}
			cout << v.back() << endl;
		}
		cout << v.size() << endl;
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.repairman();
	return 0;
}