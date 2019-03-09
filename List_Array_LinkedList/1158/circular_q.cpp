#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node {
	struct Node* prev;
	struct Node* next;
	int data;
}Node;
int main() {
	int M, N;
	cin >> N >> M;
	Node *root = NULL;
	for (int i = 1; i <= N; i++) {
		Node *pN = new Node;
		pN->data = i;
		if (root == NULL) {
			pN->prev = pN;
			pN->next = pN;
			root = pN;
		}
		else {
			pN->prev = root->prev;
			pN->next = root;
			root->prev->next = pN;
			root->prev = pN;
		}
	}
	Node *pN = root;
	Node *next;
	cout << "<";
	while (pN != NULL) {
		for (int i = 0; i < M - 1; i++)
			pN = pN->next;
		cout << pN->data;
		if (pN->next == pN) {
			delete pN;
			pN = NULL;
		}
		else {
			cout << ", ";
			pN->prev->next = pN->next;
			pN->next->prev = pN->prev;
			next = pN->next;
			delete pN;
			pN = next;
		}
	}
	cout << ">";
}