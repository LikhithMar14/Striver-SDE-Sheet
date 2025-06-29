/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
};

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp = head;


    while (temp && temp->data == k) {
        Node* prevTemp = temp;
        temp = temp->next;
        delete prevTemp;
    }

    if(!temp)return NULL;
    temp->prev = NULL;

    head = temp;
    Node* curr = head;


    while(curr){
        if(curr->data == k){
            Node* prevNode = curr->prev;
            Node* currNode = curr->next;
            prevNode->next = currNode;
            if (currNode) currNode->prev = prevNode;
            curr->prev = NULL;
            curr->next = NULL;
            Node*tempNode = curr;
            delete tempNode;

            curr  = currNode;

        }else{
            
            curr = curr->next;
        }


    }
    return head;

}
