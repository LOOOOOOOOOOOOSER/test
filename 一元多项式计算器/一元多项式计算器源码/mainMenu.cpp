#include"mainMenu.h"
#include"menuOne.h"
#include"menuThrd.h"
const char *cMenu_top = (const char*)   "*************************** ��ӭʹ�ö���ʽ������ ******************************\n"
										"*************************** ������������Ҫ�Ĺ��� ******************************\n"
										"*************************** 0���˳�ϵͳ          ******************************\n"
										"*************************** 1������ʽ��������    ******************************\n"
										"*************************** 2���������ʽ��ĳ��ĺ���ֵ ***********************\n"
										"*************************** 3������ʽ���ֻ�΢������ ***************************\n"
										"*************************** 4���������ʽ��ĳ�㸽���ĸ� ***********************\n"
										"*************************** 5���鿴��ǰʱ��      ******************************\n";

//�洢����ʽ������
std::vector<std::pair<float, int>> oneVect{};
std::vector<std::pair<float, int>> twoVect{};
// ��ʾ���˵�
int Printf_MainMenu()
{
	std::cout << cMenu_top << std::endl << std::endl;
	std::cin.clear();

	char num;
	
	while (true) {
		std::cin >> num;
		std::cin.get();
		if (std::isdigit(num)) {
			break;
		}
		else {
			std::cin.clear();
		}
	}
	return num - 0x30;
}
// ��ʾ��һ���˵������ж���ʽ����
int Printf_OneMenu()
{
	std::vector<std::pair<float, int>> ret{};
Label:
	std::cout << "***************************�������һ������ʽ***********************************" << std::endl ;
	oneVect.clear();
	std::string first_input ="";
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	oneVect = InsertVectorPair(v1);
	

Label1:
	std::cout << "***************************������ڶ�������ʽ***********************************" << std::endl;
	        

	std::string second_input ="";
	std::getline(std::cin, second_input);
	std::vector<std::string> v2 = InsertVectorstring(second_input);
	if (v2.empty()) {
		goto Label1;
	}
	twoVect = InsertVectorPair(v2);


Label2:
	std::cout << "***************************������������Ҫ������*********************************" << std::endl;
	std::cout << "*************************** 0.�ӷ�             *********************************" << std::endl;
	std::cout << "*************************** 1.����             *********************************" << std::endl;
	std::cout << "*************************** 2.�˷�             *********************************" << std::endl;
	std::cout << "*************************** 3.����             *********************************" << std::endl;
	std::cout << "*************************** 4.ȡ��             *********************************" << std::endl;
	std::cout << "*************************** 5.�������˵�       *********************************" << std::endl;
	std::cout << std::endl;

LLO:
	char num = 0x30;

	while (true) {
		std::cin >> num;
		std::cin.get();
		if (std::isdigit(num)) {
			break;
		}
		else {
			std::cin.clear();
		}
	}
	int iSel =  num - 0x30;
	std::string strRet = "";
	switch (iSel)
	{
	case 0://+
		ret = add(oneVect, twoVect);
		strRet = ::vecToString(ret);
		std::cout << strRet << std::endl;
		break;
	case 1://-
		ret = sub(oneVect, twoVect);
		strRet = ::vecToString(ret);
		std::cout << strRet << std::endl;
		break;
	case 2://*
		ret = mul(oneVect, twoVect);
		strRet = ::vecToString(ret);
		std::cout << strRet << std::endl;
		break;
	case 3:// /
		ret = div(oneVect, twoVect);
		strRet = ::vecToString(ret);
		std::cout << strRet << std::endl;
		break;
	case 4:// mod
		ret = mod(oneVect, twoVect);
		strRet = ::vecToString(ret);
		std::cout << strRet << std::endl;
		break;
	case 5://top menu
	default:
		break;
	}
	
	return 5;
}
// ����Ƿ�������ȷ
bool CheckIsOk()
{
	return 1;
}
// �رճ���
#include <Windows.h>
void Printf_ZeroMenu()
{
	HWND hWnd = ::GetForegroundWindow();
	if (nullptr != hWnd) {
		SendMessage(hWnd, WM_CLOSE, 0, 0);
	}
}
// ��ʾ�ڶ����˵���������ؼ���
int Printf_TwoMenu()
{
Label:
	std::cout << "***************************���������ʽ*****************************************" << std::endl;
	std::vector <std::pair<float, int>> vec;

	std::string first_input;
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	vec = InsertVectorPair(v1);

	std::cout << "***************************������x��ֵ******************************************" << std::endl;
	
	char num;

	while (true) {
		std::cin >> num;
		std::cin.get();
		if (std::isdigit(num)) {
			break;
		}
		else {
			std::cin.clear();
		}
	}
	int x =  num - 0x30;

	std::cout << "***************************�õ�y��ֵ********************************************" << std::endl;
	std::sort(vec.begin(), vec.end(), MergeDec());
	float sum = 0;
	std::vector <std::pair<float, int>>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {
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
	std::cout << sum << std::endl;

LABEL9:
	std::cout << "***************************����0���������˵�************************************" << std::endl;

	

	while (true) {
		std::cin >> num;
		std::cin.get();
		if (std::isdigit(num)) {
			break;
		}
		else {
			std::cin.clear();
		}
	}
	x = num - 0x30;
	if (x != 0) {
		goto LABEL9;
	}
	return 0;
}
// ��ʾ�������˵���������ؼ���
int Printf_ThirdMenu()
{
Label:
	std::cout << "***************************���������ʽ*****************************************" << std::endl;
	std::vector <std::pair<float, int>> vec;
	std::vector <std::pair<float, int>> ret;
	std::string first_input;
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	vec = InsertVectorPair(v1);

LO:
	std::cout << "***************************���������㹦��***************************************" << std::endl;
	std::cout << "***************************0.΢��***********************************************" << std::endl;
	std::cout << "***************************1.��������*******************************************" << std::endl;
	std::cout << "***************************2.������*********************************************" << std::endl;
	std::cout << "***************************3.�������˵�*****************************************" << std::endl;

	char num;

	while (true) {
		std::cin >> num;
		std::cin.get();
		if (std::isdigit(num)) {
			break;
		}
		else {
			std::cin.clear();
		}
	}
	int x = num - 0x30;
	if (x != 0 && x != 1 && x != 2 && x != 3) {
		goto LO;
	}
	std::string strRet = "";
	switch (x)
	{
	case 0:
		ret = getWF(vec);
		strRet = vecToString(ret);
		std::cout << strRet << std::endl;
		break;
	case 1:
		ret = getNtF(vec);
		strRet = vecToString(ret);
		strRet += "+ C";
		std::cout << strRet << std::endl;
		break;
	case 2:
		strRet = getF(vec);
		std::cout << strRet << std::endl;
		break;
	case 3:
	default:
		break;
	}

	return 3;

}
// ����ַ����Ƿ�Ϊ������

bool isFloat(const std::string& str) {
	std::stringstream ss(str);
	float f;
	ss >> f;
	if (ss.fail()) {
		return false;
	}
	return true;
}
// ��ȡ����ʽ��ĳ���ֵ

float getValue(std::vector <std::pair<float, int>> &vec , float x)
{
	float sum = 0 ,tmp =1;
	std::vector <std::pair<float, int>> ::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {
		if (it->second == 0) {
			sum += it->first;
		}
		else {
			for (int i = 0; i < it->second; ++i) {
				tmp *= x;
			}
			tmp = tmp * it->first;
			sum += tmp;
		}
	}
	return sum;
}
// ��ʾ���ĸ��˵���������ؼ���
int Printf_FourMenu()
{
Label:
	std::cout << "***************************���������ʽ*****************************************" << std::endl;
	std::vector <std::pair<float, int>> vec;

	std::string first_input;
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	vec = InsertVectorPair(v1);

LO:
	std::cout << "***************************������y��ֵ******************************************" << std::endl;
	std::string input;
	while (true) {
		std::cin >> input;
		if (input.empty()) {
			std::cin.clear();
			continue;
		}
		else if (std::all_of(input.begin(), input.end(), ::isdigit)) {
			break;
		}
		else {
			std::cin.clear();
			continue;
		}
	}

	if (!isFloat(input)) {
		goto LO;
	}

	float yy = atof(input.c_str());

	std::cout << "***************************�ö���ʽ�ĸ�Ϊ***************************************" << std::endl;

	std::vector <std::pair<float, int>> ::iterator it;
	bool bFind = false;
	std::sort(vec.begin(), vec.end(), Merge());
	for (it = vec.begin(); it != vec.end(); ++it) {
		if (it->second == 0) {
			it->first -= yy;
			bFind = true;
			break;
		}
	}

	if (bFind == false) {
		std::pair<float, int>p;
		p.first = 0-yy;
		p.second = 0;
		vec.insert(vec.begin(), p);
	}

	std::vector <std::pair<float, int>> vdx1;
	for (it = vec.begin(); it != vec.end(); ++it) {
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
		f = getValue(vec, x0);
		fdx = getValue(vdx1, x0);
		x1 = x0 - f / fdx;
	} while (fabsf(x1-x0)>=1e-5);

	std::cout << x1 << std::endl;


	char num;

	while (true) {
		std::cin >> num;
		std::cin.get();
		if (std::isdigit(num)) {
			break;
		}
		else {
			std::cin.clear();
		}
	}
	int x = num - 0x30;
	return x;

}
// ��ʾ��ǰʱ��
void Printf_FiveMenu()
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::cout << "Current time: " << std::ctime(&now_c) << std::endl;
	return;
}
// ������Ķ���ʽ�ַ����ָ�ɸ���
//a0 + a1X + a2X^2 + a3X^3 + a4X^4 + a5X^5 + a6X^6 + ... + anX^n
std::vector<std::string> InsertVectorstring(std::string & strInPut)
{
	std::string polynomial = strInPut;
	polynomial.erase(std::remove(polynomial.begin(), polynomial.end(), ' '), polynomial.end());
	polynomial.erase(std::remove(polynomial.begin(), polynomial.end(), '\t'), polynomial.end());

	std::string strTmp = "";
	std::vector<std::string>vecstring = {};
	for (char c : polynomial) {
		if (c == '+') {
			vecstring.push_back(strTmp);
			strTmp = "";
		}
		else if (c == '-') {
			vecstring.push_back(strTmp);
			strTmp = "-";
		}
		else {
			strTmp += c;
		}
	}

	if (strTmp.length() > 0) {
		vecstring.push_back(strTmp);
	}
	return vecstring;
}
// �����ַ�����ȡ����ʽ��ϵ����ָ��

