#include "stdafx.h"
#include "Calculator.h"


Calculator::Calculator()
{
	m_symbol["+"] = 1;
	m_symbol["-"] = 1;
	m_symbol["*"] = 2;
	m_symbol["/"] = 2;
	m_symbol["**"] = 2;
}


Calculator::~Calculator()
{
}

void Calculator::run(const string & expr)
{
	m_expr = expr;
	m_iter = m_expr.begin();
	m_words.clear();

#ifdef _DEBUG
	cout << "表达式：" << expr << endl;
#endif
	stack<Word>  symbolStack;

	Word word;
	while (token(word)) {
		int typeRole = word.type();
		if (typeRole == Word::Number) {
			m_words.push_back(word);
		}
		else if (typeRole == Word::Symbol) {
			pushSymbol(word, symbolStack);
		}
		else if (typeRole == Word::Bracket) {
			pushBracket(word, symbolStack);
		}
	}

	while (!symbolStack.empty()) {
		m_words.push_back(symbolStack.top());
		symbolStack.pop();
	}

#ifdef _DEBUG
	cout << "后缀：";
	for (const auto &i : m_words) {
		cout << i << " ";
	}
	cout << endl;
#endif
	output();
}

void Calculator::output() const
{
	stack<Word>  _stack;

	for (const auto &i : m_words) {
		if (i.type() == Word::Number) {
			_stack.push(i);
		}
		else if (i.type() == Word::Symbol) {
			Word op2 = _stack.top(); _stack.pop();
			Word op1 = _stack.top(); _stack.pop();
			if (i.value() == "+") {
				op1 += op2;
			} else if (i.value() == "-") {
				op1 -= op2;
			} else if (i.value() == "*") {
				op1 *= op2;
			} else if (i.value() == "/") {
				op1 /= op2;
			} else if (i.value() == "**") {
				op1 ^= op2;
			}
			_stack.push(op1);
		}
	}

	if (_stack.size() == 1) {
		cout << m_expr << "=";
		cout << _stack.top() << endl;
	}
	else {
		cout << "表达式错误" << endl;
	}
}

void Calculator::pushSymbol(const Word & word, stack<Word>& symbolStack)
{
	int level = m_symbol[word.value()];
	while (!symbolStack.empty()) {
		const Word &top = symbolStack.top();
		if (top.value() == "(") {
			break;
		}

		int topLevel = m_symbol[top.value()];
		if (level > topLevel) {
			break;
		}
		else {
			m_words.push_back(top);
			symbolStack.pop();
		}
	}

	symbolStack.push(word);
}

void Calculator::pushBracket(const Word & word, stack<Word>& symbolStack)
{
	if (word.value() == "(") {
		symbolStack.push(word);
		return;
	}
	
	while (!symbolStack.empty()) {
		Word top = symbolStack.top();
		symbolStack.pop();

		if (top.value() == "(") {
			break;
		}
		else {
			m_words.push_back(top);
		}
	}
}

bool Calculator::token(Word & word)
{
	if (m_iter == m_expr.end()) {
		return false;
	}

	if (isdigit(*m_iter)) {
		word = Word(Word::Number, tokenNumber());
		return true;
	} else if (isblank(*m_iter)) {
		tokenBlank();
		word = Word(Word::None, "");
		return true;
	} else if (*m_iter == '(' || *m_iter == ')') {
		word = Word(Word::Bracket, string(1, *m_iter));
		++m_iter;
		return true;
	}

	string str = tokenSymbol();
	if (!str.empty()) {
		m_iter += str.size();
		word = Word(Word::Symbol, str);
		return true;
	}
	
	return false;
}

string Calculator::tokenNumber()
{
	string str;
	for (; m_iter != m_expr.end(); ++m_iter) {
		if (isdigit(*m_iter)) {
			str += *m_iter;
		}
		else {
			break;
		}
	}
	return str;
}

string Calculator::tokenSymbol()
{
	string str;
	str += *m_iter;
	if (*m_iter == '*' && *(m_iter + 1) == '*') {
		str += '*';
	}

	auto iter = m_symbol.find(str);
	if (iter != m_symbol.end()) {
		return str;
	}
	
	return string();
}

void Calculator::tokenBlank()
{
	for (; m_iter != m_expr.end(); ++m_iter) {
		if (!isblank(*m_iter)) {
			break;
		}
	}
}

