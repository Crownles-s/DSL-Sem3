# Data Structures Lab — C

A collection of Data Structures Lab (DSL) programs implemented in C, covering fundamental data structures, algorithms, pointers, dynamic memory allocation, and problem-solving techniques.

The repository documents my progression through the core concepts of data structures, from basic arrays and searching to linked lists, stacks, queues, and dynamic data structures.


## Contents

* Labs
* Topics Covered
* Repository Structure
* Compilation & Execution
* What I learned


## Labs

Lab	Focus
Lab 1	Arrays, Searching, Sorting & Matrix Operations
Lab 2	Pointers, Dynamic Memory & Recursion
Lab 3	Strings & Structures
Lab 4	Singly Linked Lists
Lab 7	Stacks & Expression Processing
Lab 8	Queues & Priority Queues

Labs 5 and 6 TBD.


## Topics Covered

### Arrays & Matrices

* One-dimensional arrays
* Two-dimensional arrays
* Finding maximum/minimum elements
* Matrix operations
* Matrix multiplication

### Searching

* Linear search
* Binary search

### Sorting

* Bubble sort
* Selection sort
* Insertion sort
* Recursive sorting
* Sorting structures
* Sorting linked lists

### Pointers & Dynamic Memory

* Pointer arithmetic
* Pointers to arrays
* Pointers to structures
* Dynamic arrays
* Dynamically allocated 2D arrays
* malloc()
* free()
* Dynamic structures

### Strings

* String length
* String concatenation
* String comparison
* Substring insertion
* Substring deletion

### Structures

* Defining and using structures
* Arrays of structures
* Structure sorting
* Searching structure data
* Dynamic allocation of structures

### Linked Lists

* Node creation
* Traversal
* Insertion
* Deletion
* Sorted insertion
* List reversal
* List sorting
* Deletion of alternate nodes

### Stacks

* Stack implementation
* push and pop
* Palindrome checking
* Parentheses matching
* Infix-to-postfix conversion
* Postfix expression evaluation
* Linked-list-based stacks

### Queues

* Queue implementation
* enqueue and dequeue
* Empty/full conditions
* Array-based queues
* Linked queues
* Priority queues


## Compilation & Execution

The programs can be compiled using GCC or any standard C compiler.

Compile

gcc filename.c -o program

Run

./program

For example:

gcc Lab4/q1.c -o linkedlist
./linkedlist

On Windows:

gcc Lab4/q1.c -o linkedlist.exe
linkedlist.exe


## What I Learned

Working through these programs helped build a practical understanding of how data structures are implemented at a low level in C.

Key takeaways include:

* Understanding how arrays store and organize data in contiguous memory.
* Implementing searching and sorting algorithms and understanding their basic trade-offs.
* Using pointers for direct memory access and traversal.
* Managing dynamically allocated memory using malloc() and free().
* Understanding how structures can represent more complex data.
* Building linked lists using dynamically allocated nodes and pointers.
* Implementing stacks and queues from the ground up.
* Applying stacks to problems such as palindrome checking and expression conversion/evaluation.
* Understanding the difference between LIFO and FIFO data organization.
* Using recursion as an alternative approach to iterative algorithms.
* Developing a stronger understanding of how abstract data structures translate into actual C implementations.
