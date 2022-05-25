#include "stdafx.h"
#include "Word.h"
#include <map>
#include <cmath>

map<int, string> typeRoleMap = {
	{ Word::None, "None" },
	{ Word::Number, "Number" },
	{ Word::Symbol, "Symbol" },
	{ Word::Bracket, "Bracket"},
};

Word::Word()
{
	m_type = None;
}

Word::Word(Word::TypeRole type, const string & value)
{
	this->m_type = type;
	this->m_value = value;
}

int Word::type() const
{
	return m_type;
}

const string & Word::value() const
{
	return m_value;
}

Word & Word::operator+=(const Word & other)
{
	m_value = to_string(stoi(m_value) + stoi(other.m_value));
	return *this;
}

Word & Word::operator-=(const Word & other)
{
	m_value = to_string(stoi(m_value) - stoi(other.m_value));
	return *this;
}

Word &Word::operator*=(const Word &other)
{
	m_value = to_string(stoi(m_value) * stoi(other.m_value));
	return *this;
}

Word &Word::operator/=(const Word &other)
{
	m_value = to_string(stoi(m_value) / stoi(other.m_value));
	return *this;
}

Word &Word::operator^=(const Word &other)
{
	m_value = to_string(pow(stoi(m_value), stoi(other.m_value)));
	return *this;
}

ostream &operator<<(ostream &out, const Word &word)
{
// 	out << typeRoleMap[word.m_type];
// 	if (word.m_type != Word::None) {
// 		out << "," << word.m_value;
// 	}
	if (word.m_type != Word::None) {
		out << word.m_value;
	}
	return out;
}