std::shared_ptr<std::pair<float, int>> GetPairFromString(std::string & strInput)
{
	std::string strTmp = strInput;
	std::pair<float, int> retP = {};
	if (strTmp.find('*') == std::string::npos && strTmp.find('x') == std::string::npos && strTmp.find('^') == std::string::npos) {
		retP.first = atof(strTmp.c_str());
		retP.second = 0;
	}
	else if (strTmp.find('*') != std::string::npos && strTmp.find('x') != std::string::npos && strTmp.find('^') == std::string::npos) {
		std::istringstream iss(strTmp);
		int num;
		iss >> num;
		retP.first = num;
		retP.second = 1;
	}
	else if (strTmp.find('*') == std::string::npos && strTmp.find('x') != std::string::npos && strTmp.find('^') == std::string::npos) {
		retP.first = 1;
		retP.second = 1;
	}
	else if (strTmp.find('*') != std::string::npos && strTmp.find('x') != std::string::npos && strTmp.find('^') != std::string::npos) {
		std::istringstream iss(strTmp);
		int num;
		iss >> num;
		retP.first = num;

		size_t iPos = strTmp.find('^');
		strTmp = strTmp.substr(iPos+1);
		retP.second = atoi(strTmp.c_str());
	}
	else if (strTmp.find('*') == std::string::npos && strTmp.find('x') != std::string::npos && strTmp.find('^') != std::string::npos) {
		retP.first = 1;
		size_t iPos = strTmp.find('^');
		strTmp = strTmp.substr(iPos + 1);
		retP.second = atoi(strTmp.c_str());
	}
	
	return std::make_shared<std::pair<float, int>>(retP.first, retP.second);
}
// ������ʽ�ַ���ת��Ϊϵ����ָ��������
std::vector<std::pair<float, int>> InsertVectorPair(std::vector<std::string> & vecstring)
{
	std::vector<std::pair<float, int>> vecPair{};
	if (vecstring.size() <= 0) {
		return vecPair;
	}

	std::vector<std::string>::iterator it;
	for (it = vecstring.begin(); it != vecstring.end(); ++it) {

		auto p = GetPairFromString(*it);
		vecPair.push_back(*p);
	}
	return vecPair;
}