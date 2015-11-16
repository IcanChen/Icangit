/* +---------------------------------------------------------------------------+
   | File:main.cpp                                                             |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:Print list from tai to head.                                     |
   +---------------------------------------------------------------------------+ */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

#include "./include/PrintListFromTailToHead.h"



using namespace std;
using std::vector;

int main()
{
	Solution solution;

	ListNode *head,*node,*temp;

	head = (ListNode *)malloc(sizeof(ListNode));
	head->val = 0;
	node = (ListNode *)malloc(sizeof(ListNode));
	node->val = 1;
	head->next = node;
	temp = node;
	for(int i = 2;i < 5;i++)
	{
		node = (ListNode *)malloc(sizeof(ListNode));
		node->val = i;
		temp->next = node;
		temp = node;
	}
	vector<int> print;

 	print = solution.printListFromTailToHead(head);

 	for(vector<int>::size_type i = 0;i != print.size();i++)
 	{
 		cout << print[i] << endl;
 	}

	return 0;
}