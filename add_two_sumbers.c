#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int value, flag = 0, x = 0;
    struct ListNode* head = NULL;
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = NULL;
    while (l1 || l2 || || x)
    {
        if (l1)
            flag += l1->val;    
        if (l2)
            flag += l2->val;
        
        value = flag % 10;
        if (!head)
        {
            head = p1 = p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            p2->val = value;
            p2->next = NULL;
        } else {
            p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            p2->val = value;
            p2->next = NULL;
            p1->next = p2;
            p1 = p1->next;
        }
        if (flag > 9)
            flag = 1;
        else
            flag = 0;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        x = flag;
    }
    return head;
}

int main()
{
    struct ListNode* node_1_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node_1_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node_1_3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_1_1->val = 2;
    node_1_1->next = node_1_2;
    node_1_2->val = 4;
    node_1_2->next = node_1_3;
    node_1_3->val = 3;
    node_1_3->next = NULL;


    struct ListNode* node_2_1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node_2_2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node_2_3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_2_1->val = 5;
    node_2_1->next = node_2_2;
    node_2_2->val = 6;
    node_2_2->next = node_2_3;
    node_2_3->val = 4;
    node_2_3->next = NULL;

    struct ListNode* result = addTwoNumbers(node_1_1, node_2_1);
    free(node_1_1);
    free(node_1_2);
    free(node_1_3);
    free(node_2_1);
    free(node_2_2);
    free(node_2_3);
}
