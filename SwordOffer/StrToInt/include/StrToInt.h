/* +---------------------------------------------------------------------------+
   | File:ReconstructBinaryTree.h                                              |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/16                                                           |
   | Describe:The result of the first order traversal of a two fork tree and   |
   |the result of the traversal of the order, please rebuild the two fork tree.|
   |If the input of the first order traversal and the results of the sequence  |
   |traversal are not included in the number of repeat. For example, the input |
   |sequence traversal sequence {1,2,4,7,3,5,6,8} and sequence traversal       |
   |sequence {4,7,2,1,5,3,8,6}, then reconstruct the two fork tree and return. |
   +---------------------------------------------------------------------------+ */
#ifndef _STRTOINT_H_
#define _STRTOINT_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std; 

enum Status {KValid = 0,KInvalid};
class Solution {
public:
    Solution(){};
    ~Solution(){};


    int status = KValid;
    
    
    int StrToInt(string str) {
        status = KInvalid;
        long long num = 0;
        
        string::size_type ix = 0;
        if(!str.empty() && (str[ix] != '\0'))
        {
            bool negative = false;
            
            if('+' == str[ix])
                ++ix;
            else if('-' == str[ix])
            {
                ++ix;
                negative = true;
            }
            
            if('\0' != str[ix])
            {
                num = StrToIntCore(str,ix,negative);
            }
        }
        return (int)num;
    }
    
    long long StrToIntCore(string str,string::size_type ix,bool negative)
    {
        long long num = 0;
        string::size_type it = ix;
        
        while('\0' != str[it])
        {
            if(str[it] >= '0' && str[it] <= '9')
            {
                int flag = negative ? -1 : 1;
                num = num * 10 + flag * (str[it] - '0');
                
                if((!negative && num > 0x7FFFFFFF)
                    || (negative && num < (signed int)0x80000000))
                {
		    cout << "1" <<endl;
                    num = 0;
                    break;
                }
                
                ++it;
            }
            else
            {
		 cout << "2" <<endl;
                num = 0;
                break;
            }
        }
        
	if('\0' == str[it])
	{
		status = KValid;
	}
        return num;
    }
};


#endif
