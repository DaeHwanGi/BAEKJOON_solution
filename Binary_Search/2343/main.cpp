#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int N, M;
	int time[100000];
	cin >> N >> M;
	ll low = 0;
	ll high = 0;
	for (int i = 0; i < N; i++) {
		cin >> time[i];
		high += time[i];
		if (low < time[i]) low = time[i];
	}
	while (low <= high) {
		ll mid = (low + high) / 2;
		ll sum = 0;
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (sum + time[i] > mid) {
				count++;
				sum = 0;
			}
			sum += time[i];
		}
		if (sum != 0) count++;
		cout << low << "," << high << "," << mid << "," << count << endl;
		if (count > M) low = mid+1;
		else high = mid-1;
	}
	cout << low << endl;
	return 0;
}