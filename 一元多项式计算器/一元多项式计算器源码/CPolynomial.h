#pragma once
#include <string>
#include<vector>
#include <iostream>
#include"mainMenu.h"
#include"menuOne.h"
#include"menuThrd.h"
class CPolynomial
{
public:
	CPolynomial(std::string strInput);//多项式构造函数,strInput，就是键盘键入的一元多项式
	~CPolynomial(){                   //析构函数，清除内存
		m_vecData.clear(); 
	}
	CPolynomial(const CPolynomial & other);                       //拷贝构造函数
	CPolynomial(const std::vector<std::pair<float, int>> & other);//构造函数，参数为vector


	CPolynomial operator+(const CPolynomial & other); //重载 + 运算符
	CPolynomial operator-(const CPolynomial & other); //重载 - 运算符
	CPolynomial operator*(const CPolynomial & other); //重载 * 运算符
	CPolynomial operator/(const CPolynomial & other); //重载 / 运算符
	CPolynomial operator%(const CPolynomial & other); //重载 % 运算符

	friend std::ostream& operator<<(std::ostream& os, const CPolynomial& other); //重载输出运算符

	std::string getPolynomialWF();           //微分
	std::string getPolynomialF();            //定积分
	std::string getPolynomialNF();           //不定积分
	float getPolynomialValueAtPoint(int a);  //在某点的函数值
	float getPolynomialValueArea(float x);   //在某点附近的根
	

public:
	std::vector<std::pair<float, int>> m_vecData;
};

