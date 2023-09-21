ListNode* reverseList(ListNode* cur, ListNode* prev = nullptr) {
    while (cur != nullptr) {
        swap(cur->next, prev);
        swap(prev, cur);     
    }
    return prev;    
}
