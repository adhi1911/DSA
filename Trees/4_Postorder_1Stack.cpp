vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;

}

/*
Algorithm:
1. Create a stack st
2. While cur is not null or st is not empty, do the following:
    a. If cur is not null, push cur to st and move cur to its left child
    b. Else, pop the top element from st and store it in temp
        i. If the right child of temp is null, push temp to result
        ii. Else, push temp to result and move cur to the right child of temp
3. Return result

*/