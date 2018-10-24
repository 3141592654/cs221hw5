/*
 * Tests tree.cc.
 */

#include <assert.h>
#include <iostream>
#include "tree.hh"

int main() {
  std::cout << "INITIALIZING..." << std::endl;
  tree_ptr_t lrl = create_tree(9, 8);
  tree_ptr_t lr = create_tree(6, 5, lrl);
  tree_ptr_t ll = create_tree(12, 11);
  tree_ptr_t l = create_tree(-5, -6, ll, lr);
  tree_ptr_t rl = create_tree(3, 2);
  tree_ptr_t r = create_tree(12, 11, rl);
  // and to use some different functionality
  tree_ptr_t root = create_tree(126, 125);
  root->left_ = l;
  root->right_ = r;

  std::cout << "RUNNING BASIC TESTS" << std::endl;
  assert(root->key_ == 126);
  assert(root->value_ == 125);
  assert(root->left_->right_->key_ == 6);
  assert(root->right_->left_->right_ == nullptr);

  std::cout << "RUNNING PATH_TO TESTS" << std::endl;
  assert(path_to(root, 126) == "");
  assert(path_to(root, -5) == "L");
  assert(path_to(root, 12) == "LL");
  assert(path_to(root, 6) == "LR");
  assert(path_to(root, 9) == "LRL");
  assert(path_to(root, 3) == "RL");
  assert(path_to(l, 12) == "L");
  // as per spec, if you run the following lines, the program will crash.
  // std::cout << "searching for 3 starting at -5 (shouldn't find): "
  // << path_to(l, 3);

  std::cout << "RUNNING NODE_AT TESTS" << std::endl;
  assert(node_at(root, "")->key_ == 126);
  assert(node_at(root, "L")->key_ == -5);
  assert(node_at(root, "LL")->key_ == 12);
  assert(node_at(root, "LR")->key_ == 6);
  assert(node_at(root, "LRL")->key_ == 9);
  assert(node_at(root, "R")->key_ == 12);
  assert(node_at(root, "RL")->key_ == 3);
  assert(node_at(root, "RRRR") == nullptr);
  assert(node_at(root, "quick_brown_fox") == nullptr);

  std::cout << "RUNNING DELETION TEST (CHECK VALGRIND)" << std::endl;
  destroy_tree(root);
  return 0;
}
