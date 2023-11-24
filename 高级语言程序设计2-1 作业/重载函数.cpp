#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;

double round(double x) {
	return (int)(x + 0.5);
}

void OddFilter(int a[], int size) {
	list<int> b{};
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 1) {
			b.emplace_back(a[i]);
		}
	}
	if (b.size() == 0)
	{
		cout << "No Odd!" << endl;
		return;
	}
	b.sort();
	for (int& i : b)
	{
		cout << i << " ";
	}
	cout << endl;
}
void OddFilter(double a[], int size) {
	list<int> x{};
	list<int> b{};
	for (int i = 0; i < size; i++)
	{
		x.emplace_back((int)(round(a[i])));
	}
	for (int& i : x)
	{
		if (i % 2 == 1) {
			b.emplace_back(i);
		}
	}
	if (b.size() == 0)
	{
		cout << "No Odd!" << endl;
		return;
	}
	b.sort();
	for (int& i : b)
	{
		cout << i << " ";
	}
	cout << endl;
}
void OddFilter(char a[], int size) {
	list<char> origin(a, a + size);
	list<char> odd;
	while (!origin.empty())
	{
		char current = origin.front();
		int times = count(origin.begin(), origin.end(), current);
		if (times % 2 == 1)
		{
			odd.push_back(current);
		}
		origin.remove(current);
	}
	if (odd.empty())
	{
		cout << "No Odd!" << endl;
		return;
	}
	odd.sort();
	for (char& i : odd)
	{
		cout << i << " ";
	}
	cout << endl;

}
int main() {
	int M, N;
	cin >> M >> N;
	int Int[100];
	double Float[100];
	for (int i = 0; i < M; i++)
	{
		cin >> Int[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> Float[i];
	}

	const int maxLength = 100;
	char inputString[maxLength];

	// 输入字符串
	cin >> inputString;

	// 获取字符串长度
	size_t length = strlen(inputString);

	// 创建字符数组并复制每个字符
	char Char[maxLength]; // 假设数组大小不超过maxLength
	for (size_t i = 0; i < length && i < maxLength - 1; ++i) {
		Char[i] = inputString[i];
	}
	Char[length] = '\0'; // 添加字符串终止符
	OddFilter(Int, M);
	OddFilter(Float, N);
	OddFilter(Char, length);
}