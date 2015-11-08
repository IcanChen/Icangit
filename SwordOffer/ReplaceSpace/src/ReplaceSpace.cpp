/* +---------------------------------------------------------------------------+
   | File:ReplaceSpace.cpp                                                 |
   | Authors:Ican chen                                                         |
   | Date:2015/11/08                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/ReplaceSpace.h"

void Solution::replaceSpace(char *str,int length) 
{
  if((NULL == str) || (0 >= length))
    return ;

  int numSpace = 0;
  int originalLength = 0;

  while('\0' != str[originalLength])
  {
    if(' ' == str[originalLength])
      numSpace++;

    originalLength++;
  }

  int NewLength = originalLength + 2*numSpace;

  if(NewLength > length)
    return;
  int indexOfNewLength = NewLength;
  for(int j = originalLength;j >= 0;j--)
  {
    if (str[j] == ' ')
    {
      str[indexOfNewLength--] = '0';
      str[indexOfNewLength--] = '2';
      str[indexOfNewLength--] = '%';
    }
    else
    {
      str[indexOfNewLength--] = str[j];
    }
  }   
}
