#include <iostream>
using namespace std;

class Solution {
private:
	int N;
	int **arr;
	int ans[3];
public:
	Solution() {
		cin >> N;
		arr = new int*[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new int[N];
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 0;
	}
	int the_number_of_paper() {
		recursive(0, 0, N);
		cout << ans[0] << endl;
		cout << ans[1] << endl;
		cout << ans[2] << endl;

		return 0;
	}
	int recursive(int start_row, int start_col, int N) {
		int paper_type = arr[start_row][start_col];
		int current_type;
		bool same = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				current_type = arr[start_row + i][start_col + j];
				if (paper_type != current_type) {
					same = false;
					break;
				}
			}
			if (same == false)
				break;
		}
		if (same) {
			ans[paper_type + 1] += 1;
		}
		else if (N == 3) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					current_type = arr[start_row + i][start_col + j];
					ans[current_type + 1] += 1;
				}
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					recursive(start_row + i*(N / 3), start_col + j*(N / 3), N / 3);
				}
			}
		}
		return 0;
	}
	~Solution() {
		for (int i = 0; i < N; i++)
			delete[] arr[i];
		delete[] arr;
	}
};
int main() {
	Solution solution = Solution();
	solution.the_number_of_paper();
	return 0;
}