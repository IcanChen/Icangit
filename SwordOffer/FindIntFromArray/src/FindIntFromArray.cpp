/* +---------------------------------------------------------------------------+
   | File:FindIntFromArray.cpp                                                 |
   | Authors:Ican chen                                                         |
   | Date:2015/11/06                                                           |
   | Describe:                                                                 |
   +---------------------------------------------------------------------------+ */
#include "../include/FindIntFromArray.h"

bool Solution::Find(vector<vector<int> > array,int target) 
{
    size_t roCount = array.size();
    size_t coCount = array[0].size();

    for(size_t i = roCount - 1,j = 0;(i >= 0) && (j < coCount);)
    {
        if(target == array[i][j])
            return true;
        if(target < array[i][j])
        {
            i--;
            continue;
        }
        if(target > array[i][j])
        {
            j++;
            continue;
        }
    }
    return false;
}