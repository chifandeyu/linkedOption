#ifndef _HEAD_H_
#define _HEAD_H_

typedef int DataType;

class ListNode
{
public:
	ListNode(const DataType & x):m_data(x), m_pNext(NULL){}

	DataType m_data;
	ListNode * m_pNext;
};

class Slist
{
public:
	Slist():m_pHead(NULL), m_pTail(NULL)
	{}

	~Slist()
	{
		Destroy();
	}

	void Destroy()
	{
		ListNode *begin =m_pHead;
		while (begin)
		{
			ListNode *del = begin;
			begin = begin->m_pNext;
			delete del;
		}
	}
public:
	//β�巨
	void PushBack(const DataType &x)
	{
		if (m_pHead == NULL)
		{
			m_pHead = new ListNode(x);
			m_pTail = m_pHead;
		}
		else
		{
			m_pTail->m_pNext = new ListNode(x);
			m_pTail = m_pTail->m_pNext;
		}
	}
	//����
	ListNode *find(const DataType&x)
	{
		ListNode *tmp = m_pHead;
		while (tmp != NULL)
		{
			if(tmp->m_data == x)
				return tmp;
			else
			{
				tmp = tmp->m_pNext;
			}
		}
		return NULL;
	}

	//��O(1)ʱ����, ɾ��һ���ڵ�,��������:
	void DeleteNodeNumone(ListNode **phead, ListNode *pToBeDelete)
	{
		if(*phead == nullptr || pToBeDelete == nullptr)
			return;
		
		if(pToBeDelete->m_pNext != nullptr)
		{
			ListNode *temp = pToBeDelete->m_pNext;
			pToBeDelete->m_data = temp->m_data;
			pToBeDelete->m_pNext = temp->m_pNext;

			delete temp;
			temp = nullptr;
		}
		//only one node
		else if(*phead == pToBeDelete)
		{
			delete pToBeDelete;
			pToBeDelete = nullptr;
			*phead = nullptr;
		}

		//ɾ���ڵ���β�ڵ�
		else
		{
			ListNode *cur = *phead;
			while (cur->m_pNext != pToBeDelete)
			{
				cur = cur->m_pNext;
			}
			delete pToBeDelete;
			pToBeDelete = nullptr;
			cur->m_pNext = nullptr;
		}
	}
	
	void print()
	{
		ListNode *begin = m_pHead;
		while (begin)
		{
			cout<<begin->m_data<<"->";
			begin = begin->m_pNext;
		}
		cout<<"NUll"<<endl;
	}
public:
	ListNode *m_pHead;//ͷ�ڵ�ָ��
	ListNode *m_pTail;//β�ڵ�ָ��
};

#endif //_HEAD_H_