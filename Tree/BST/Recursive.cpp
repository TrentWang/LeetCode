#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
};

/* 根 → 左 → 右 */
void pre_order(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    ret.push_back(root->val);          // 1. 訪問根
    pre_order(root->left,  ret);       // 2. 左子樹
    pre_order(root->right, ret);       // 3. 右子樹
}

/* 左 → 根 → 右   （對二元搜尋樹可得到遞增序列）*/
void in_order(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    in_order(root->left,  ret);        // 1. 左子樹
    ret.push_back(root->val);          // 2. 訪問根
    in_order(root->right, ret);        // 3. 右子樹
}

/* 左 → 右 → 根 */
void post_order(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    post_order(root->left,  ret);      // 1. 左子樹
    post_order(root->right, ret);      // 2. 右子樹
    ret.push_back(root->val);          // 3. 訪問根
}