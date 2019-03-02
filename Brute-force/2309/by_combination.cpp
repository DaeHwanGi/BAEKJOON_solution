#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int dwarf() {
		int num_dwarf = 9;
		int num_real = 7;
		vector<int> v(num_dwarf);

		for (int i = 0; i<num_dwarf; i++) {
			cin >> v[i];
		}

		vector<int> idx;
		for (int i = 0; i < num_real; i++)
			idx.push_back(1);
		for (int i = 0; i < num_dwarf - num_real; i++)
			idx.push_back(0);

		sort(v.begin(), v.end());
		sort(idx.begin(), idx.end());

		do {
			int sum = 0;
			for (int i = 0; i<num_dwarf; i++) {
				if (idx[i]) sum += v[i];
			}
			if (sum == 100) {
				for (int i = 0; i<num_dwarf; i++) {
					if (idx[i]) cout << v[i] << endl;
				}
			}

		} while (next_permutation(idx.begin(), idx.end()));
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.dwarf();
	return 0;
}