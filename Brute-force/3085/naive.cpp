#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int change_with_down(char **arr, int row, int col) {
	char temp = arr[row][col];
	arr[row][col] = arr[row + 1][col];
	arr[row + 1][col] = temp;
	return 0;
}
int change_with_right(char **arr, int row, int col) {
	char temp = arr[row][col];
	arr[row][col] = arr[row][col+1];
	arr[row][col+1] = temp;
	return 0;
}
int find_max_in_row(char **arr, int N, int row) {
	vector<char> v;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!v.empty()) {
			if (v.back() != arr[row][i]) {
				v.clear();
				v.push_back(arr[row][i]);
			}
			else {
				v.push_back(arr[row][i]);
			}
		}
		else {
			v.push_back(arr[row][i]);
		}
		ret = ret > v.size() ? ret : v.size();
	}
	return ret;
}
int find_max_in_col(char **arr, int N, int col) {
	vector<char> v;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!v.empty()) {
			if (v.back() != arr[i][col]) {
				v.clear();
				v.push_back(arr[i][col]);
			}
			else {
				v.push_back(arr[i][col]);
			}
		}
		else {
			v.push_back(arr[i][col]);
		}
		ret = ret < v.size() ? v.size() : ret;
	}
	return ret;
}
int check(char **arr, int N) {
	int ans = 1;
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				cnt++;
			}
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (arr[j][i] == arr[j - 1][i]) {
				cnt++;
			}
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}
int print_arr(char **arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
int main() {
	int N;
	cin >> N;

	char **arr = new char*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new char[N];
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int a, b, c, d, answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << "ij " << i << " " << j << endl;
			if (i != N - 1) {
				change_with_down(arr, i, j);
				//print_arr(arr, N);
				a = check(arr, N);
				change_with_down(arr, i, j);
			}
			if (j != N - 1) {
				change_with_right(arr, i, j);
				//print_arr(arr, N);
				b = check(arr, N);
				change_with_right(arr, i, j);
			}
			answer = std::max({ answer, a, b });
			//cout << a << " " << b << " " << c << " " << d << endl;
		}
	}
	cout << answer << endl;
	return 0;
}