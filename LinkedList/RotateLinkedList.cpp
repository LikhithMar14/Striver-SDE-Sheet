#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //lastnode
        if(!head || k==0 || !head->next)return head;
        ListNode* temp = head;
        int length = 1;
        while(temp && temp->next){
            temp = temp->next;
            length++;
        }
        ListNode*lastNode = temp;
        temp = head;

        int count  = length-k%length;
        if (count == length) return head;
        while(temp && --count)temp = temp->next;
        ListNode* nextNode = temp->next;
        temp->next = NULL;
        lastNode->next = head;
        head = nextNode;

        return head;


    }
};