#include "rb_node.h"

#include <string>

using libmap::rb_tree::Node;

TEST_CASE("Node construction", "") {
  Node<int> n = Node<int>(1);
  REQUIRE(n.data == 1);

  Node<std::string> n1("test");
  REQUIRE(n1.data == "test");
}
