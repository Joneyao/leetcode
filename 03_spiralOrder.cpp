#include <iostream>
#include <set>
#include <vector>

using namespace std;

/**
 * @brief
 * 解法1：
 * 1. 设置一个行结束索引和列结束索引
 * 2. 每输出一行结束后，列索引 - 1
 * 3. 输出一列结束后，行索引 - 1
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int cnt = 0; // 0: 正行，1：正列，2：反行，3：反列
        int x = 0, y = 0;
        int is_first = 1;
        int x_start_index = 0, x_end_index = matrix.size(), y_start_index = 0, y_end_index = matrix[0].size();
        int total_num = matrix.size() * matrix[0].size();
        vector<int> ret;

        for (int i = 0; i < total_num; i++) {
            // 输出 正行
            if (cnt == 0) {
                x = x_start_index;
                if (is_first) {
                    y = y_start_index;
                    is_first = 0;
                }

                ret.push_back(matrix[x][y]);
                y++;
                if (y == y_end_index) {
                    cnt++;
                    y_end_index--;
                    is_first = 1;
                }
            }

            // 输出 正列
            else if (cnt == 1) {
                if (is_first) {
                    x = x_start_index + 1;
                    is_first = 0;
                }

                y = y_end_index;
                ret.push_back(matrix[x][y]);
                x++;
                if (x == x_end_index) {
                    cnt++;
                    x_end_index--;
                    is_first = 1;
                }
            }

            // 输出 反行
            else if (cnt == 2) {
                x = x_end_index;
                if (is_first) {
                    y = y_end_index - 1;
                    is_first = 0;
                }

                ret.push_back(matrix[x][y]);

                if (y == y_start_index) {
                    cnt++;
                    x_start_index++;
                    is_first = 1;
                }
                y--;
            }

            // 输出 反列
            else if (cnt == 3) {
                if (is_first) {
                    x = x_end_index - 1;
                    is_first = 0;
                }
                y = y_start_index;
                ret.push_back(matrix[x][y]);
                if (x == x_start_index) {
                    cnt = 0;
                    y_start_index++;
                    is_first = 1;
                }
                x--;
            }
        }
        return ret;
    }
};

void print_vector(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main(int argc, const char** argv)
{
    vector<vector<int>> test_case = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

    print_vector(test_case);

    Solution test_obj;

    test_obj.spiralOrder(test_case);

    return 0;
}
