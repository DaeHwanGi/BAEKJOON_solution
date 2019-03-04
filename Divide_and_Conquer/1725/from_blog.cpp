#include <iostream>
using namespace std;

typedef long long ll;

inline ll min(ll a, ll b) { return a > b ? b : a; }
inline ll max(ll a, ll b) { return a < b ? b : a; }

class Solution {
public:
	int partial_array() {
		int N;
		cin >> N;
		ll *arr = new ll[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		ll ans = histogram(arr, 0, N);
		cout << ans << endl;
		return 0;
	}
	static ll histogram(ll *arr, int s, int e) {
		if (s == e) return 0;
		if (s + 1 == e) return arr[s];

		int mid = (s + e) / 2;
		ll result = max(histogram(arr, s, mid), histogram(arr, mid, e));

		int w = 1, l = mid, r = mid;
		ll h = arr[mid];
		while (r - l + 1 < e - s) {
			ll p = l>s ? min(h, arr[l - 1]) : -1;
			ll q = r<e - 1 ? min(h, arr[r + 1]) : -1;

			if (p >= q) {
				h = p;
				l--;
			}
			else {
				h = q;
				r++;
			}

			result = max(result, ++w*h);
		}
		return result;
	}
};
int main() {
	Solution solution = Solution();
	solution.partial_array();
	return 0;
}