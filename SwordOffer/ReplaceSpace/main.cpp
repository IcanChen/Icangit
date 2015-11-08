/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen                                                         |
   | Date:2015/11/08                                                           |
   | Describe:Replace the space in a string "%20".                             |
   +---------------------------------------------------------------------------+ */

#include <iostream>
#include <vector>
#include <string>

#include "include/ReplaceSpace.h"

using namespace std;
using std::vector;
using std::string;


int main( )
{
	Solution solution;
	char st[10] = " ";
	solution.replaceSpace(st,10);
	cout << st << "1" << endl;
}