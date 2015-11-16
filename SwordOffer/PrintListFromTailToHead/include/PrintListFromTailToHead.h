/* +---------------------------------------------------------------------------+
   | File:PrintListFromTailToHead.h                                            |
   | Authors:Ican chen                                                         |
   | Date:2015/11/09                                                           |
   | Describe:Print list from tai to head.                                     |
   +---------------------------------------------------------------------------+ */
   
#ifndef _PRINTLISTFROMTAILTOHEAD_H_
#define _PRINTLISTFROMTAILTOHEAD_H_

#include <iostream>
#include <vector>

#include <stack>

using namespace std;
using std::vector;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
       val(x), next(NULL) {
    }
};

class Solution{
public:
	Solution(){};
	~Solution(){};
	vector<int> printListFromTailToHead(struct ListNode* head);

private:

};

#endif