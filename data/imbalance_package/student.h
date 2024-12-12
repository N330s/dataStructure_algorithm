// Your code here

int getBalance(node* n, KeyT& ans, int& max) {
    if (!n) return -1;
    int hl = getBalance(n->left, ans, max);
    int hr = getBalance(n->right, ans, max);
    int height = 1 + ((hl > hr) ? hl : hr);
    int balance = ((hl-hr > 0) ? (hl - hr) : (hr-hl));
    if (balance > max) {
        max = balance;
        ans = n->data.first;
    }
    else if (balance == max && ans > n->data.first) {
        ans = n->data.first;
    }
    return height;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int max = -1;
    KeyT ans = mRoot->data.first;

    getBalance(mRoot, ans, max);
    return ans;
}
