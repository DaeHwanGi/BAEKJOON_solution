#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	int N;
	string str;
	float value[26];
	stack<float> s;
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < str.size(); i++){
		if (str.at(i) == '+') {
			float b = s.top();
			s.pop();
			float a = s.top();
			s.pop();
			s.push(a + b);
		}
		else if (str.at(i) == '-') {
			float b = s.top();
			s.pop();
			float a = s.top();
			s.pop();
			s.push(a - b);
		}
		else if (str.at(i) == '/') {
			float b = s.top();
			s.pop();
			float a = s.top();
			s.pop();
			s.push(a / b);
		}
		else if (str.at(i) == '*') {
			float b = s.top();
			s.pop();
			float a = s.top();
			s.pop();
			s.push(a * b);
		}
		else {
			s.push(value[str.at(i)-65]);
		}
	}
	printf("%.2lf", s.top());
	return 0;
}