#include <iostream>
#include <string>
using namespace std;
void exchange(float sco[], int n, string num[], string name[]);
void equal(int n, float sco[], string name[], string num[]);

int main() {
    int N, Type;
    string num[100], name[100];
    float math[100], chinese[100], english[100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        cin >> name[i];
        cin >> math[i];
        cin >> chinese[i];
        cin >> english[i];
    }
    cin >> Type;
    if (Type == 1) {
        exchange(math, N, num, name);
        equal(N, math, name, num);
    }
    else if (Type == 2) {
        exchange(chinese, N, num, name);
        equal(N, chinese, name, num);
    }
    else if (Type == 3) {
        exchange(english, N, num, name);
        equal(N, english, name, num);
    }
    else {
        cout << "ERROR" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        cout << num[i] << " " << name[i] << endl;
    }
}

void exchange(float sco[], int n, string num[], string name[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sco[i] < sco[j])
            {
                float t1 = sco[i];
                sco[i] = sco[j];
                sco[j] = t1;
                string t2 = num[i];
                num[i] = num[j];
                num[j] = t2;
                string t3 = name[i];
                name[i] = name[j];
                name[j] = t3;
            }
        }
    }
}

void equal(int n, float sco[], string name[], string num[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sco[i] == sco[j] && num[i] > num[j])
            {
                string t1 = name[i];
                name[i] = name[j];
                name[j] = t1;
                string t2 = num[i];
                num[i] = num[j];
                num[j] = t2;
            }
        }
    }
}