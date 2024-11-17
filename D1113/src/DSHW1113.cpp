#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


// 自訂型態二分搜尋
template <typename T>
int binaryS(T* arr, int right, int left, T key) {
	if (right < left) return -1;
	int mid = (left + right) / 2;
	if (key > *(arr + mid)) return binaryS(arr, right, mid + 1, key);
	else if (key < *(arr + mid)) return binaryS(arr, mid - 1, left, key);
	else return mid;
}


template <typename T>
void inputm(, int n, int q) {
	T* arr = new T[n];
	T input;
	//陣列列讀入
	for (int i = 0; i < n; i++)
		cin >> *(arr + i);
	sort(arr, arr + n - 1);
	//搜尋值讀入
	for (int i = 0; i < q; i++) {
		cin >> input;
		int result = binaryS(arr, n - 1, 0, input);//搜尋結果列印
		cout << result << endl;
	}
}

int main(void) {
	char type;
	int n, q;
	while (cin >> type >> n >> q) {//判斷是否有值
		if (type == 'i') inputm<int>(n, q);
		if (type == 's') inputm<string>(n, q);
		cout << endl;
	}
}