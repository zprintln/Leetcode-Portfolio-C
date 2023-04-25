/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int goodNodeCounter(struct TreeNode* node, int count, int maxNode){
    if(node == NULL){
        return count;
    }
    if(node->val >= maxNode){
        count++;
        maxNode = node->val;
    }
    count = goodNodeCounter(node->left, count, maxNode);
    count = goodNodeCounter(node->right, count, maxNode);
    return count;
}

int goodNodes(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    int maxNode = root->val;
    count = goodNodeCounter(root, count, maxNode);
    return count;
}