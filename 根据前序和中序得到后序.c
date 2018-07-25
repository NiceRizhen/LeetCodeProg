/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* traverse(int *pre, int prestart, int preend, int *in, int instart, int inend)
{
    if(prestart>preend||instart>inend) return NULL;
    
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = pre[prestart];
    node->left = NULL;
    node->right = NULL;
    
    int i;
    for(i = instart; i<=inend; i++)
    {
        if(in[i]==pre[prestart])
        {
        	//pre:从开始后一个到开始后(i - instart)这一段 
        	//in : 从开始到i前一个这一段 
            node->left = traverse(pre, prestart+1, prestart+i-instart,in, instart, i-1); 
            
            // pre: 从开始后(i-instart)的下一个到结束
			// in: 从i+1个到结束 
            node->right = traverse(pre, prestart+i-instart+1, preend, in ,i+1, inend);  //
            break;
        }
    }
    return node;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 
{
    struct TreeNode *tree;
    tree = traverse(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
    
    return tree;
}

