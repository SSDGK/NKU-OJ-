#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	string target[20][20];
	int num[20];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> target[i][0];
		cin >> target[i][1];
		cin >> num[i];
	}
	for (int i = 0; i < N; i++)
	{
		int len = target[i][0].size();
		while (num[i] > len)
		{
			num[i] -= len;
		}
		if (target[i][1] == "L")
		{
			string a = target[i][0].substr(0, num[i]);
			target[i][0].erase(0, num[i]);
			target[i][0].append(a);
		}
		else if (target[i][1] == "R")
		{
			string b = target[i][0].substr(0, len - num[i]);
			target[i][0].erase(0, len - num[i]);
			target[i][0].append(b);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < target[i][0].size(); j += 2) {
			string c = target[i][0];
			cout << c[j];
		}
		cout << endl;
	}
}