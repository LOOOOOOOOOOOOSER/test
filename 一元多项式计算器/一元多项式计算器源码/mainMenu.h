#pragma once

#include<iostream>
#include<sstream>
#include<vector>
#include<cctype>
#include<string>
#include<functional>
#include <regex>
#include <chrono> 
#include <numeric>  
#include <cmath>
#include <limits> 



extern const char *cMenu_top;

extern std::vector<std::pair<float, int>> oneVect;
extern std::vector<std::pair<float, int>> twoVect;

int Printf_MainMenu();
void Printf_ZeroMenu();
int  Printf_OneMenu();
int  Printf_TwoMenu();
int  Printf_ThirdMenu();
int  Printf_FourMenu();
void Printf_FiveMenu();
bool isFloat(const std::string& str);
   
std::vector<std::string> InsertVectorstring(std::string & strInPut);
std::vector<std::pair<float, int>> InsertVectorPair(std::vector<std::string> & vecstring);
std::shared_ptr<std::pair<float, int>> GetPairFromString(std::string & strInput);

float getValue(std::vector <std::pair<float, int>> &vec, float x);


struct Merge {
	bool operator()(const std::pair<float, int>& a, const std::pair<float, int>& b) {
		return a.second < b.second;
	}
	void merge(std::pair<float, int>& a, const std::pair<float, int>& b) {
		a.first += b.first;
	}
};

struct MergeDec {
	bool operator()(const std::pair<float, int>& a, const std::pair<float, int>& b) {
		return a.second > b.second;
	}
	void merge(std::pair<float, int>& a, const std::pair<float, int>& b) {
		a.first += b.first;
	}
};

