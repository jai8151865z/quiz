#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct ListNodeStruct {
    int value;
    struct ListNodeStruct *next;
} ListNode;


ListNode *head=NULL;
ListNode *tail=NULL;

ListNode *detectCycle(ListNode *head) {
         if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                slow = head;
                while(slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return NULL;
    }


int main()
{
    ListNode *answer;
    ListNode *c=NULL;
    for(int i=1;i<6;i++)
    {
      if(head==NULL)
      {
        head = (ListNode*) malloc(sizeof(ListNode));
        head->value=i;
        head->next=NULL;
        c=head;
        tail=head;
      }
      else 
      {
        c->next = (ListNode*) malloc(sizeof(ListNode));
        c->next->value=i;
        c->next->next=NULL;
        c=c->next;
        tail=c;
      }
    }
    tail->next = head->next;
    
    answer=detectCycle(head);
    if(answer!=NULL) {
        printf("Detected cycle at: %d\n",answer->value);
    } else {
        printf("Not found cycle\n");
    }

    return 0;
}