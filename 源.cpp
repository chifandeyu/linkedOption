/* Delete a node in a list with O(1)
 * input:    pListHead - the head of list
 * pToBeDeleted - the node to be deleted
 */
#include <iostream>
using namespace std;
#include "标头.h"
//struct ListNode
//{
//	int m_nKey;
//	ListNode *m_pNext;
//};

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if(pListHead == NULL || pToBeDeleted == NULL)
		return;
	//=====================================================
	//删除非尾节点
	if(pToBeDeleted->m_pNext != nullptr)
	{
		ListNode *temp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_data = temp->m_data;
		pToBeDeleted->m_pNext = temp->m_pNext;

		delete temp;
		temp = nullptr;
	}
	//=======================================================
	//只有一个节点 删除头
	else if(pToBeDeleted == *pListHead)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}

	//最后一种 删除节点是尾节点
	else
	{
		ListNode *cur = *pListHead;
		while (cur->m_pNext != pToBeDeleted)
		{
			cur = cur->m_pNext;
		}
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		cur->m_pNext = nullptr;
	}
}

int main()
{
	Slist s1;
	s1.PushBack(5);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(1);
	s1.PushBack(5);
	s1.PushBack(6);
	s1.PushBack(7);
	s1.PushBack(8);
	s1.print();

	ListNode *num = s1.find(9);

	s1.DeleteNodeNumone(&s1.m_pHead, num);
	s1.print();
	
	num = s1.find(1);
	s1.DeleteNodeNumone(&s1.m_pHead, num);
	s1.print();

	num = s1.find(6);
	s1.DeleteNodeNumone(&s1.m_pHead, num);

	s1.print();
	return 0;
}