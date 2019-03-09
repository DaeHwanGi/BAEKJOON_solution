#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int *arr = new int[N];
	int left = 0, right = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		right = arr[i] > right ? arr[i] : right;
	}

	while (left <= right) {
		int mid = (left + right) / 2;

		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) sum += arr[i] - mid;
		}
		if (sum < M) right = mid - 1;
		else left = mid + 1;
	}
	cout << right << endl;
	return 0;
}