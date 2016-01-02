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

#include "./include/StrToInt.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
	Solution solution;
	string str("-123");
	int num = solution.StrToInt(str);
	cout << "num = " << num << endl;	
	return 0;
}
