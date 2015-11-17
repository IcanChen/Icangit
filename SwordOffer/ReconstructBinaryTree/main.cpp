/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/16                                                           |
   | Describe:The result of the first order traversal of a two fork tree and   |
   |the result of the traversal of the order, please rebuild the two fork tree.|
   |If the input of the first order traversal and the results of the sequence  |
   |traversal are not included in the number of repeat. For example, the input |
   |sequence traversal sequence {1,2,4,7,3,5,6,8} and sequence traversal       |
   |sequence {4,7,2,1,5,3,8,6}, then reconstruct the two fork tree and return. |
   +---------------------------------------------------------------------------+ */

#include "./include/ReconstructBinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;
using std::vector;


int main()
{
	Solution solution;
	int P[8] = {1,2,4,7,3,5,6,8};
	int I[8] = {4,7,2,1,5,3,8,6};
	vector<int> Pre(P,P+8);
	vector<int> In(I,I+8);
	TreeNode* Tree;
	Tree = solution.reConstructBinaryTree(Pre,In);
	
	return 0;
}