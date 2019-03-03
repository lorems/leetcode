// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Laurent Beauregard
// Date   : 2019-03-02

// 2. Add Two Numbers
// Medium
// 
// You are given two non - empty linked lists representing two non - negative integers.The digits
// are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
// 
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
// Example:
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output : 7 -> 0 -> 8
// Explanation : 342 + 465 = 807.

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Runtime: 40 ms, faster than 97.14% of C++ online submissions for Add Two Numbers.
// Memory Usage : 19.2 MB, less than 32.54% of C++ online submissions for Add Two Numbers.
class Solution {
public:

	bool carryOver = false;

	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* resultHead = new ListNode(0);
		ListNode* resultNode = resultHead;		

		int i = 0;

		while (l1 != NULL || l2 != NULL || carryOver == true) {

			if (l1 == NULL && l2 == NULL) {
				resultNode->next = new ListNode(1);
				carryOver = false;
			}
			else if (i == 0) {
				resultNode->val = sumListNode(l1, l2);
			}
			else {
				ListNode* nxt = new ListNode(sumListNode(l1, l2));
				resultNode->next = nxt;

				resultNode = nxt;
			}

			if (l1 != NULL && l1->next != NULL)
				l1 = l1->next;
			else
				l1 = NULL;

			if (l2 != NULL && l2->next != NULL)
				l2 = l2->next;
			else
				l2 = NULL;

			++i;
		}

		return resultHead;
	}

	int sumListNode(ListNode* l1, ListNode* l2)
	{
		int a = l1 == NULL ? 0 : l1->val;
		int b = l2 == NULL ? 0 : l2->val;
		int c = carryOver ? 1 : 0;

		if (a + b + c > 9)
			carryOver = true;
		else
			carryOver = false;

		return (a + b + c) % 10;
	}
};

int main()
{
	cout << "Starting" << endl;

	//ListNode ln1 = ListNode(2);
	//ln1.next = new ListNode(4);
	//ln1.next->next = new ListNode(3);

	//ListNode ln2 = ListNode(5);
	//ln2.next = new ListNode(6);
	//ln2.next->next = new ListNode(4);

	ListNode ln1 = ListNode(1);

	ListNode ln2 = ListNode(9);
	ln2.next = new ListNode(9);

	Solution s;

	ListNode* result = s.addTwoNumbers(&ln1, &ln2);

	for (ListNode* it = result; it != NULL; it = it->next) {
		cout << it->val << endl;
	}
	
	//cout << ln1.val << endl;
	//cout << ln1.next->val << endl;

	cout << endl << "End";
	int v;
	cin >> v;
	return 0;
}