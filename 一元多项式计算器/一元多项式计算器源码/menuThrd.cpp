#include"menuThrd.h"
#include"mainMenu.h"
#include"mainMenu.h"

// ����ʽ��������
float evepoly(float x, std::vector<float> xs, int d) {
	float result = 0.0;
	d = d - 1;
	for (int i = 0; i <= d; i++) {
		result += xs[i] * pow(x, i);
	}
	return result;
}
// ����ɭ�������ڶ����ּ���
float simpson_rule(float a, float b, int n, std::vector<float> xs, int d) {
	float h = (b - a) / n;
	float x = a;
	float fintegral = 0.0;
	for (int i = 0; i < n; i++) {
		double temp = (i == 0 || i == n - 1) ? evepoly(x, xs, d) : (i % 2 == 0) ? 2 * evepoly(x, xs, d) : 4 * evepoly(x, xs, d);
		fintegral += temp;
		x += h;
	}
	fintegral *= h / (3 * n);
	return fintegral;
}

// �Ը�������ʽ������

std::vector < std::pair<float, int>> getWF(std::vector < std::pair<float, int>> &v)
{
LO:
	std::cout << "***************************������΢������Ľ���*********************************" << std::endl;

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

	// ɾ��������

	std::vector < std::pair<float, int>> ::iterator it;
	std::vector <std::pair<float, int>> ret;

	std::sort(v.begin(), v.end(), MergeDec());
	for (it = v.begin(); it != v.end(); ++it) {
		if (it->second == 0) {
			v.erase(it);
			break;
		}
	}
	// �Զ���ʽ������
	for (it = v.begin(); it != v.end(); ++it) {
		std::pair<float, int>p;
		p.first = it->first * it->second;
		p.second = it->second - 1;
		ret.push_back(p);
	}
	return ret;

}
// �Ը�������ʽ��������
std::vector < std::pair<float, int>> getNtF(std::vector < std::pair<float, int>> &v) 
{
	std::vector < std::pair<float, int>> ::iterator it;
	std::vector < std::pair<float, int>> ret;

	std::sort(v.begin(), v.end(), MergeDec());
	// �Զ���ʽ��������
	for (it = v.begin(); it != v.end(); ++it) {
		std::pair<float, int>p;
		p.first = it->first / (it->second + 1);
		p.second = it->second + 1;
		ret.push_back(p);
	}

	return ret;
}

// �Ը�������ʽ�����󶨻���
std::string getF(std::vector < std::pair<float, int>> &v)
{
LO:
	std::cout << "***************************�����붨���ֵ�����***********************************" << std::endl << std::endl;
	std::cout << "***************************����������1,2����������ʾ����************************" << std::endl;
	std::string input;
	while (true) {
		std::cin >> input;
		if (input.empty()) {
			std::cin.clear();
			continue;
		}
		else {
			break;
		}
	}
	// ��������Ƿ�Ϸ�
	if (input.find(',') == std::string::npos) {
		goto LO;
	}

	size_t n = input.find(',');
	std::string strLeft = input.substr(0,n);
	std::string strRigt = input.substr(n + 1);
	if (::isFloat(strLeft) == false || ::isFloat(strRigt) == false) {
		goto LO;
	}

	float fLeft = atof(strLeft.c_str());
	float fRigt = atof(strRigt.c_str());

	if (fLeft > fRigt) {
		goto LO;
	}

	// �Ը�������ʽ�����󵼲����㶨����
	std::vector < std::pair<float, int>> ::iterator it;
	std::vector < std::pair<float, int>> ret;

	std::sort(v.begin(), v.end(), MergeDec());
	for (it = v.begin(); it != v.end();++it) {
		std::pair<float, int> p{};
		p.first =  it->first/(it->second + 1);
		p.second = it->second + 1;
		ret.push_back(p);
	}
	
	float sumLeft = 0, sumRight = 0 ,tmpf = 1;
	for (it = ret.begin(); it != ret.end(); ++it) {
		tmpf = 1;
		for (int i = 0; i < it->second; ++i) {
			tmpf *= fRigt;
		}
		tmpf *= it->first;
		sumRight += tmpf;
	}
	tmpf = 1;
	for (it = ret.begin(); it != ret.end(); ++it) {
		tmpf = 1;
		for (int i = 0; i < it->second; ++i) {
			tmpf *= fLeft;
		}
		tmpf *= it->first ;
		sumRight += tmpf;
	}

	float integral = sumRight - sumLeft;

	/*����ɭ�����󶨻���
	int dem = v.begin()->second;
	std::vector<float> fxs ;
	for (const auto& pair : v) {
		fxs.push_back(pair.first);
	}

	float integral = simpson_rule(fLeft, fRigt, 1000, fxs, dem);
	*/
	char buf[100];
	memset(buf, 0, sizeof buf);
	sprintf(buf, "%.2f", integral);
	
	return std::string(buf);
}