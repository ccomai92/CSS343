#! /bin/bash
#
# Measures time for the performance and 
# prints the time on the console. 
# -----------------------------------------------------
# Reference 
#	stackoverflow.com 


# Data with random and unsorted words with BST
echo "BST with O0" 
echo "Random 500,000 words: "
time ./WordCount1 < random500000.txt > result500.txt 
echo "Random 100,000 words: " 
time ./WordCount1 < random100000.txt > result100.txt 
echo "Random 50,000 words: " 
time ./WordCount1 < random50000.txt > result50.txt 
echo "Random 10,000 words: " 
time ./WordCount1 < random10000.txt > result10.txt 

# Data with random but sorted words with BST
echo "Sorted 500,000 words: "
time ./WordCount1 < sorted500.txt > sResult500.txt 
echo "Sorted 100,000 words: " 
time ./WordCount1 < sorted100.txt > sResult100.txt 
echo "Sorted 50,000 words: " 
time ./WordCount1 < sorted50.txt > sResult50.txt 
echo "Sorted 10,000 words: " 
time ./WordCount1 < sorted10.txt > sResult10.txt 

# Data with random and unsorted words with optimized BST
echo "BST with O3"
echo "Random 500,000 words: " 
time ./WordCount1opt < random500000.txt > result500.txt 
echo "Random 100,000 words: " 
time ./WordCount1opt < random100000.txt > result100.txt 
echo "Random 50,000 words: " 
time ./WordCount1opt < random50000.txt > result50.txt 
echo "Random 10,000 words: " 
time ./WordCount1opt < random10000.txt > result10.txt 

# Data with random but sorted words with optimized BST
echo "Sorted 500,000 words: " 
time ./WordCount1opt < sorted500.txt > sResult500.txt 
echo "Sorted 100,000 words: " 
time ./WordCount1opt < sorted100.txt > sResult100.txt 
echo "Sorted 50,000 words: " 
time ./WordCount1opt < sorted50.txt > sResult50.txt 
echo "sorted 10,000 words: " 
time ./WordCount1opt < sorted10.txt > sResult10.txt 

# Data with random and unsorted words with optimized Treap
echo "Treap with O3" 
echo "Random 500,000 words: " 
time ./WordCount2 < random500000.txt > result500.txt 
echo "Random 100,000 words: " 
time ./WordCount2 < random100000.txt > result100.txt 
echo "Random 50,000 words: " 
time ./WordCount2 < random50000.txt > result50.txt 
echo "Random 10,000 words: " 
time ./WordCount2 < random10000.txt > result10.txt 

# Data with random but sorted words with optimized Treap 
echo "Sorted 500,000 words: " 
time ./WordCount2 < sorted500.txt > sResult500.txt 
echo "Sorted 100,000 words: " 
time ./WordCount2 < sorted100.txt > sResult100.txt 
echo "Sorted 50,000 words: " 
time ./WordCount2 < sorted50.txt > sResult50.txt 
echo "Sorted 10,000 words: " 
time ./WordCount2 < sorted10.txt > sResult10.txt 

