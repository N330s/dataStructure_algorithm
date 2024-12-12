#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if (!n) return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if (!mRoot) return std::pair<KeyT,MappedT>();

  delete_all_nodes(left.mRoot);
  left.mRoot = mRoot->left;
  left.mSize = process(mRoot->left);
  mRoot->left = nullptr;
  if (left.mRoot) left.mRoot->parent = nullptr;

  delete_all_nodes(right.mRoot); 
  right.mRoot = mRoot->right;
  right.mSize = process(mRoot->right);
  mRoot->right = nullptr;
  if (right.mRoot) right.mRoot->parent = nullptr;
  mSize = 1;
  return mRoot->data;
}

#endif

