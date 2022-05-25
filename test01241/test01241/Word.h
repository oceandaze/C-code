#pragma once
#include <string>
#include <iostream>
using namespace std;

class Word
{
public:
	enum TypeRole
	{
		None,
		Number, //ÊýÖµ
		Symbol, //ÔËËã·û
		Bracket,//À¨ºÅ
	};

	Word();
	Word(Word::TypeRole type, const string &value);

	int type() const;
	const string &value() const;

	Word &operator+=(const Word &other);
	Word &operator-=(const Word &other);
	Word &operator*=(const Word &other);
	Word &operator/=(const Word &other);

	friend ostream &operator<<(ostream &out, const Word &word);
private:
	string    m_value;
	int		  m_type;
};

