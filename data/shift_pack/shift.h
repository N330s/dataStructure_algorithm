void shift(int k) {
	// TODO: Add your code here
	int n = (k + mSize * 1000) % mSize;
	auto it = mHeader->next;
	for (int i = 0; i < n; i ++) {
		it = it->next;
	}
	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;
	it->prev->next = mHeader;
	mHeader->next = it;
	mHeader->prev = it->prev;
	it->prev = mHeader;
}
