void replace(const T& x, list<T>& y) {
  //write your code here
  auto it = begin();
  while (it != end()) {
    if (it.ptr->data == x) {
      for (auto i : y) {
        insert(it, i);
      }
      it = erase(it);
    }
    else {
      it++;
    }
  }
}
