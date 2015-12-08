#ifndef LIBMAP_INCLUDE_RB_NODE_H_
#define LIBMAP_INCLUDE_RB_NODE_H_

enum Colour { RED, BLACK };

template <typename T>
class Node {
 public:
  Node(T data) : data_(data) {}

  T data() const { return data_; }
  bool IsRed() const { return colour_ == RED; }

 private:
  Colour colour_;  // Colour of link between node and parent
  T data_;
  Node<T>* left;
  Node<T>* right;
};

#endif
