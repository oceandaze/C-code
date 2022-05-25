#pragma once
#include <map>
#include <list>
#include <stack>
#include "Word.h"


class Calculator
{
public:
	Calculator();
	~Calculator();

	void run(const string &expr);
private:
	void output() const;
	void pushSymbol(const Word &word, stack<Word> &symbolStack);
	void pushBracket(const Word &word, stack<Word> &symbolStack);

	bool token(Word &word);
	string tokenNumber();
	void tokenBlank();
	string Calculator::tokenPower();
private:
	string					m_expr;
	string::const_iterator	m_iter;
	map<string, int>		m_symbol;
	list<Word>				m_words;
};

