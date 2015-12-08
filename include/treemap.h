#ifndef LIBMAP_INCLUDE_TREEMAP_H_
#define LIBMAP_INCLUDE_TREEMAP_H_

class TreeMap {
 public:
  TreeMap(int dummy_val) : dummy_val_(dummy_val) {}

  int dummy_val() const;

 private:
  int dummy_val_;
};

#endif  // LIBMAP_INCLUDE_TREEMAP_H_
