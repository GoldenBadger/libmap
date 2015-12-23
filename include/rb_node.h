#ifndef LIBMAP_INCLUDE_RB_NODE_H_
#define LIBMAP_INCLUDE_RB_NODE_H_

namespace libmap {
namespace rb_tree {

enum Colour { RED, BLACK };

template <typename T>
struct Node {
  Node(T data) : data(data) {}
  Node(T data, Node<T>* parent) : data(data), parent(parent) {}

  ~Node() {
    delete left;
    delete right;
  }

  T data;
  Colour colour = BLACK;  // Colour of link between node and parent
  Node<T>* parent = nullptr;
  Node<T>* left = nullptr;
  Node<T>* right = nullptr;
};

}  // namespace rb_tree
}  // namespace libmap

#endif
