#ifndef LIBMAP_INCLUDE_RB_TREE_H_
#define LIBMAP_INCLUDE_RB_TREE_H_

#include "rb_node.h"
#include "rb_iterator.h"

namespace libmap {
namespace rb_tree {

template <typename T>
class Tree {
 public:
  ~Tree() { delete root_; }

  void Insert(T data) {
    root_ = Insert(root_, data, nullptr);
    root_->colour = BLACK;
  }

  bool Contains(T data) const { return Contains(root_, data); }

  Iterator<T> begin() const {
    auto iter_node = root_;
    while (iter_node->left) iter_node = iter_node->left;
    return Iterator<T>(iter_node);
  }

  Iterator<T> end() { return nullptr; }

 private:
  Node<T>* Insert(Node<T>* node, T data, Node<T>* parent) {
    if (node == nullptr) return new Node<T>(data, parent);

    int compare = (node->data < data);
    if (compare < 0) {
      node->left = Insert(node->left, data, node);
    } else if (compare > 0) {
      node->right = Insert(node->right, data, node);
    } else {
      node->data = data;
    }

    if (IsRed(node->right) && !IsRed(node->left)) {
      node = RotateLeft(node);
    }
    if (IsRed(node->left) && IsRed(node->left->left)) {
      node = RotateRight(node);
    }
    if (IsRed(node->left) && IsRed(node->right)) {
      FlipColours(node);
    }

    return node;
  }

  bool Contains(Node<T>* node, T data) const {
    if (node == nullptr) return false;

    if (data == node->data) return true;
    if (data < node->data) return Contains(node->left, data);
    // if data > node->data
    return Contains(node->right, data);
  }

  bool IsRed(Node<T>* node) {
    if (node == nullptr) return false;
    return node->colour == RED;
  }

  // Makes sure that node's children know it is their parent.
  static void MakeParent(Node<T>* node) {
    if (node->left) node->left->parent = node;
    if (node->right) node->right->parent = node;
  }

  static Node<T>* RotateRight(Node<T>* node) {
    auto* pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;
    pivot->colour = node->colour;
    node->colour = RED;
    MakeParent(node);
    MakeParent(pivot);
    return pivot;
  }

  static Node<T>* RotateLeft(Node<T>* node) {
    auto* pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;
    pivot->colour = node->colour;
    node->colour = RED;
    MakeParent(node);
    MakeParent(pivot);
    return pivot;
  }

  static void FlipColours(Node<T>* node) {
    node->colour = RED;
    node->left->colour = BLACK;
    node->right->colour = BLACK;
  }

  Node<T>* root_ = nullptr;
};

}  // namespace rb_tree
}  // namespace libmap

#endif
