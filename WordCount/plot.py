import matplotlib.pyplot as plt 
import matplotlib.patches as mpatches
import numpy as np 

x = [10000, 50000, 100000, 500000]
unBSTO0 = [0.044, 0.156, 0.314, 1.715] 
BSTO0 = [1.62, 52.82, 213.86, 264.67]
unBSTO3 = [0.024, 0.115, 0.237, 1.354]
BSTO3 = [0.234, 5.335, 24.167, 653.597]
unTreap = [0.027, 0.209, 0.339, 1.619]
Treap = [0.024, 0.13, 0.218, 1.151]

x = np.array(x, dtype='d')
unBSTO0 = np.array(unBSTO0, dtype='d')
BSTO0 = np.array(BSTO0, dtype='d')
unBSTO3 = np.array(unBSTO3, dtype='d')
BSTO3 = np.array(BSTO3, dtype='d')
unTreap = np.array(unTreap, dtype='d')
Treap = np.array(Treap, dtype='d')

plt.figure(1) 
plt.plot(x, unBSTO0, 'bs--', x, unBSTO3, 'gs--', x, unTreap, 'rs--')
plt.title('Compare BST, optimized BST and Treap with unsorted words')
plt.ylabel('time (s)')
plt.xlabel('number of words')
plt.gca().legend(('BST', 'optimized BST', 'optimized Treap'))
#blue_patch = mpatches.Patch(color='blue', label='BST')
#red_patch = mpatches.Patch(color='red', label='optimized Treap')
#green_patch = mpatches.Patch(color='green', label='optimized BST')
#plt.legend(handles=[blue_patch])
#plt.legend(handles=[red_patch])
#plt.legend(handles=[green_patch])
#plt.legend(bbox_to_anchor=(1.05, 1), loc=2, borderaxespad=0.)
plt.savefig('Unsorted.png')

plt.figure(2)
plt.plot(x, BSTO0, 'b^--', x, BSTO3, 'g^--', x, Treap, 'r^--')
plt.title('Compare BST, optimized BST and Treap with presorted words')
plt.ylabel('time (s)')
plt.xlabel('number of words')
plt.gca().legend(('BST', 'optimized BST', 'optimized Treap'))
#blue_patch = mpatches.Patch(color='blue', label='BST')
#red_patch = mpatches.Patch(color='red', label='optimized Treap')
#green_patch = mpatches.Patch(color='green', label='optimized BST')
#plt.legend(handles=[blue_patch], handles=[red_patch], handles=[green_patch])
plt.savefig('Sorted.png')

plt.show()
