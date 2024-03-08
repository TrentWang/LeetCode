// https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/solutions/4814059/avl-tree-c/
struct Node {

    int key;
    int size; 
    Node* left;
    Node* right;

    Node(int k, int s = 1, Node* l = nullptr, Node* r = nullptr)
        : key(k), size(s), left(l), right(r) {}
};

class BalancedTree {
private:
    Node* root;

    void updateSize(Node* node) {
        if (node != nullptr) {
            node->size = getSize(node->left) + getSize(node->right) + 1;
        }
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        updateSize(x);
        updateSize(y);
        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        updateSize(y);
        updateSize(x);
        return x;
    }
    
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }

        updateSize(node);

        int balance = getSize(node->left) - getSize(node->right);
        if (balance > 1) {
            return rightRotate(node);
        } else if (balance < -1) {
            return leftRotate(node);
        }

        return node;
    }
    

    int greaterCount(Node* node, int key) {
        if (node == nullptr) {
            return 0;
        }

        if (key < node->key) {
            return getSize(node->right) + 1 + greaterCount(node->left, key);
        } else {
            return greaterCount(node->right, key);
        }
    }   
    
    int getSize(Node* node) {
        return (node != nullptr) ? node->size : 0;
    }

public:
    BalancedTree() : root(nullptr) {}
    
    void insert(int key) {
        root = insert(root, key);
    }

    int greatorCount(int key) {
        return greaterCount(root, key);
    }
    
    int getSize() {
        return getSize(root);
    }

};


// 客製化
// https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/solutions/4838855/tree-with-counters/
template<class T>
class TreeNodeWithCounter {
    T val;
    TreeNodeWithCounter *left = nullptr, *right = nullptr;
    int cnt_left = 0, cnt_right = 0, cnt_val = 1;
public:
    ~TreeNodeWithCounter() { 
        delete left; 
        delete right; 
    }

    TreeNodeWithCounter(T v) : val(v) {};
    
    void insert(T v, TreeNodeWithCounter **thisNode) {
        if (v == val) 
            ++cnt_val;
        else if (v < val) {
            ++cnt_left;
            if (left == nullptr)
                left = new TreeNodeWithCounter(v);
            else 
                left->insert(v, &left);
        }
        else {
            ++cnt_right;
            if (right == nullptr)
                right = new TreeNodeWithCounter(v);
            else
                right->insert(v, &right);
        }
        if (cnt_left > cnt_right + 2) { // right rotation
            *thisNode = left;
            left = left->right;
            (*thisNode)->right = this;
            this->cnt_left = (*thisNode)->cnt_right;
            (*thisNode)->cnt_right += this->cnt_val + this->cnt_right;
        }
        else if (cnt_left + 2 < cnt_right) { // left rotation
            *thisNode = right;
            right = right->left;
            (*thisNode)->left = this;
            this->cnt_right = (*thisNode)->cnt_left;
            (*thisNode)->cnt_left += this->cnt_val + this->cnt_left;
        }
    }
    
    int larger(T v) {
        if (v == val)
            return cnt_right;
        if (v < val) {
            return cnt_val + cnt_right + (left == nullptr ? 0 : left->larger(v));
        }
        return right == nullptr ? 0 : right->larger(v);
    }    
};
