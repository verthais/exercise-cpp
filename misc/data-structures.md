# Data Structures

## Overview

### Basic

- [Array](#array)
- [Singly Linked List](#singly-linked-list)
- [Doubly Linked List](#doubly-linked-list)
- [Circular Linked List](#circular-linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [Circular Queue](#circular-queue)

### Advanced

- [Map](#map)
- [HashTable](#hashtable)
- [Binary Tree](#binary-tree)
- [AVL Tree](#avl-tree)
- [Red-Black Tree](#red-black-tree)
- [Tries](#tries)
- [B-Tree](#b-tree)
- [Heap](#heap)
- [Graph](#graph)

### [Access times](#access-times)

## Linear Data Structures 

### Array

A data structure used to store homogeneous elements at contiguous locations. Size
of an array must be provided before storing data and cannot be changed without
reallocating every element. 

[Top](#data-structures)

### Singly Linked List

Every node stores reference of next node in list and the last node has next
address or reference as NULL. For example 1->2->3->4->NULL 

[Top](#data-structures)

### Doubly Linked List

There are two references associated with each node, One of the reference points
to the next node and one to the previous node. Advantage of this data structure
is that we can traverse in both the directions and for deletion we don’t need
to have explicit access to previous node. Eg. NULL<-1<->2<->3->NULL  

[Top](#data-structures)

### Circular Linked List

All nodes are connected to form a circle. There is no NULL at the end. A circular
linked list can be a singly circular linked list or doubly circular linked list.
Advantage of this data structure is that any node can be made as starting node.
This is useful in implementation of circular queue in linked list. Eg. 1->2->3->1
[The next pointer of last node is pointing to the first] 

[Top](#data-structures)

### Stack

LIFO (last in, first out) is an abstract data type that serves as a collection
of elements, with two principal operations: push, which adds an element to the
collection, and pop, which removes the last element that was added. In stack
both the operations of push and pop takes place at the same end that is top of
the stack. It can be implemented by using both array and linked list. It's used
for example by compiler to check for missing symbols like closing brackets. 

[Top](#data-structures)

### Queue

FIFO (first in, first out) is an abstract data type that serves as a collection
of elements, with two principal operations: enqueue, the process of adding an
element to the collection.(The element is added from the rear side) and dequeue,
the process of removing the first element that was added. (The element is removed
from the front side). It can be implemented by using both array and linked list.

[Top](#data-structures)

### Circular Queue

The advantage of this data structure is that it reduces wastage of space in case
of array implementation, As the insertion of the (n+1)’th element is done at the
0’th index if it is empty. 

[Top](#data-structures)

## Advanced Data Structures 

### Map

An abstract data type composed of a collection of (key, value) pairs, such that
each possible key appears at most once in the collection.  

[Top](#data-structures)

### HashTable

A structure that can map keys to values. Uses a hash function to compute an index,
also called a hash code, into an array of buckets or slots, from which the desired
value can be found. During lookup, the key is hashed and the resulting hash
indicates where the corresponding value is stored.  

Hashing often this is done in two steps:  

hash = hashfunc(key) 

index = hash % array_size 

Hash function should provide a uniform distribution of hash values to minimalize
the collisions. 

[Top](#data-structures)

### Binary Tree

(Binary Search Tree – BST) Unlike Arrays, Linked Lists, Stack and queues, which
are linear data structures, trees are hierarchical data structures. A binary tree
is a tree data structure in which each node has at most two children, which are
referred to as the left child and the right child. It is implemented mainly using
Links. 

## Support data structure for implementation of each algorithm: 

depth first search

stack

breadth-first search

queue

sorting 

heap

[Top](#data-structures)

### AVL Tree

Is a self-balancing Binary Search Tree (BST) where the difference between
heights of left and right subtrees cannot be more than one for all nodes. The balance
factor of the node is equal to difference between height of left and right subtree. 

[Top](#data-structures)

### Red-Black Tree

Is a kind of self-balancing binary search tree where each node has an extra bit,
and that bit is often interpreted as the colour. These colours are used to ensure
that the tree remains balanced during insertions and deletions. Although the balance
of the tree is not perfect, it is good enough to reduce the searching time and
maintain it around O(log n) time.  

Every node has a colour either red or black. 

The root is black. This rule is sometimes omitted. Since the root can always be changed
from red to black, but not necessarily vice versa, this rule has little effect on analysis. 

If a node is red, then both its children are black. 

Every path from a node (including root) to any of its descendant NULL node has the same number of black nodes. 

Splay tree a BST with additional property that frequently accessed nodes will move nearer
to the root where they can be accessed more quickly. The worst-case height—though
unlikely—is O(n), with the average being O(log n). The most significant disadvantage of
splay trees is that the height of a splay tree can be linear. 

[Top](#data-structures)

### Tries

Is an efficient information reTrieval data structure. Using Trie, search complexities can
be brought to optimal limit (key length). If we store keys in binary search tree, a well
balanced BST will need time proportional to M * log N, where M is maximum string length
and N is number of keys in tree. Using Trie, we can search the key in O(M) time. However
the penalty is on Trie storage requirements. Every node of Trie consists of multiple
branches. Each branch represents a possible character of keys. We need to mark the last
node of every key as end of word node. A Trie node field isEndOfWord is used to distinguish
the node as end of word node.  

[Top](#data-structures)

### B-Tree

Is a self-balancing search tree. In most of the other self-balancing search trees it is
assumed that everything is in main memory. To understand the use of B-Trees, we must think
of the huge amount of data that cannot fit in main memory. When the number of keys is high,
the data is read from disk in the form of blocks. The main idea of using B-Trees is to
reduce the number of disk accesses. Most of the tree operations (search, insert, delete,
max, min, ..etc ) require O(h) disk accesses where h is the height of the tree. B-tree is a
fat tree. The height of B-Trees is kept low by putting maximum possible keys in a B-Tree
node. Generally, the B-Tree node size is kept equal to the disk block size. Since the height
of the B-tree is low so total disk accesses for most of the operations are reduced
significantly. 

[Top](#data-structures)

### Heap

Is a special Tree-based data structure in which the tree is a complete binary tree. Generally,
Heaps can be of two types: 

[Top](#data-structures)

#### Max-Heap

In a Max-Heap the key present at the root node must be greatest among the keys present at all
of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree. 

[Top](#data-structures)

#### Min-Heap

In a Min-Heap the key present at the root node must be minimum among the keys present at all
of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.  

```
arr[(i-1)/2] 
```

Returns the parent node 

```
arr[(2*i)+1] 
```

Returns the left child node 

```
arr[(2*i)+2] 
```

Returns the right child node 

Time complexity of building a heap is O(n). 

[Top](#data-structures)

### Graph

Is a non-linear data structure consisting of nodes and edges. The nodes are sometimes also referred
to as vertices and the edges are lines or arcs that connect any two nodes in the graph. 

[Top](#data-structures)

## Access times

|                         | Random Access [] | push back  | pop back  |   insert   |    erase    |    find   |    sort     |
|:-----------------------:|:----------------:|:----------:|:---------:|:----------:|:-----------:|:---------:|:-----------:|
|          array          |        O(1)      |    N/A     |    N/A    |    N/A     |     N/A     |    O(n)   | O(n log(n)) |
|         vector          |        O(1)      |    O(1)    |    N/A    |    O(n)    |     O(n)    |    O(n)   | O(n log(n)) |
|          deque          |        O(1)      |    O(1)    |    O(1)   |    O(n)    |     O(n)    |    O(n)   | O(n log(n)) |
|          list           |        N/A       |    O(1)    |    O(1)   |    O(n)    |     O(n)    |    O(n)   | O(n log(n)) |
|      forward_list       |        N/A       |    N/A     |    N/A    |    O(1)    |     O(1)    |    O(n)   |     N/A     |
|      set/multiset       |        N/A       |    N/A     |    N/A    |  O(log(n)) |  O(log(n))  | O(log(n)) |     N/A     |
|      map/multimap       |        N/A       |    N/A     |    N/A    |  O(log(n)) |  O(log(n))  | O(log(n)) |     N/A     |
| unordered_set/multiset  |        N/A       |    N/A     |    N/A    |    O(1)    |     O(1)    |    O(1)   |     N/A     |
|  unordered_map/multimap |        N/A       |    N/A     |    N/A    |    O(1)    |     O(1)    |    O(1)   |     N/A     |

[Top](#data-structures)
