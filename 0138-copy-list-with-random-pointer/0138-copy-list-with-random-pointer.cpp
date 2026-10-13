/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertinbetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node*copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
    }

    void connectrandom(Node* head){
        Node* temp  = head;
        while(temp!=NULL){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
            }else{
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* connectnext(Node* head){
        Node* dnode = new Node(-1);
        Node* temp = head;
        Node* res = dnode;
        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp ->next = temp->next->next;
            temp = temp->next;
        }
        return dnode->next;
    }

    Node* copyRandomList(Node* head) {
        insertinbetween(head);
        connectrandom(head);
        return connectnext(head);        
    }
};