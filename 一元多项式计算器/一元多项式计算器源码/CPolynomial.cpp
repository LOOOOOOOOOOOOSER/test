#include "CPolynomial.h"

CPolynomial::CPolynomial(std::string strInput)//定义多项式构造函数,strInput，就是键盘键入的一元多项式
{
	std::vector<std::string> v1 = InsertVectorstring(strInput);
	this->m_vecData = InsertVectorPair(v1);
}

CPolynomial::CPolynomial(const CPolynomial & other)//定义拷贝构造函数
{
	this->m_vecData.clear();
	this->m_vecData = other.m_vecData;
}

CPolynomial::CPolynomial(const std::vector<std::pair<float, int>> & other) {//构造函数，参数为vector
	this->m_vecData = other;
}

CPolynomial CPolynomial::operator+(const CPolynomial & other)//重载 + 运算符
{
	std::vector<std::pair<float, int>> mv = add(this->m_vecData, other.m_vecData);
	CPolynomial os(mv);
	return os;
}

CPolynomial CPolynomial::operator-(const CPolynomial & other)//重载 - 运算符
{
	std::vector<std::pair<float, int>> mv = sub(this->m_vecData, other.m_vecData);
	CPolynomial os(mv);
	return os;
}

CPolynomial CPolynomial::operator*(const CPolynomial & other)//重载 * 运算符
{
	std::vector<std::pair<float, int>> mv = mul(this->m_vecData, other.m_vecData);
	CPolynomial os(mv);
	return os;
}

CPolynomial CPolynomial::operator/(const CPolynomial & other)//重载 / 运算符
{
	std::vector<std::pair<float, int>> mv = div(this->m_vecData, other.m_vecData);
	CPolynomial os(mv);
	return os;
}

CPolynomial CPolynomial::operator%(const CPolynomial & other)//重载 % 运算符
{
	std::vector<std::pair<float, int>> mv = mod(this->m_vecData, other.m_vecData);
	CPolynomial os(mv);
	return os;
}

std::ostream& operator<<(std::ostream& os, const CPolynomial& other)//重载输出运算符<<
{
	std::vector<std::pair<float, int>> m = other.m_vecData;
	std::string outStr = vecToString(m);
	os << outStr << std::endl;
	return os;
}

float CPolynomial::getPolynomialValueAtPoint(int a)//在某点的函数值
{
	int x = a;
	std::sort(this->m_vecData.begin(), m_vecData.end(), MergeDec());
	float sum = 0;
	std::vector <std::pair<float, int>>::iterator it;
	for (it = m_vecData.begin(); it != m_vecData.end(); ++it) {
		if (it->second == 0) {
			sum += it->first;
		}
		else {
			float fmc = 1;
			for (int index = 0; index < it->second; ++index) {
				fmc *= x;
			}
			fmc = it->first * fmc;
			sum += fmc;
		}
	}
	return sum;
}

std::string CPolynomial::getPolynomialWF() //微分
{
	std::vector<std::pair<float,int>> v = getWF(this->m_vecData);
	std::string str = vecToString(v);
	return str;
}

std::string CPolynomial::getPolynomialNF()//不定积分
{
	std::vector<std::pair<float, int>> v = getNtF(this->m_vecData);
	std::string str = vecToString(v);
	return str;
}

std::string CPolynomial::getPolynomialF()//定积分
{
	std::string str = getF(this->m_vecData);
	return str;
}

float CPolynomial::getPolynomialValueArea(float x)//在某点附近的根
{
	float yy = x;

	std::vector <std::pair<float, int>> ::iterator it;
	bool bFind = false;
	std::sort(m_vecData.begin(), m_vecData.end(), Merge());
	for (it = m_vecData.begin(); it != m_vecData.end(); ++it) {
		if (it->second == 0) {
			it->first -= yy;
			bFind = true;
			break;
		}
	}

	if (bFind == false) {
		std::pair<float, int>p;
		p.first = 0 - yy;
		p.second = 0;
		m_vecData.insert(m_vecData.begin(), p);
	}

	std::vector <std::pair<float, int>> vdx1;
	for (it = m_vecData.begin(); it != m_vecData.end(); ++it) {
		std::pair<float, int>p;
		if (it->second == 0) {
			continue;
		}
		p.first = it->first * it->second;
		p.second = it->second - 1;
		vdx1.push_back(p);
	}

	float x0, x1 = 1.5, f, fdx;

	do {
		x0 = x1;
		f = getValue(m_vecData, x0);
		fdx = getValue(vdx1, x0);
		x1 = x0 - f / fdx;
	} while (fabsf(x1 - x0) >= 1e-5);

	return  x1;
}