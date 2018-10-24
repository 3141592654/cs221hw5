  # cs221hw5
  Build program using make. Run it with valgrind ./test_tree.
  I decided not to check if left_ and right_ were nullptrs in value_found. I reasoned that for defensiveness' sake the function would have to check if tree was a nullptr first. If value_found then passes tree->left_ as a nullptr to itself, it will exit. This has a modest cost since you have to copy things, but it's not clear this cost is greater than the cost of some additional logic.
  I implemented this using a reference for the result string, but cpplint didn't like that so I used a pointer.