#include "rb_iterator.h"
#include "rb_tree.h"

#include <string>

using libmap::rb_tree::Tree;

TEST_CASE("Basic Iterator test", "") {
  Tree<int> test_tree;
  test_tree.Insert(0);
  test_tree.Insert(1);
  test_tree.Insert(2);
  test_tree.Insert(3);
  test_tree.Insert(4);
  test_tree.Insert(5);

  int counter = 0;
  for (int i : test_tree) {
    CHECK(i == counter);
    counter++;
  }
}
