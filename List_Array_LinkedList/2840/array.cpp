#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	char *arr = new char[N];
	for (int i = 0; i < N; i++) arr[i] = '?';
	int pos = 0;
	while (K--) {
		int move;
		char c;
		cin >> move >> c;

		if (pos - move < 0)
			pos = N + pos - move;
		else
			pos = pos - move;
		
		if (arr[pos] != '?' && arr[pos] != c){
			cout << "!" << endl;
			return 0;
		}
		arr[pos] = c;
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (arr[i] != '?' && arr[i] == arr[j]){
				cout << "!" << endl;
				return 0;
			}

	for (int i = 0; i < N; i++)
		cout << arr[(i + pos) % N];

	cout << "\n";
	return 0;
}