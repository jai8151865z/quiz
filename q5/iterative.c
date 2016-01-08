#include <stdio.h>
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


void list()
{
    FILE *fp=fopen("testdata","r");
    char buf[256];
    char *sbuf;
    int tmp;
    ListNode *cnode=NULL;

    fgets(buf,256,fp);
    sbuf=strtok(buf, " ");

    while(sbuf!=NULL) {
        tmp=atoi(sbuf);
        sbuf=strtok(NULL, " ");

        if(head==NULL) {
            head=malloc(sizeof(ListNode));
            head->value=tmp;
            head->next=NULL;
            cnode=head;
            tail=head;
        } else {
            cnode->next=malloc(sizeof(ListNode));
            cnode->next->value=tmp;
            cnode->next->next=NULL;
            cnode=cnode->next;
            tail=cnode;
        }
    }
    fgets(buf,256,fp);
    tmp=atoi(buf);
    cnode=head;
    while(cnode!=NULL && cnode!=tail) {
        if(cnode->value==tmp) {
            tail->next=cnode;
            break;
        } else {
            cnode=cnode->next;
        }
    }
}

int main()
{
    ListNode *answer;
    list();
    //printlist();
    answer=detectCycle(head);
    if(answer!=NULL) {
        printf("Detected cycle at: %d\n",answer->value);
    } else {
        printf("Not found cycle\n");
    }
    return 0;
}