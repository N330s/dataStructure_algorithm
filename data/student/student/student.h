#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  std::sort(pos.begin(), pos.end());
  size_t newSize = mSize - pos.size();
  T* temp = new T[newSize * 2];
  size_t j = 0;
  size_t k = 0;
  for (size_t i = 0; i < mSize; i++) {
    if (j < pos.size()) {
      if (pos[j] == i) {
        j++;
        continue;
      }
    }
    temp[k] = mData[(mFront + i) % mCap];
    k++;
  }
  delete[] mData;
  mData = temp;
  mSize = newSize;
  mCap = newSize * 2;
  mFront = 0;
}

#endif
