#pragma once
typedef struct Node
{
	int val;
	struct Node * next;
}node;

class Stack
{
private:
	node * head;
	node * m_top;
	int cnt;
public:
	Stack();
	~Stack();


	int top();
	void push(int n);
	void pop();
	bool empty();
	int size();
	void output();
};

