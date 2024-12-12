#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  auto lsItr = ls.begin();
  for (int i = 0 ; i < ls.size(); i++) {
    mSize += lsItr->size();
    if (lsItr->size() > 0) {
      lsItr->begin().ptr->prev = mHeader->prev;
      mHeader->prev->next = lsItr->begin().ptr;

      auto last = --lsItr->end();
      mHeader->prev = last.ptr;
      last.ptr->next = mHeader;
      lsItr->mSize = 0;

      lsItr->end().ptr->prev = lsItr->end().ptr;
      lsItr->end().ptr->next = lsItr->end().ptr;
    }
    lsItr++;
  }

}

#endif
