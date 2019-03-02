#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int dwarf() {
		int arr[9];
		int fake[2];
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		sort(arr, arr + 9);
		for (int i = 0; i < 8; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (sum - arr[i] - arr[j] == 100) {
					fake[0] = i;
					fake[1] = j;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			if (i != fake[0] && i != fake[1]) cout << arr[i] << endl;
		}
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.dwarf();
	return 0;
}