#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int N, M, arr[10001];
	cin >> N;
	ll total = 0;
	ll low = 0;
	ll high = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i];
		high = arr[i] > high ? arr[i] : high;
	}
	cin >> M;
	if (total <= M) {
		cout << high << endl;
		return 0;
	}

	while (low <= high) {
		ll mid = (low + high) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] < mid) sum += arr[i];
			else sum += mid;
		}

		if (M - sum >= 0) low = mid + 1;
		else high = mid - 1;
	}

	cout << high << endl;
	return 0;
}