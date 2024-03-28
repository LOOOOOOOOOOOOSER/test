#include<iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class String
{
public:
	String()
	{
		size = 0;
		str = new char[size + 1];
		str[0] = '\0';
	}
	String(const String& obj)
	{
		size = obj.size;
		str = new char[size + 1];
		if (str == nullptr)
		{
			cout << "Failed to apply for space" << endl;
			exit(1);
		}
		strcpy(str, obj.str);
	}


	String(const char* s)
	{
		size = strlen(s);
		str = new char[size + 1];
		if (str == nullptr)
		{
			cout << "Failed to apply for space" << endl;
			exit(1);
		}
		strcpy(str, s);
	}

	String substr(int pos, int length)
	{
		String tmp;
		int len = size - pos >= length ? length : size - pos;
		tmp.size = len;
		tmp.str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			tmp.str[i] = str[i + pos];
		}
		tmp.str[len] = '\0';
		return tmp;
	}

	void insert(const String& obj, int pos)
	{
		String tmp;
		tmp.size = obj.size + size;
		tmp.str = new char[tmp.size + 1];
		for (int i = 0; i < pos; i++)
		{
			tmp.str[i] = str[i];
		}
		for (int i = pos; i < pos + obj.size; i++)
		{
			tmp.str[i] = obj.str[i - pos];
		}
		for (int i = 0; i < size - pos; i++)
		{
			tmp.str[i + pos + obj.size] = str[pos + i];
		}
		tmp.str[tmp.size] = '\0';
		delete[] str;
		str = tmp.str;
		size = tmp.size;
		tmp.str = nullptr;
	}

	void Delete(int pos, int length)
	{
		String tmp;
		int len = size - pos >= length ? length : size - pos;
		tmp.size = size - len;
		tmp.str = new char[tmp.size + 1];
		int i = 0;
		while (i < pos)
		{
			tmp.str[i] = str[i];
			i++;
		}
		int j = pos + len;
		while (j < size)
		{
			tmp.str[i] = str[j];
			i++;
			j++;
		}
		tmp.str[i] = '\0';
		delete[] str;
		str = tmp.str;
		size = tmp.size;
		tmp.str = nullptr;
	}

	int strsize()
	{
		return size;
	}

	String& operator=(String obj)
	{
		if (this->str == obj.str) return *this;
		if (str != nullptr) delete[] str;
		size = obj.size;
		str = new char[size + 1];
		strcpy(str, obj.str);
		return *this;
	}

	String& operator=(const char* s)
	{
		if (this->str == s) return *this;
		if (str != nullptr) delete[] str;
		size = strlen(s);
		str = new char[size + 1];
		strcpy(str, s);
		return *this;
	}

	String operator+(String& obj)
	{
		String tmp;
		tmp.size = size + obj.size;
		tmp.str = new char[tmp.size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp.str[i] = str[i];
		}
		for (int i = size; i < tmp.size; i++)
		{
			tmp.str[i] = obj.str[i - size];
		}
		tmp.str[tmp.size] = '\0';
		return tmp;
	}

	String operator+(const char* s)
	{
		String tmp;
		tmp.size = strlen(s) + size;
		tmp.str = new char[tmp.size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp.str[i] = str[i];
		}
		for (int i = size; i < tmp.size; i++)
		{
			tmp.str[i] = s[i - size];
		}
		tmp.str[tmp.size] = '\0';
		return tmp;
	}

	friend String operator+(const char* s, String& obj);

	friend ostream& operator<<(ostream& os, const String& obj);

	friend istream& operator>>(istream& is, String& obj);

	bool operator ==(const String& b)
	{
		if (size != b.size) return false;

		for (int i = 0; i < size; i++)
		{
			if (str[i] != b.str[i]) return false;
		}
		return true;
	}

	bool operator !=(const String& b)
	{
		if (*this == b) return false;
		return true;
	}

	char& operator[](int x)
	{
		if (x > size)
		{
			cout << "The value passed in is out of bounds" << endl;
			exit(1);
		}
		return str[x];
	}

	const char& operator[](int x) const
	{
		if (x > size)
		{
			cout << "The value passed in is out of bounds" << endl;
			exit(1);
		}
		return str[x];
	}

	~String()
	{
		if (str != nullptr)
			delete[] str;
	}

	char* str;
	int size;
};

String operator+(const char* s, String& obj)
{
	String tmp;
	int len = strlen(s);
	tmp.size = strlen(s) + obj.size;
	tmp.str = new char[tmp.size + 1];
	for (int i = 0; i < len; i++)
	{
		tmp.str[i] = s[i];
	}
	for (int i = len; i < tmp.size; i++)
	{
		tmp.str[i] = obj.str[i - len];
	}
	tmp.str[tmp.size] = '\0';
	return tmp;
}

ostream& operator<<(ostream& os, const String& obj)
{
	os << obj.str;
	return os;
}


int main()
{
	String s("hello");
	String s1(s);
	cout << s1.strsize() << endl;
	cout << s1 << endl;
	s1.Delete(2, 3);
	cout << s1 << endl;
	s1.insert("llo", 2);
	cout << s1 << endl;
	cout << s1 + s << endl;
	cout << s[1] << endl;
	return 0;
}
