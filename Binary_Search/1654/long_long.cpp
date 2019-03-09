#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int K, N;
	cin >> K >> N;
	int *length = new int[K];
	int max_length = 0;
	for (int i = 0; i < K; i++) {
		cin >> length[i];
		max_length = length[i] > max_length ? length[i] : max_length;
	}
	int left = 1, right = max_length;
	while (left <= right) {
		int mid = (left + right) / 2;
		int count = 0;
		for (int i = 0; i < K; i++) {
			int tmp_length = length[i];
			int tmp_count = 0;
			while (tmp_length - mid >= 0) {
				tmp_length -= mid;
				tmp_count++;
			}
			count += tmp_count;
		}
		if (count < N) right = mid - 1;
		else left = mid + 1;
	}
	cout << right << endl;
	return 0;
}