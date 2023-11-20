#include <iostream>
#include <list>
using namespace std;
int main() {
	int M, N;
	int a[100], b[100];
	cin >> M >> N;
	for (int i = 0; i < M; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	list<int> x(a, a + M);
	list<int> y(b, b + N);
	for (int& i : y)
	{
		x.emplace_back(i);
	}
	x.sort();
	x.unique();
	for (int& i : x)
	{
		cout << i << " ";
	}
}