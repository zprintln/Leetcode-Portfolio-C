//Zadie Moon
//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

// Computes the sum of all node values in the tree
unsigned long long int computeTotalSum(struct TreeNode* node){
    if(node == NULL){
        return 0;
    }
    return node->val + computeTotalSum(node->left) + computeTotalSum(node->right);
}

// Recursively computes the sum of nodes in each subtree, 
// finds the maximum product of two non-overlapping subtrees
// and updates the value of a pointer to the maximum product seen so far.
// Returns the sum of nodes in the subtree rooted at the current node.
unsigned long long int computeSubSum(struct TreeNode* node, unsigned long long int* maxProduct, unsigned long long int totalSum){
    if(node == NULL){
        return 0;
    }
    unsigned long long int subTree = node->val;
    subTree += computeSubSum(node->left, maxProduct, totalSum);
    subTree += computeSubSum(node->right, maxProduct, totalSum);

    unsigned long long int otherSubTree = totalSum - subTree;

    unsigned long long int product = subTree * otherSubTree;

    if(product > *maxProduct){
        *maxProduct = product;
    }
    return subTree;
}
// Computes the maximum product of two non-overlapping subtrees in the binary tree
unsigned long long int maxProduct(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    unsigned long long int totalSum = computeTotalSum(root);
    unsigned long long int maxProduct = 0;
    computeSubSum(root, &maxProduct, totalSum);
    return maxProduct % 1000000007;

}
