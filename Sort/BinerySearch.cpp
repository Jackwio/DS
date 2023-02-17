#include <iostream>
using namespace std;

bool binerySearch(int* num, int size , int goal);
void Print(int* num, int size);

int main() {

	int* num, n , goal;
	cin >> n;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> goal;
	bool result = binerySearch(num, n,goal);
	if (result) {
		Print(num, n);
	}
	else {
		cout << "Not Found!!";
	}
	return 0;
}

bool binerySearch(int* num, int size, int goal) {

	int left = 0;
	int right = size - 1;
	int mid;
	bool found = false;

	while (left <= right && !found ) {

		mid = (left + right) / 2;
		if (num[mid] > goal) {
			right = mid-1;
		}
		else if (num[mid] < goal) {
			left = mid + 1;
		}
		else {
			found = true;
		}
	}
	return found;
}

void Print(int* num, int size) {
	for (int i = 0; i < size; i++) {
		cout << num[i] << " ";
	}
}