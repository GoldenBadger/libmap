#ifndef LIBMAP_INCLUDE_RB_ITERATOR_H_
#define LIBMAP_INCLUDE_RB_ITERATOR_H_

#include "rb_node.h"

namespace libmap {
namespace rb_tree {

template <typename T>
class Iterator {
 public:
  Iterator() = delete;
  Iterator(Node<T>* node) : node_(node) {}
  Iterator(const Iterator<T>& other) : node_(other.node_) {}

  T& operator*() const { return node_->data; }

  bool operator==(const Iterator<T>& other) const {
    return node_ == other.node_;
  }

  bool operator!=(const Iterator<T>& other) const { return !operator==(other); }

  Iterator<T>& operator++() {
    Increment();
    return *this;
  }

 private:
  void Increment() {
    if (node_->right != nullptr) {
      node_ = node_->right;
      while (node_->left != nullptr) {
        node_ = node_->left;
      }
    } else {
      auto parent = node_->parent;
      while (parent && node_ == parent->right) {
        node_ = parent;
        parent = node_->parent;
      }
      if (node_->right != parent) {
        node_ = parent;
      }
    }
  }

  Node<T>* node_;
};

}  // namespace rb_tree
}  // namespace libmap

#endif
