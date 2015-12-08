#ifndef LIBMAP_INCLUDE_RB_NODE_H_
#define LIBMAP_INCLUDE_RB_NODE_H_

enum Colour { RED, BLACK };

template <typename T>
struct Node {
  Node(T data) : data(data) {}

  T data;
  Colour colour;  // Colour of link between node and parent
  Node<T>* left;
  Node<T>* right;
};

#endif
