/* +---------------------------------------------------------------------------+
   | File:ReconstructBinaryTree.cpp                                            |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/16                                                           |
   | Describe:The result of the first order traversal of a two fork tree and   |
   |the result of the traversal of the order, please rebuild the two fork tree.|
   |If the input of the first order traversal and the results of the sequence  |
   |traversal are not included in the number of repeat. For example, the input |
   |sequence traversal sequence {1,2,4,7,3,5,6,8} and sequence traversal       |
   |sequence {4,7,2,1,5,3,8,6}, then reconstruct the two fork tree and return. |
   +---------------------------------------------------------------------------+ */
#include "../include/ReconstructBinaryTree.h"

struct TreeNode* Solution::reConstructBinaryTree(vector<int> pre,vector<int> in)
{
   if(0 == pre.size())
      return NULL;

   TreeNode *root = new TreeNode(pre[0]);
   
   vector<int> leftPre,leftIn,rightPre,rightIn;
   vector<int>::iterator iter;

   for(iter = in.begin();iter != in.end();iter++)
      if(pre[0] == *iter)
         break;
      
   leftIn.assign(in.begin(),iter);
   rightIn.assign(iter + 1,in.end());
   leftPre.assign(pre.begin() + 1,pre.begin() + 1 + leftIn.size());
   rightPre.assign(pre.end() - rightIn.size(),pre.end());

   root->left = reConstructBinaryTree(leftPre,leftIn);
   root->right = reConstructBinaryTree(rightPre,rightIn);
   return root;
}