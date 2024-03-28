#include"menuOne.h"
#include"mainMenu.h"


// 函数：向量相加

std::vector<std::pair<float, int>>  add(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2)
{
	std::vector<std::pair<float, int>> mergedVec = {};
	std::vector<std::pair<float, int>> ::iterator it;
	std::map<float, float> sumMap = {};

	for (const auto& p : v1) {
		sumMap[p.second] = p.first;
	}
	for (const auto& p : v2) {
		sumMap[p.second] += p.first;
	}

	for (const auto& kv : sumMap) {
		if (kv.second == 0 && kv.first != 0) {
			;
		}
		else{
			mergedVec.push_back(std::make_pair(kv.second, kv.first));
		}
		
	}

	return (mergedVec);
}

// 函数：向量相减

std::vector<std::pair<float, int>>  sub(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2)
{
	std::vector<std::pair<float, int>> mergedVec;
	std::vector<std::pair<float, int>> ::iterator it;
	std::map<float, float> sumMap;

	for (const auto& p : v1) {
		sumMap[p.second] = p.first;
	}
	for (const auto& p : v2) {
		sumMap[p.second] -= p.first;
	}

	for (const auto& kv : sumMap) {
		if (kv.second == 0 && kv.first != 0) {
			;
		}
		else {
			mergedVec.push_back(std::make_pair(kv.second, kv.first));
		}
	}
	return (mergedVec);
}
// 函数：向量相乘
std::vector<std::pair<float, int>>  mul(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2)
{
	std::vector<std::pair<float, int>> ret{};
	std::vector<std::pair<float, int>>::iterator it1, it2;
	for (it1 = v1.begin(); it1 != v1.end(); ++it1) {
		std::pair<float, int> p = {};
		for (it2 = v2.begin(); it2 != v2.end(); ++it2) {
			float xsf = it1->first;
			int   xmc = it1->second;

			float new_xsf = xsf * it2->first;
			int   new_xmc = xmc + it2->second;

			p.first = new_xsf;
			p.second = new_xmc;
			ret.push_back(p);
		}
	}
	
	if (ret.size() <= 0) return ret;
	std::sort(ret.begin(), ret.end(), Merge());
	std::vector<std::pair<float, int>> result;
	for (auto it = ret.begin(); it != ret.end(); ++it) {
		if (result.empty() || result.back().second != it->second) {
			result.push_back(*it);
		}
		else {
			result.back().first += it->first;
		}
	}
	
	return (result);
}

// 函数：向量相减（扩展版本）


std::vector<std::pair<float, int>> subEx(std::vector<std::pair<float, int>> be_s, std::vector<std::pair<float, int>> s) {
	std::vector<std::pair<float, int>> ans;
	std::pair<float, int> temp;
	int i = 0, j = 0;
	while (i < be_s.size() && j < s.size()) {
		if (s[j].second > be_s[i].second) {
			temp.first = be_s[i].first;
			temp.second = be_s[i].second;
			ans.push_back(temp);
			i++;
		}
		else if (s[j].second == be_s[i].second) {
			temp.first = be_s[i].first - s[j].first;
			temp.second = s[j].second;
			if (temp.first != 0)
				ans.push_back(temp);
			i++; j++;
		}
	}
	return ans;
}

// 函数：向量相乘（扩展版本）
std::vector<std::pair<float, int>> mulEx(std::vector<std::pair<float, int>> be_m, std::pair<float, int> m) {
	std::vector<std::pair<float, int>> ans = be_m;
	for (int i = 0; i < ans.size(); i++) {
		ans[i].first *= m.first;
		ans[i].second += m.second;
	}
	return ans;
}

// 函数：向量相除
std::vector<std::pair<float, int>>  div(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2)
{
	std::sort(v1.begin(), v1.end(), MergeDec());
	std::sort(v2.begin(), v2.end(), MergeDec());

	
	std::vector<std::pair<float, int>> yushu ,ans ,di ;
	float shang = 0;
	int   mic = 0;
	yushu = v1;
	std::pair<float, int >pp;
	int iMaxMic = v1.begin()->second;
	
	
	std::vector<std::pair<float, int>> ve;
LLOO:
	std::vector<std::pair<float, int>>::iterator it1, it2, it22;

	for (it1 = v1.begin(); it1 != v1.end(); ++it1) {
		for (it2 = v2.begin(); it2 != v2.end(); ++it2) {
			std::pair<float, int> p;
			if (it1->second < it2->second) {
				goto Ext;
			}

			p.first = it1->first / it2->first;
			p.second = it1->second - it2->second;

			ans.push_back(p);
			ve.clear();
			for (it22 = v2.begin(); it22 != v2.end(); ++it22) {
				std::pair<float, int> pp;
				pp.first = it22->first * p.first;
				pp.second = it22->second + p.second;
				ve.push_back(pp);
			}
			yushu.clear();
			yushu = sub(v1, ve);
			v1.clear();
			v1 = yushu;
			std::sort(v1.begin(), v1.end(), MergeDec());
			goto LLOO;
		}
	}

Ext:
	return yushu;
}

// 函数：向量求模
std::vector<std::pair<float, int>>  mod(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2)
{
	std::sort(v1.begin(), v1.end(), MergeDec());
	std::sort(v2.begin(), v2.end(), MergeDec());


	std::vector<std::pair<float, int>> yushu, ans, di;
	float shang = 0;
	int   mic = 0;
	yushu = v1;
	std::pair<float, int >pp;
	
	std::vector<std::pair<float, int>> ve;
LLOO:
	std::vector<std::pair<float, int>>::iterator it1, it2, it22;

	for (it1 = v1.begin(); it1 != v1.end(); ++it1) {
		for (it2 = v2.begin(); it2 != v2.end(); ++it2) {
			std::pair<float, int> p;
			if (it1->second < it2->second) {
				goto Ext;
			}

			p.first = it1->first / it2->first;
			p.second = it1->second - it2->second;

			ans.push_back(p);
			ve.clear();
			for (it22 = v2.begin(); it22 != v2.end(); ++it22) {
				std::pair<float, int> pp;
				pp.first = it22->first * p.first;
				pp.second = it22->second + p.second;
				ve.push_back(pp);
			}
			yushu.clear();
			yushu = sub(v1, ve);
			v1.clear();
			v1 = yushu;
			std::sort(v1.begin(), v1.end(), MergeDec());
			goto LLOO;
		}
	}

Ext:
	return ans;
}
// 函数：判断两个浮点数是否相等
bool isEqual(float a, float b, float epsilon = 0.0001f) {
	return std::abs(a - b) < epsilon;
}


std::string  vecToString(std::vector<std::pair<float, int>> &vec)
{
	std::vector<std::pair<float, int>> ::iterator  it;

	std::string strRet = "";
	std::sort(vec.begin(), vec.end(), Merge());
	char buf[200] = {};

	for (it = vec.begin(); it != vec.end(); ++it) {
		if (it->second == 0) {
			sprintf(buf, "%.2f", it->first);
			strRet += buf;
		}
		else {
			if (it->first < 0) strRet += '-';
			else if (it->first > 0) strRet += '+';

			if (isEqual(it->first, 1)) {
				strRet += 'x';
			}else {
				sprintf(buf, "%.2f", fabs(it->first));
				strRet += buf;
				strRet += "*x";
			}

			if (it->second > 1) {
				sprintf(buf, "^%d", it->second); 
				strRet += buf;
			}

		}
	}
	if (strRet[0] == '+') {
		strRet = strRet.substr( 1);
	}

	return strRet;
}