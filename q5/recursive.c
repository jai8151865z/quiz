#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct ListNodeStruct {
    int value;
    struct ListNodeStruct *next;
} ListNode;

ListNode *head=NULL;
ListNode *tail=NULL;

ListNode *first( ListNode *slow, ListNode *fast )
{
	if( fast == NULL || fast->next == NULL )
		return NULL;
	if( slow != fast )
		return first( slow->next, fast->next->next );
	return fast;
}

ListNode *second( ListNode *slow, ListNode *fast )
{
	if( slow == fast )
		return slow;
	return second( slow->next, fast->next );
}

ListNode *detectCycle( ListNode *head )
{
	ListNode* slow = head;
	ListNode* fast = head; 
	
	fast = first( slow->next, fast->next->next );
	slow = head;
	if( fast != NULL )
		return second( slow, fast );
	return fast;
}


int main()
{
    ListNode *answer;
    ListNode *c=NULL;
    for(int i=1;i<=6;i++)
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