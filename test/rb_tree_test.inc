#include "rb_tree.h"

TEST_CASE("Tree Insertion", "") {
  auto tree = Tree<int>();
  tree.Insert(1);
  REQUIRE(tree.Contains(1) == true);
}
