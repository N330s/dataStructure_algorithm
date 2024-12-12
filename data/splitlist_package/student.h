void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if(mSize == 0) return;
    int size2 = mSize / 2;
    int size1 = mSize - size2;
    node* n = mHeader->next;
    node* m = n;
    for (int i = 0; i < size1-1; i++) {
        m = m->next;
    }
    node *a = m->next;
    node *b = mHeader->prev;
    list1.mHeader->prev->next = n;
    n->prev = list1.mHeader->prev;
    m->next = list1.mHeader;
    list1.mHeader->prev = m;
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    list1.mSize += size1;
    mSize -= size1;
    if (mSize == 0) return;
    list2.mHeader->prev->next = a;
    a->prev = list2.mHeader->prev;
    b->next = list2.mHeader;
    list2.mHeader->prev = b;
    list2.mSize += size2;
    mSize = 0;
}
