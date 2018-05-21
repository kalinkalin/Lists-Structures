## Linked list

Implementation of singly linked list written in C, based on structures. Each node is contained of value field and pointer to next node in a list. There is specified first element in a list (head) and last element in a list (tail). 

<br>

![](https://image.ibb.co/mYZ6mT/408px_Singly_linked_list.png)

<hr>

### Operations:

  * **merge** - merging two lists, rewritting first list into new one than second one. Complexity O(size1 + size2).
  * **add** - adding new element to a list. New element is added at the end of a list as a new tail. Constant complexity.
  * **delete** -  deletion of element at given index. Complexity - O(size).
  * **check** - boolean function returning true when given element is in a list, false otherwise.
  * **find** - function returning value of element at given index. Complexity O(size).
  
Worst case of add, delete, check and find operations is O(size) because if we want to get to a last element of a list we have to 
pass all the elements starting from head and moving upwards.
