/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void printlist(RandomListNode *head){
        while(head){
            cout<<head->label<<"->";
            head=head->next;
        }
        cout<<endl;
    }
    RandomListNode *newnode(int data){
        RandomListNode *n=(RandomListNode *)malloc(sizeof(RandomListNode));
        n->label=data;
        n->next=n->random=NULL;
        return n;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        // use a map to store the newlist and old list relationship
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode *org=head,*cl=NULL;
        if(head==NULL){
            return NULL;
        }
        while(org){
            cl=newnode(org->label);
            m[org]=cl;
            org=org->next;
        }
        org=head;
        RandomListNode *ans=m.find(org)->second;
        while(org){
            cl=m.find(org)->second;
            if(org->next==NULL){
                cl->next=NULL;
            }
            else{
                cl->next=m.find(org->next)->second;
            }
            if(org->random==NULL){
                cl->random=NULL;
            }
            else{
                cl->random=m.find(org->random)->second;
            }
            org=org->next;
        }
        return ans;

    }
};
