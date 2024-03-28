#include"mainMenu.h"
#include"menuOne.h"
#include"menuThrd.h"
const char *cMenu_top = (const char*)   "*************************** 欢迎使用多项式计算器 ******************************\n"
										"*************************** 请输入你所需要的功能 ******************************\n"
										"*************************** 0：退出系统          ******************************\n"
										"*************************** 1：多项式算术运算    ******************************\n"
										"*************************** 2：计算多项式在某点的函数值 ***********************\n"
										"*************************** 3：多项式积分或微分运算 ***************************\n"
										"*************************** 4：计算多项式在某点附近的根 ***********************\n"
										"*************************** 5：查看当前时间      ******************************\n";

//存储多项式的向量
std::vector<std::pair<float, int>> oneVect{};
std::vector<std::pair<float, int>> twoVect{};
// 显示主菜单
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
// 显示第一个菜单并进行多项式运算
int Printf_OneMenu()
{
	std::vector<std::pair<float, int>> ret{};
Label:
	std::cout << "***************************请输入第一个多项式***********************************" << std::endl ;
	oneVect.clear();
	std::string first_input ="";
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	oneVect = InsertVectorPair(v1);
	

Label1:
	std::cout << "***************************请输入第二个多项式***********************************" << std::endl;
	        

	std::string second_input ="";
	std::getline(std::cin, second_input);
	std::vector<std::string> v2 = InsertVectorstring(second_input);
	if (v2.empty()) {
		goto Label1;
	}
	twoVect = InsertVectorPair(v2);


Label2:
	std::cout << "***************************请输入你所需要的运算*********************************" << std::endl;
	std::cout << "*************************** 0.加法             *********************************" << std::endl;
	std::cout << "*************************** 1.减法             *********************************" << std::endl;
	std::cout << "*************************** 2.乘法             *********************************" << std::endl;
	std::cout << "*************************** 3.除法             *********************************" << std::endl;
	std::cout << "*************************** 4.取余             *********************************" << std::endl;
	std::cout << "*************************** 5.返回主菜单       *********************************" << std::endl;
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
// 检查是否输入正确
bool CheckIsOk()
{
	return 1;
}
// 关闭程序
#include <Windows.h>
void Printf_ZeroMenu()
{
	HWND hWnd = ::GetForegroundWindow();
	if (nullptr != hWnd) {
		SendMessage(hWnd, WM_CLOSE, 0, 0);
	}
}
// 显示第二个菜单并进行相关计算
int Printf_TwoMenu()
{
Label:
	std::cout << "***************************请输入多项式*****************************************" << std::endl;
	std::vector <std::pair<float, int>> vec;

	std::string first_input;
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	vec = InsertVectorPair(v1);

	std::cout << "***************************请输入x的值******************************************" << std::endl;
	
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

	std::cout << "***************************该点y的值********************************************" << std::endl;
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
	std::cout << "***************************输入0，返回主菜单************************************" << std::endl;

	

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
// 显示第三个菜单并进行相关计算
int Printf_ThirdMenu()
{
Label:
	std::cout << "***************************请输入多项式*****************************************" << std::endl;
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
	std::cout << "***************************请输入运算功能***************************************" << std::endl;
	std::cout << "***************************0.微分***********************************************" << std::endl;
	std::cout << "***************************1.不定积分*******************************************" << std::endl;
	std::cout << "***************************2.定积分*********************************************" << std::endl;
	std::cout << "***************************3.返回主菜单*****************************************" << std::endl;

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
// 检查字符串是否为浮点数

bool isFloat(const std::string& str) {
	std::stringstream ss(str);
	float f;
	ss >> f;
	if (ss.fail()) {
		return false;
	}
	return true;
}
// 获取多项式在某点的值

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
// 显示第四个菜单并进行相关计算
int Printf_FourMenu()
{
Label:
	std::cout << "***************************请输入多项式*****************************************" << std::endl;
	std::vector <std::pair<float, int>> vec;

	std::string first_input;
	std::getline(std::cin, first_input);
	std::vector<std::string> v1 = InsertVectorstring(first_input);
	if (v1.empty()) {
		goto Label;
	}
	vec = InsertVectorPair(v1);

LO:
	std::cout << "***************************请输入y的值******************************************" << std::endl;
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

	std::cout << "***************************该多项式的根为***************************************" << std::endl;

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
// 显示当前时间
void Printf_FiveMenu()
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::cout << "Current time: " << std::ctime(&now_c) << std::endl;
	return;
}
// 将输入的多项式字符串分割成各项
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
// 根据字符串获取多项式的系数和指数

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
// 将多项式字符串转换为系数和指数的数组
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