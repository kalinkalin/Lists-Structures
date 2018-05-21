## Cyclic doubly linked list

Cyclic list is a variation of Linked list, there can be cyclic singly linked list and also cyclic doubly linked list. In this type 
of list last element (tale) points to first element (head) and in case of cyclic doubly linked list, also first element points to a
last element.

<br>

![](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/CircularLinkeList.png)

<hr>

### What are the advantages ?

Advantages of such solution are quite obvious. In finding node at given index and deleting node at given index we have to pass half 
of total number of elements at most, becouse if the given index is lower than half a size we can travel forward from head to next elements 
and if the index is higher than that we can travel backwards moving through previous elements pointers. Of course complexity of this 
operations is still linear, but constant is much lower.

<hr>

### Operations:
  
