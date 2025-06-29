#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //Observation
        //we cannot perfrom all ops generally because we donty have addr3ss of the ahdd

        int tempVal = node->next->val;
        node->val = tempVal;
        ListNode* tempNode = node->next;
        node->next = node->next->next;
        tempNode->next = NULL;
        delete tempNode;
    }
};