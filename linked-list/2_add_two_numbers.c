#include<stdlib.h>
struct ListNode* createNode(int value){
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=value;
        newNode->next=NULL;
        return newNode;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next=NULL;
    struct ListNode* tail=&dummy;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=carry;
        if(l1){
            sum=sum+l1->val;
            l1=l1->next;
        }
        if(l2){
            sum=sum+l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        tail->next=createNode(sum%10);
        tail=tail->next;
    }
    return dummy.next;
}
