#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rLL(ListNode* temp) {
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        while (temp && --k) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp) {
            ListNode* kthNode = getKthNode(temp, k);
            if (!kthNode) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL; 

            ListNode* reversedHead = rLL(temp);

            if (temp == head) {
                head = reversedHead;
            } else {
                prevLast->next = reversedHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
