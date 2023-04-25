/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
0: not monitored and no camera installed
1: monitored but no camera installed
2: camera installed
*/
struct TreeNode* init_root;
int minCameras(struct TreeNode* node, int* cameras){
    if(node == NULL){
        return 1;
    }
    int left = minCameras(node->left, cameras);
    int right = minCameras(node->right, cameras);
    if(left == 0 || right == 0){
        (*cameras)++;
        return 2;
    }
    if(left == 1 && right == 1){
        if(node == init_root){
            (*cameras)++;
            return 2;
        }
        return 0;
    }
    return 1;
}
int minCameraCover(struct TreeNode* root){
    init_root = root;
    int cameras = 0;
    minCameras(root, &cameras);
    return cameras;
}

