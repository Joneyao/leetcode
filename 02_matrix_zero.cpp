#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * @brief
 * 解法1：
 * 1. 轮询所有行和列
 * 2. 记录包含0所在的行和列的坐标
 * 3. 最后根据坐标设置满足要求的行和列（设置过程中，需要判断对应的行或者列是否已经被设置为0）
 * 使用set 记录，可以直接去掉重复的数字
 */

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> x_list;
        set<int> y_list;

        // 轮询找出0的坐标
        int x = 0;
        int y = 0;
        for (x = 0; x < matrix.size(); x++)
        {
            for (y = 0; y < matrix[0].size(); y++)
            {
                if (matrix[x][y] == 0)
                {
                    x_list.insert(x);
                    y_list.insert(y);
                }
            }
        }

        // 再次轮询，设置所在行和列为0
        // 将所在行设置为0
        set<int>::iterator it = x_list.begin();
        while (it != x_list.end())
        {

            for (y = 0; y < matrix[0].size(); y++)
            {
                matrix[*it][y] = 0;
            }
            it++;
        }

        it = y_list.begin();
        while (it != y_list.end())

        {
            for (x = 0; x < matrix.size(); x++)
            {
                matrix[x][*it] = 0;
            }
            it++;
        }
    }
};

void print_vector(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main(int argc, const char **argv)
{
    vector<vector<int>> test_case = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    print_vector(test_case);

    Solution test_obj;
    test_obj.setZeroes(test_case);

    cout << "------------------------" << endl;

    print_vector(test_case);

    return 0;
}