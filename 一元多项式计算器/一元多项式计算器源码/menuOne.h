#pragma once
#include<string>
#include<vector>
#include<map>

/***********************************************************************/
std::vector<std::pair<float, int>>  add(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2);
std::vector<std::pair<float, int>>  sub(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2);
std::vector<std::pair<float, int>>  mul(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2);
std::vector<std::pair<float, int>>  div(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2);
std::vector<std::pair<float, int>>  mod(std::vector<std::pair<float, int>>v1, std::vector<std::pair<float, int>>v2);

std::string  vecToString(std::vector<std::pair<float, int>> &vec);

