/*
 * Implementation of tree.hh.
 */

#include <assert.h>
#include "tree.hh"

// implementation of create_tree
tree_ptr_t create_tree(const key_t& key, const value_t& value,
                          tree_ptr_t left, tree_ptr_t right) {
  tree_ptr_t retval = new Tree{key, value, left, right};
  return retval;
}

// implementation of destroy_tree
void destroy_tree(tree_ptr_t tree) {
  // could leave out the != nullptr if you wanted.
  if (tree->left_ != nullptr) {
    destroy_tree(tree->left_);
  }
  if (tree->right_ != nullptr) {
    destroy_tree(tree->right_);
  }
  delete tree;
}

// helper function. returns true if the key has been found
// at this node or any of its children. constructs the path
// to the relevant node in the following way. traverse through
// the tree until you find the key. once you do, tell the parent
// node about this. the parent node knows if this was to its left
// or its right, so it prepends the relevant letter. then it
// returns to its own parent node.

bool value_found(const tree_ptr_t tree, std::string* result, const key_t key) {
  if (tree == nullptr) {
    return false;
  }
  if (tree->key_ == key) {
    return true;
  }
  // check if the key was found somewhere to the left of this parent node.
  // if so, make a note of it and return to the parent node.
  if (value_found(tree->left_, result, key)) {
    (*result).insert(0, 1, 'L');
    return true;
  }
  // check if key was found to right of this parent node.
  if (value_found(tree->right_, result, key)) {
    (*result).insert(0, 1, 'R');
    return true;
  }
  // if the code has gotten to this point, then this node
  // doesn't have the key, and neither do its children, so
  return false;
}

// implementation of path_to
std::string path_to(tree_ptr_t tree, key_t key) {
  std::string result("");
  assert(value_found(tree, &result, key));
  return result;
}

// implementation of node_at
tree_ptr_t node_at(tree_ptr_t tree, std::string path) {
  if (tree == nullptr) {
    return tree;
  }
  // pretty standard stuff, just go down the path
  // and store the result node in tree
  std::string::iterator it = path.begin();
  for (; it != path.end(); ++it) {
    if (*it == 'L') {
      if (tree->left_ == nullptr) {
        return nullptr;
      }
      tree = tree->left_;
    } else {
      if (*it == 'R') {
        if (tree->right_ == nullptr) {
          return nullptr;
        }
        tree = tree->right_;
      } else {
        return nullptr;
      }
    }
  }
  return tree;
}

