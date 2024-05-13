/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

/**
 * @brief
 * 暴力法：
 * 1. vector 数组：
 * 2. 循环比较
 */

class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        std::vector<int> list;
        while (head) {
            list.push_back(head->val);
            head = head->next;
        }

        // 轮询判断是否为回型字符串
        int total_len = list.size();
        int index = 0;
        int tail_index = total_len - 1;
        while (index < total_len / 2) {
            if (list[index] != list[tail_index])
                return false;

            index++;
            tail_index--;
        }

        return true;
    }
};

int main(int argc, const char** argv)
{
    Solution test;

    // create a test chain
    ListNode* head = new ListNode;
    head->val = 1;
    ListNode* t1 = new ListNode;
    t1->val = 2;
    ListNode* t2 = new ListNode;
    t2->val = 1;
    ListNode* t3 = new ListNode;
    t3->val = 1;

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = nullptr;

    cout << "the result: " << test.isPalindrome(head) << endl;

    // release

    return 0;
}