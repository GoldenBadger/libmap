#ifndef LIBMAP_INCLUDE_RB_TREE_H_
#define LIBMAP_INCLUDE_RB_TREE_H_

#include "rb_node.h"

template <typename T>
class Tree {
 public:
  void Insert(T data) {
    root = Insert(root, data);
    root->colour = BLACK;
  }

  bool Contains(T data) const { return Contains(root, data); }

  static Node<T>* RotateLeft(Node<T>* node) {
    auto* pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;
    pivot->colour = node->colour;
    node->colour = RED;
    return pivot;
  }

  static Node<T>* RotateRight(Node<T>* node) {
    auto* pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;
    pivot->colour = node->colour;
    node->colour = RED;
    return pivot;
  }

  static void FlipColours(Node<T>* node) {
    node->colour = RED;
    node->left->colour = BLACK;
    node->right->colour = BLACK;
  }

 private:
  Node<T>* Insert(Node<T>* node, T data) {
    if (node == nullptr) return new Node<T>(data);

    int compare = (node->data < data);
    if (compare < 0) {
      node->left = Insert(node->left, data);
    } else if (compare > 0) {
      node->right = Insert(node->right, data);
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

  Node<T>* root;
};

#endif
