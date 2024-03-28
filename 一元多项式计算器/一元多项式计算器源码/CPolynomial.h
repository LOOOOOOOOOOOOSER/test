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
	CPolynomial(std::string strInput);//����ʽ���캯��,strInput�����Ǽ��̼����һԪ����ʽ
	~CPolynomial(){                   //��������������ڴ�
		m_vecData.clear(); 
	}
	CPolynomial(const CPolynomial & other);                       //�������캯��
	CPolynomial(const std::vector<std::pair<float, int>> & other);//���캯��������Ϊvector


	CPolynomial operator+(const CPolynomial & other); //���� + �����
	CPolynomial operator-(const CPolynomial & other); //���� - �����
	CPolynomial operator*(const CPolynomial & other); //���� * �����
	CPolynomial operator/(const CPolynomial & other); //���� / �����
	CPolynomial operator%(const CPolynomial & other); //���� % �����

	friend std::ostream& operator<<(std::ostream& os, const CPolynomial& other); //������������

	std::string getPolynomialWF();           //΢��
	std::string getPolynomialF();            //������
	std::string getPolynomialNF();           //��������
	float getPolynomialValueAtPoint(int a);  //��ĳ��ĺ���ֵ
	float getPolynomialValueArea(float x);   //��ĳ�㸽���ĸ�
	

public:
	std::vector<std::pair<float, int>> m_vecData;
};

