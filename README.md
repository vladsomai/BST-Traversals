# Binary search tree

## Implementation of binary search tree using [C++].
 -'smart pointers' are used.\
 -searching a node is done using 'inoreder algorithm'.\
 -deleting of a node is done based on 3 cases:\
## The node that must be deleted should meet the following criteria:
   '1.' Does not have any children nodes.\
   '2.' Have only 1 child.\
   '3.' Have 2 children. \

   For the 1st case we traverse the tree and swap the node that must be deleted with nullptr.\
   For the 2nd case we traverse the tree and swap the node that must be deleted with the child node.\
   For the 3rd case we traverse the sub-tree of the node which must be deleted(we set this node to nullptr), then we search for the greatest node in the left sub-tree and swap the two.\
