/* +---------------------------------------------------------------------------+
   | File:MinNumberInRotateArray.cpp                                           |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/11/20                                                           |
   | Describe:The beginning of an array of several elements to the end of the  |
   | array, we call the array of rotation. Enter a non decreasing sequence of  |
   | a rotation, the output of the smallest element of the array. For example, |
   | an array of {3,4,5,1,2} for a {1,2,3,4,5} of a rotation, the minimum value|
   | of the array is 1                                                         |
   +---------------------------------------------------------------------------+ */
#include "../include/MinNumberInRotateArray.h"

int Solution::MinNumberInRotateArray(vector<int> rotateArray)
{
	//method 1
	/*
	if(rotateArray.size() <= 0)
		return 0;
	int indexStart = 0;
	int indexEnd = rotateArray.size() - 1;
	int indexMid = indexStart;

	while(rotateArray[indexStart] >= rotateArray[indexEnd])
	{
		if(1 == (indexEnd - indexStart))
		{
			indexMid = indexEnd;
			break;
		}
		indexMid = (indexStart + indexEnd)/2;

		if((rotateArray[indexMid] == rotateArray[indexStart]) && (rotateArray[indexMid] == rotateArray[indexEnd]))
		{
			int temp = rotateArray[0];
			for(size_t i = 0;i != rotateArray.size();i++)
			{
				if(temp > rotateArray[i])
					temp = rotateArray[i];
			}
			return temp;
		}


		if(rotateArray[indexMid] >= rotateArray[indexStart])
			indexStart = indexMid;
		else if(rotateArray[indexMid] <= rotateArray[indexEnd])
			indexEnd = indexMid;
	}

	return rotateArray[indexMid];*/

	//method 2;
/*	if(rotateArray.size() <= 0)
		return 0;
	vector<int>::iterator indexStart = rotateArray.begin();
	vector<int>::iterator indexEnd = rotateArray.end() - 1;
	vector<int>::iterator indexMid = indexStart;

	while(*indexStart >= *indexEnd)
	{
		if(1 == (indexEnd - indexStart))
		{
			indexMid = indexEnd;
			break;
		}
		indexMid = indexStart + (indexEnd - indexStart)/2;
		if((*indexMid == *indexStart) && (*indexMid == *indexEnd))
		{
			int temp = rotateArray[0];
			for(vector<int>::iterator iter = rotateArray.begin();iter != rotateArray.end();iter++)
			{
				if(temp > *iter)
					temp = *iter;
			}
			return temp;
		}


		if(*indexMid >= *indexStart)
			indexStart = indexMid;
		else if(*indexMid <= *indexEnd)
			indexEnd = indexMid;
	}

	return *indexMid;	

*/
	//method 3;
	if(rotateArray.size() == 0)
		return 0;
	vector<int>::iterator  iter = rotateArray.end() - 1;
	while((iter != rotateArray.begin()) && (*(iter - 1) <= *iter))
		iter--;
	return *iter;

}