#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
};

/* ---------- 1. Pre-order：根 → 左 → 右 ---------- */
void pre_order(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* cur = st.top(); st.pop();
        ret.push_back(cur->val);          // 訪問根
        if (cur->right) st.push(cur->right); // 先右後左 ⇒ 左子樹會先被處理
        if (cur->left)  st.push(cur->left);
    }
}

/* ---------- 2. In-order：左 → 根 → 右 ---------- */
void in_order(TreeNode* root, vector<int>& ret) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        // 先一路走到最左
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top(); st.pop();         // 彈出最左（或中途）節點
        ret.push_back(cur->val);          // 訪問根
        cur = cur->right;                 // 轉向右子樹
    }
}

/* ---------- 3. Post-order：左 → 右 → 根 ---------- */
/* 方法：單 stack + 前一次訪問指標 prev */
void post_order(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    stack<TreeNode*> st;
    TreeNode* cur  = root;
    TreeNode* prev = nullptr;             // 上一次輸出的節點

    while (cur || !st.empty()) {
        // 跟 in-order 類似，先走到最左
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();                   // 檢查棧頂

        // 若右子樹不存在，或剛剛處理完右子樹 ⇒ 可以輸出 cur
        if (!cur->right || cur->right == prev) {
            ret.push_back(cur->val);      // 訪問根
            st.pop();
            prev = cur;                   // 標記已處理
            cur = nullptr;                // 繼續檢查棧頂
        } else {
            // 還沒走右子樹，先去右子樹
            cur = cur->right;
        }
    }
}

/* Pre-order 改成 根 → 右 → 左
   最後再 reverse 就會變成 左 → 右 → 根  */
void post_order(TreeNode* root, vector<int>& ret) {
    if (!root) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* cur = st.top(); st.pop();
        ret.push_back(cur->val);         // 暫以 根→右→左 儲存

        if (cur->left)  st.push(cur->left);   // 注意：先 push 左
        if (cur->right) st.push(cur->right);  // 再 push 右
        /* 為什麼先左後右？
           因為 stack 後進先出，彈出順序就變成 根→右→左 */
    }
    reverse(ret.begin(), ret.end());          // 轉成 左→右→根
}