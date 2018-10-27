#include <iostream>
#include <cassert>

struct LNode {
  int data_;
  LNode* next_;
};

//////////////////////////////////////////////////////////////////////////////
void print_list(const LNode* head) {
  while (head) {
    std::cout << head->data_ << " ";
    head = head->next_;
  }
  std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////
// Reverse a list iteratively
// You can pass a node that is not the head. If you do, it will become the
// tail of the returned list. It will also be the tail of the old list.
// So you now have two lists.
LNode* reverse_list(LNode* head) {
  LNode* previous = nullptr;
  LNode* current = head;
  LNode* temp;
  // go through all the nodes in the list, make them point to their predecessor
  while (current != nullptr) {
    temp = current->next_;
    current->next_ = previous;
    previous = current;
    current = temp;
  }
  return previous;
}


//////////////////////////////////////////////////////////////////////////////
// Reverse a list recursively
LNode* reverse_list_r(LNode* head) {
  LNode* next = head->next_;
  LNode* result;
  if (next == nullptr) {
    // if we are at the end of the list, return the current node
    result = head;
  } else {
    // return the value that the next node returns,
    // which is the node at the end of the list
    result = reverse_list_r(next);
    // then make the next node point upstream
    next->next_ = head;
  }
  // for all nodes other than the head, next_ will be overriden before this. so
  // this could be done more efficiently with a sub-function. but IMO if you are
  // concerned about efficiency you should do this iteratively.
  head->next_ = nullptr;
  return result;
}

//////////////////////////////////////////////////////////////////////////////
int main() {
  // test basic functionality, then restore the list to its original state
  LNode ln5 = LNode({5, nullptr});
  LNode ln4 = LNode({4, &ln5});
  LNode ln3 = LNode({3, &ln4});
  LNode ln2 = LNode({2, &ln3});
  LNode ln1 = LNode({1, &ln2});
  print_list(&ln1);
  print_list(reverse_list(&ln1));
  reverse_list(&ln5);
  // see what happens if we call reverse_list on a node in the middle.
  // then restore the original list and print it out again.
  reverse_list(&ln3);
  print_list(&ln1);
  print_list(&ln5);
  ln3.next_ = &ln4;
  ln4.next_ = &ln5;
  ln5.next_ = nullptr;
  print_list(&ln1);
  // finally test the recursive version and return 0.
  reverse_list_r(&ln1);
  print_list(&ln5);
  return 0;
}
