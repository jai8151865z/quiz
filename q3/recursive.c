#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
            int val;
            struct TreeNode* left;
            struct TreeNode* right;
}TreeNode;

struct TreeNode*  flatten(TreeNode *root);
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
            printf("%d,",root->val);
            root = flatten(root);
}

TreeNode* flatten(TreeNode *root)
{
    if(root == NULL)
         return root;
    struct TreeNode* rightree = root->right;
    if(root->left != NULL)
    {
          root->right = root->left;
          root->left = NULL;
          printf("%d,",root->right->val);
          root = flatten(root->right);
     }
     if(rightree != NULL)
     {
          root->right = rightree;
          printf("%d,",root->right->val);
          root = flatten(root->right);
      }
      return root;
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