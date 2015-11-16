/* +---------------------------------------------------------------------------+
   | File:PrintListFromTailToHead.cpp                                           |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:Print list from tail to head.                                     |
   +---------------------------------------------------------------------------+ */
#include "../include/PrintListFromTailToHead.h"

vector<int> Solution::printListFromTailToHead(struct ListNode* head)
{
	//method one;
/*
	std::stack<ListNode *> nodesstack;

	ListNode* Tnode = head; 

	while(NULL != Tnode)
	{
		nodesstack.push(Tnode);
		Tnode = Tnode->next;
	}

	vectot<int> print;

	while(!Tnode.empty())
	{
		Tnode = nodesstack.top();
		print.push_back(Tnode->val);
		nodesstack.pop();
	}

	return print;
*/

	//method two
	ListNode* Tnode = head; 
	vector<int> print;
	if(NULL != Tnode)
	{
		if(NULL != Tnode->next)
		{
			print = printListFromTailToHead(Tnode->next);
		}

		print.push_back(Tnode->val);

	}

	return print;

}