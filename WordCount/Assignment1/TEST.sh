#! /bin/bash 
#
# checks the difference between expected out put and the result
# from the program and show tree structures. 

diff expected.txt WordCount1R.txt 
diff expected.txt WordCount1optR.txt
diff expected.txt WordCount2R.txt
echo "<visualized BST O1 with random data>" 
cat visual1.txt 
echo "<visualized BST O3 with random data>" 
cat visual1opt.txt
echo "<visualized Treap O3 with random data>" 
cat visual2.txt

diff expectedS.txt sortedWordCount1R.txt
diff expectedS.txt sortedWordCount1optR.txt
diff expectedS.txt sortedWordCount2R.txt

echo "<visualized BST O1 with presorted data>" 
cat visual1s.txt
echo "<visualized BST O3 with presorted data>" 
cat visual1opts.txt
echo "<visualized Treap O3 with presorted data>" 
cat visual2s.txt
