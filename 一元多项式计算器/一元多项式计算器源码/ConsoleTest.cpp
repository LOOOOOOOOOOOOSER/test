// ConsoleTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma once
#include <iostream>
#include"mainMenu.h"



int main()
{
MAIN_LABEL:   // 主标签，用于跳转
	int iSel = Printf_MainMenu();// 调用Printf_MainMenu函数，并将返回值赋给iSel变量
	switch (iSel){  // 根据iSel的值进行选择
	case 0:
		Printf_ZeroMenu();//执行Printf_ZeroMenu函数
		break;
	case 1:
		if (5 == Printf_OneMenu()) {// 如果Printf_OneMenu函数的返回值等于5
			goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		}
		goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		break;
	case 2:
		if (0 == Printf_TwoMenu()) {// 如果Printf_TwoMenu函数的返回值等于0
			goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		}
		goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		break;
	case 3:
		if (3 == Printf_ThirdMenu()) {// 如果Printf_ThirdMenu函数的返回值等于3
			goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		}
		goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		break;
	case 4:
		if (0 == Printf_FourMenu()) {// 如果Printf_FourMenu函数的返回值等于0
			goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		}
		goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
		break;
	case 5:
		Printf_FiveMenu();// 执行Printf_FiveMenu函数
		goto MAIN_LABEL;// 跳转到MAIN_LABEL标签处
	default:
		break;
	}
	return 0;// 返回0，表示程序正常结束
}

