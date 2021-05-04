#include <iostream>
using namespace std;

auto Line_multiplication = [] (auto m1, auto m2, int row, int column, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += m1[row][i]*m2[i][column];
    }
    return result;
};

auto Matrix_multiplication = [] (auto result, auto m1,auto m2, int size_1, int size_2, int size_3) {
    for (int row = 0; row < size_1; row++) {
        for (int column = 0; column < size_3; column++) {
            result[row][column] = Line_multiplication(m1, m2, row, column, size_2);
        }
    }
    return result;
};

int main() {
    int m1[2][3] = {{3,2,1},
                    {1,0,2}};
    int m2[3][2] = {{1,2},
                    {0,1},
                    {4,0}};
    int result[2][2] = {{0,0},{0,0}};

    Matrix_multiplication(result, m1, m2, 2, 3, 2);

    cout << "{" << result[0][0] << "," << result[0][1] << endl
            << result[1][0] << "," << result[1][1] << "}" << endl;

    return 0;
}
