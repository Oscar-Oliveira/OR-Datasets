This folder contains data for the paper:"Heuristic approaches for the two- and
three-dimensional knapsack packing problem".

Files:			Descriptors

testgen.c		Generator for 2D instances
testgen3d.c		Generator for 3D instances
ep2/			2D instances (ep2-xxxx) used in the paper
ep3/			3D instances (ep3-xxxx) used in the paper
other/			2D instances from other authors used in the paper. 




The file-format for .2kp-files is quite simple. 


* For 2D instances the first line contains the following

    dim, [W], [H]

  where [W] is the width and [H] the height of the knapsack. The following lines
  contains

    rect, [i],[w],[h],[p],[c]

  where [i] is the index of the rectangle (and can be ignored), [w] is the width
  of the rectangle, [h] the height of the rectangle, [p] the profit of the
  rectangle, [c] the number of times that rectangle is repeated.



* For 3D instances the first line has the format
    
    dim, [W], [H], [D]

  where [W], [H], [D] are width, height and depth respectively of the knapsack.
  Similarly, the boxes have the format:

  rect, [i],[w],[h],[d],[p],[c]

  where [d] is the depth of the box and the other values are the same as in the
  2D case.


I hope that this information can be helpful for any future research. 

  Enjoy - Jens Egeblad 2007 

