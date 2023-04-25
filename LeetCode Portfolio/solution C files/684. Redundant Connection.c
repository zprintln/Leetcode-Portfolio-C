/**
 * Note: The returned array must be malloced, assume caller calls free().

 */
// Function to find the root of the parent array
int findRoot(int node, int* parent) {
    while (node != parent[node]) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}
// Function to find redundant connection
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* parent = (int*)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int rootNode1 = findRoot(edges[i][0], parent);
        int rootNode2 = findRoot(edges[i][1], parent);
        if (rootNode1 == rootNode2) {
            *returnSize = 2;
            int* redundantEdges = (int*)malloc(*returnSize * sizeof(int));
            redundantEdges[0] = edges[i][0];
            redundantEdges[1] = edges[i][1];
            return redundantEdges;
        }
    parent[rootNode1] = rootNode2;
    }
    *returnSize = 0;
    return NULL;
}
