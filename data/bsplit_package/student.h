#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node *n = mRoot, *old = mRoot;
  while (n) {
    if (n->data.first < val) {
      n = n->right;
    }
    else {
      result.mRoot = n;
      old = n;
      if (n->parent) {
        n->parent->right = nullptr;
      }
      break;
    }
  }
  
  return result;
}

#endif
