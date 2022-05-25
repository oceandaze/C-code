#include "stdafx.h"
#include "Stack.h"
#include <iostream>

using namespace std;
Stack::Stack()
{
	node * pnew = new node;
	memset(pnew, 0, sizeof(node));
	pnew->next = nullptr;
	head = pnew;
	m_top = nullptr;
	cnt = 0;
}


Stack::~Stack()
{
	if (head != nullptr){
		node *t = nullptr;
		while (head!=nullptr)
		{
			t = head->next;
			cout << "释放" << head->val << "的内存" << endl;
			delete head;
			head = t;	
		}
		cnt = 0;
	}
{
}
}

int Stack::top()
{
	if (m_top!=nullptr){
		return m_top->val;
	}
}

void Stack::push(int a)
{
	node * pnew = new node;
	memset(pnew, 0, sizeof(node));
	pnew->next = nullptr;
	if (cnt==0){
		head->next = pnew;
		m_top = pnew;
		pnew->val = a;
		cnt = 1;
	}
	else{
		pnew->next = m_top;
		pnew->val = a;
		m_top = pnew;
		head->next = m_top;
		cnt++;
	}
}

void Stack::pop()
{
	if (m_top!=nullptr){
		m_top = m_top->next;
		cout << "释放" << head->next->val << "的内存" << endl;
		delete head->next;
		head->next = m_top;
		cnt--;
	}
}

bool Stack::empty()
{
	return m_top==nullptr;
}

int Stack::size()
{
	return cnt;
}

void Stack::output()
{
	if (m_top!=nullptr){
		node * t = nullptr;
		t = head->next;
		while (t!=nullptr){
			cout << t->val << " ";
			t = t->next;
		}	
	}
}


