#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> answers(temperatures.size(),0);
        stack<int> index;
        
        for (int i = 0; i < temperatures.size(); i++) 
        {
            while (!index.empty() && temperatures[i] > temperatures[index.top()])
            {
                answers[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
            
        }

        // int i = 0, j = 0;
        // for (i = 0; i < temperatures.size(); i++) {
        //     int next_day = 0;
        //     for (j = i + 1; j < temperatures.size(); j++) {
        //         if (temperatures[i] < temperatures[j]) {
        //             next_day = j - i;
        //             break;
        //         }
        //     }

        //     answers.push_back(next_day);
        // }

        return answers;
    }
};

int main(int argc, char const* argv[])
{
    vector<int> temperatures = { 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 };
    Solution sln;
    vector<int> nums = sln.dailyTemperatures(temperatures);

    vector<int>::iterator it = nums.begin();

    while (it != nums.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;

    return 0;
}
