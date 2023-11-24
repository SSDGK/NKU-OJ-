#include <iostream>
using namespace std;
int judge(int n);
int main() {
    int N;
    int M[10000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }
    if (N <= 0 || N > 10000)
    {
        cout << "INCORRECT INPUT!" << endl;
    }
    for (int i = 0; i < N; i++) {
        if (M[i] >= 1000000 || M[i] <= 0)
        {
            cout << "INCORRECT INPUT!" << endl;
        }
        else
        {
            if (judge(M[i]) == 1)
            {
                cout << M[i] << " " << "0" << endl;
            }
            else if (judge(M[i]) == 2)
            {
                cout << M[i] << " " << "0" << endl;
            }
            else if (judge(M[i]) == -1)
            {
                cout << 2 << " " << "1" << endl;
            }
            else
            {
                int a = 0;
                int b = M[i];
                while (judge(b) != 1) {
                    b++;
                    a++;
                }
                int c = 0;
                int d = M[i];
                while (judge(d) != 1) {
                    d--;
                    c++;
                }
                if (a > c)
                {
                    cout << d << " " << c << endl;
                }
                else if (a < c)
                {
                    cout << b << " " << a << endl;
                }
                else if (a == c)
                {
                    cout << d << " " << c << endl;
                }
            }
        }
    }
}
int judge(int n) {
    int flag = 1;
    if (n == 1)
    {
        flag = -1;
    }
    if (n == 2)
    {
        flag = 2;
    }
    if (n > 2)
    {
        for (int i = 3; i < n; i++)
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}