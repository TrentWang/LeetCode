// 98. Validate Binary Search Tree
bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    function<bool(TreeNode*)> validate = [&](TreeNode* node) {
        if (node == NULL)
            return true;
        if (!validate(node->left)) 
            return false;
        if (prev != NULL && prev->val >= node->val) 
            return false;
        prev = node;
        return validate(node->right);
    };
    return validate(root);
}
