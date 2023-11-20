#include <iostream>
#include <vector>

using namespace std;

// 蛇形输出
void snakeOutput(const vector<vector<int>>& matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            // 正序输出
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
        }
        else {
            // 倒序输出
            for (int j = n - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
    }
}

// 回转输出
void spiralOutput(const vector<vector<int>>& matrix, int m, int n) {
    int rowStart = 0, rowEnd = m - 1;
    int colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // 向右
        for (int i = colStart; i <= colEnd; i++) {
            cout << matrix[rowStart][i] << " ";
        }
        rowStart++;

        // 向下
        for (int i = rowStart; i <= rowEnd; i++) {
            cout << matrix[i][colEnd] << " ";
        }
        colEnd--;

        // 向左
        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                cout << matrix[rowEnd][i] << " ";
            }
            rowEnd--;
        }

        // 向上
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