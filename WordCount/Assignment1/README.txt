README.txt 

Gihwan Kwon (Kris) 
CSS343 - Data Structures, Algorithms, Discrete Mathematics 2 
Assignment 1 - Treap
-------------------------------------------------------------------------------
<DESCRIPTION> 
This program reads in words and put it into a dictionary.This dictionary can
hold the words in order and its frequency while reading the words.

It should be noted that dictionaries are implemented in two different ways.
 
First, the dictionary is implemented with Binary search tree. 
Second, the dictionary is implemented with Treap. 

<EXAMPLE> 
input: 
c
b
a
c
b
a
a

output:
3 a 
2 b 
2 c  

<BUILDING the Program>
BUILD.sh file builds 3 programs.
1. Dictionary implemented with Binary Search Tree
2. Dictionary implemented with Binary Search Tree and O3 optimization 
   in g++ compiler
3. Dictionary implemented with Treap and O3 optimization in g++ compiler 

<RUNNING the program> 
RUN.sh file runs all three programs with presorted and unsorted input. 
Each programs will produce outputs and structures in separate text files. 

<TESTING the program>  
TEST.sh file will check the differences between the expected outputs and 
the actual outputs from running the programs. Moreover, it shows the 
structure of the tree (BST or Treap).

<Result of program> 
Outputs from all three programs seem identical based on the inputs. However, 
the graphs drawn based on the data from PERFORMANCE.sh file proves the 
big differences in terms of time efficiency. When sorted words are used 
as an input text file, implementing dictionary with BST does not gurantee 
the operation time log n. However, Treap, because of its properties, the 
tree become balanced in certain degrees. Finally, Dictionary implemented with 
BST and compiled in O3 optimization takes even longer when input gets bigger. 
This is because O3 optimization optimize the memory inside the program instead
of the operation optimzation. 
