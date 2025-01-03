#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    if (!n) return 0;
    int l = my_recur(n->left, aux);
    int r = my_recur(n->right, aux);
    aux = (l+r > aux) ? l+r : aux;
    return std::max(l, r) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
    int aux = 0;
    if (mSize == 0) return -1;
    if (mSize == 1) return 0;
    my_recur (mRoot, aux);
    return aux;
}

#endif
