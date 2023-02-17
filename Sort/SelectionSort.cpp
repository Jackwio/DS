#include <iostream>
#include <algorithm> //swap
using namespace std;

void selectionSort (int* const num, const int size);
void Print(const int* num, const int size);

int main() {
	int n, * num;
	cin >> n;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	selectionSort(num,n);
	Print(num, n);
	return 0;
}

//每次都把最小的和前面為排序的交換
void selectionSort(int* const num, const int size) {

	int smallest = 0;
	for (int i = 0; i < size; i++) {
		smallest = i;
		for (int j = i + 1; j < size; j++) {
			if (num[smallest] > num[j]) {
				smallest = j;
			}
		}
		swap(num[i], num[smallest]);
	}
}

void Print(const int* num, const int size) {
	for (int i = 0; i < size; i++) {
		cout << num[i] << "  ";
	}
}