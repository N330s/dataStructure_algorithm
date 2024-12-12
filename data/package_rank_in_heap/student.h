#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  short count = 0;
  for (short i = 0; i < mSize; i++) {
    if (mLess(mData[pos], mData[i])) count++; 
  }
  return count;
}

#endif
