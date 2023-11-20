#include <iostream>
#include <vector>

using namespace std;

// �������
void snakeOutput(const vector<vector<int>>& matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            // �������
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
        }
        else {
            // �������
            for (int j = n - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
    }
}

// ��ת���
void spiralOutput(const vector<vector<int>>& matrix, int m, int n) {
    int rowStart = 0, rowEnd = m - 1;
    int colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // ����
        for (int i = colStart; i <= colEnd; i++) {
            cout << matrix[rowStart][i] << " ";
        }
        rowStart++;

        // ����
        for (int i = rowStart; i <= rowEnd; i++) {
            cout << matrix[i][colEnd] << " ";
        }
        colEnd--;

        // ����
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                cout << matrix[rowEnd][i] << " ";
            }
            rowEnd--;
        }

        // ����
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                cout << matrix[i][colStart] << " ";
            }
            colStart++;
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    snakeOutput(matrix, m, n);
    cout << endl;
    spiralOutput(matrix, m, n);
    cout << endl;

    return 0;
}