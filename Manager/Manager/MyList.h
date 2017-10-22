#pragma once
#include "stdafx.h"

struct MyRect: public tagRECT
{
	void operator=(CRect _s)
	{
		top = _s.top;
		bottom = _s.bottom;
		left = _s.left;
		right = _s.right;
	}
};

struct SCtrlInfo
{
	int nID;
	MyRect rect;
};

template <class T>
class CMyList
{
private:
	typedef struct _node{
		_node(T _d)
		{
			data = _d;
			return;
		}
		T data;
		_node * prev = nullptr;
		_node * next = nullptr;
		~_node()
		{
			next = nullptr;
			prev = nullptr;
		}
	}node, *list;
public:
	CMyList();
	~CMyList();
public:
	void AddRear();
	void AddRear(T _d);
	T* Next();
private:
	list m_head;
};

template <class T>
CMyList<T>::CMyList()
{
	m_head = nullptr;
}


template <class T>
CMyList<T>::~CMyList()
{
	if (m_head = nullptr)
		return;
	node * p = m_head;
	node * next = m_head;
	while (p)
	{
		next = p->next;
		delete p;
		p = next;
	}
	m_head = nullptr;
}


template <class T>
void CMyList<T>::AddRear()
{
	node * pNew = new node;
	if (pNew == nullptr)
		exit(1);
	if (m_head == nullptr)
		m_head = pNew;
	else
	{
		node * pTail = m_head;
		while (pTail->next)
			pTail = pTail->next;
		pTail->next = pNew;
		pNew->prev = pt;
	}
}


template <class T>
void CMyList<T>::AddRear(T _d)
{
	node * pNew = new node(_d);
	if (pNew == nullptr)
		exit(1);
	if (m_head == nullptr)
		m_head = pNew;
	else
	{
		node * pTail = m_head;
		while (pTail->next)
			pTail = pTail->next;
		pTail->next = pNew;
		pNew->prev = pTail;
	}
}

template <class T>
T* CMyList<T>::Next()throw()
{
	static node * p = nullptr;
	if (p == nullptr)
		p = m_head;
	else
	{
		p = p->next;
		if (p == nullptr)
			return nullptr;
	}
	return &(p->data);
}