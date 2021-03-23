#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool isPalindrome(string& s, int begin, int end) {
	if (begin + 1 >= end)
		return true;

	while (s[begin] == ' ' && begin < end)
		++begin;
	while (s[end - 1] == ' ' && end > begin)
		--end;

	if (begin + 1 >= end)
		return true;

	if (tolower(s[begin]) != tolower(s[end - 1]))
		return false;
	else
		return isPalindrome(s, begin + 1, end - 1);
}

void quickSort(int* arr, int left, int right) {
	if (left + 1 >= right)
		return;

	int lIdx = left;
	int rIdx = right - 1;
	int pivot = arr[left];

	while (lIdx < rIdx) {
		while (lIdx < rIdx && arr[lIdx] <= pivot) ++lIdx;
		while (rIdx > lIdx && arr[rIdx] > pivot) --rIdx;
		if (lIdx < rIdx) {
			int temp = arr[lIdx];
			arr[lIdx] = arr[rIdx];
			arr[rIdx] = temp;
		}
	}

	int pivotIdx = lIdx;
	//PrintArr(arr + left, right - left);
	if (lIdx > left && arr[lIdx] > pivot) {
		pivotIdx = lIdx - 1;
	}
	//cout << "Left: " << left << " " << right << " " << lIdx << " " << rIdx << " " << pivotIdx << endl;
	arr[left] = arr[pivotIdx];
	arr[pivotIdx] = pivot;
	quickSort(arr, left, pivotIdx);
	quickSort(arr, pivotIdx + 1, right);
}

void printArr(int* arr, int len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void reverseString(string& s, int begin, int end) {
	if (begin + 1 >= end)
		return;

	char c = s[begin];
	s[begin] = s[end - 1];
	s[end - 1] = c;
	reverseString(s, begin + 1, end - 1);
}

int main() {
	srand(static_cast<int>(time(nullptr)));

	string s;
	s = "radar";
	cout << s << " is palindrome? " << (isPalindrome(s, 0, s.size()) ? "yes" : "no") << endl;
	s = "A nut for a jar of tuna";
	cout << s << " is palindrome? " << (isPalindrome(s, 0, s.size()) ? "yes" : "no") << endl;
	s = "taco cat";
	cout << s << " is palindrome? " << (isPalindrome(s, 0, s.size()) ? "yes" : "no") << endl;
	s = "apple";
	cout << s << " is palindrome? " << (isPalindrome(s, 0, s.size()) ? "yes" : "no") << endl;
	cout << endl;

	int arr[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = rand() % 100;
	}
	cout << "Before quick sort" << endl;
	printArr(arr, 10);
	cout << "After quick sort" << endl;
	quickSort(arr, 0, 10);
	printArr(arr, 10);
	cout << endl;

	s = "hello world!";
	cout << "Before reverse: " << s << endl;
	reverseString(s, 0, s.size());
	cout << "After reverse: " << s << endl;
	int  a ;
	cout << "plz select : 1,Palindrome. 2,Quicksort. 3,Reverse String. 4.Exit.  "<< endl;
		cin >> a ;
	if (a==1)
	{
		cout << "Palindrome: type words :" << endl;
		cin >> s;
		cout << s << " is palindrome? " << (isPalindrome(s, 0, s.size()) ? "yes" : "no") << endl;
	}
	if(a==2)
	{
		cout << "Quicksort: type number :" << endl;
		cin >> arr[10];
		cout << "Before quick sort" << endl;
		printArr(arr, 10);
		cout << "After quick sort" << endl;
		quickSort(arr, 0, 10);
		printArr(arr, 10);
		cout << endl;
		
	}
	if (a == 3)
	{
		cout << "Reverse String: type words :" << endl;
		cin >> s;
		cout << "Before reverse: " << s << endl;
		reverseString(s, 0, s.size());
		cout << "After reverse: " << s << endl;
	}
	if (a == 4)
	{
		return 0;
	}
}