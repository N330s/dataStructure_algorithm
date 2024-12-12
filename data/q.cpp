#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	// write your code here
	ensureCapacity (mSize + m);
    if (p < mSize / 2) {
        size_t j = mSize + m - 1;
        for (size_t i = mSize - 1; i >= p; i--) {
            mData[(mFront + j) % mCap] = mData[(mFront + i) % mCap];
            j--;
        }
        for (size_t i = p; i < p + m; i++) {
            mData[(mFront + i) % mCap] = element;
        }
    }
    else {
        int j = -m; 
        for (size_t i = 0; i < p; i++) {
            mData[(mFront + j + mCap) % mCap] = mData[(mFront + i) % mCap];
            j++;
        } 
        mFront = (mFront - m + mCap) % mCap;
        for (int i = p; i < p + m; i++) {
            mData[(mFront + i) % mCap] = elem;
        }
    }
	mSize += m;
}

#endif
