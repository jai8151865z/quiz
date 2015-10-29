#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
            int val;
            struct TreeNode* left;
            struct TreeNode* right;
}TreeNode;

void  flatten(TreeNode *root);
struct TreeNode* createNode(TreeNode* parent, int index, int position);

int LEFT = 0;
int RIGHT = 0;

int main()
{
            struct TreeNode* root = createNode( NULL, 1, -1 );
            struct TreeNode* root_left_child  = createNode( root, 2, 0 );
            struct TreeNode* root_right_child = createNode( root, 5, 1 );
            createNode( root_left_child,  3, 0 );
            createNode( root_left_child,  4, 1 );
            createNode( root_right_child, 6, 1 );
            flatten(root);
}

void flatten(TreeNode *root)
{
    struct TreeNode* cur = root;
    while(cur != NULL)
    {
         printf("%d,",cur->val);
         if(cur->left != NULL)
         {
                if(cur->right != NULL)
                {
                      struct TreeNode* next = cur->left;
                      while(next->right != NULL)
                             next = next->right;
                      next->right = cur->right;
                 }
                 cur->right = cur->left;
                 cur->left = NULL;
          }
          cur = cur->right;
     }
}

TreeNode* createNode(TreeNode* parent, int index, int position) {
            struct TreeNode* child = malloc(sizeof(TreeNode));
            child->val = index;
            child->left = NULL;
            child->right = NULL;
            if(parent != NULL){
                    if(position == LEFT)
                            parent->left = child;
                    else 
                            parent->right = child;
            }
            return child;
    }