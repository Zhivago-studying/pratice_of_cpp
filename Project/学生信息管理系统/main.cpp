#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "case_func.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
	//菜单功能实现
	int choice = -1;
	bool if_back_menu = false;
	StudentManager sm(5,"students.txt","students.dat");
	do {
		cout << "========学生信息管理系统========" << endl;
		cout << " 1.添加学生" << endl;
		cout << " 2.显示所有学生" << endl;
		cout << " 3.按学号查找学生" << endl;
		cout << " 4.按学号删除学生" << endl;
		cout << " 5.修改学生信息" << endl;
		cout << " 6.从文本文件加载数据" << endl;
		cout << " 7.保存到文本文件" << endl;
		cout << " 0.退出系统" << endl;
		cout << "================================" << endl;
		cout << "请输入: ";
		cin >> choice;
		switch (choice) {
		case 0:
			if_back_menu = true;
			cout << "已退出！" << endl;
			choice = -1;
			return 0;
		case 1:
			case_1(sm);
			choice = -1;
			break;
		case 2:
			case_2(sm);
			choice = -1;
			break;
		case 3:
			case_3(sm);
			choice = -1;
			break;
		case 4:
			case_4(sm);
			choice = -1;
			break;
		case 5:
			case_5(sm);
			choice = -1;
			break;
		case 6:
			case_6(sm);
			choice = -1;
			break;
		case 7:
			case_7(sm);
			choice = -1;
			break;
		default:
			cout << "输入无效，请重新输入" << endl;
			break;
		}
	} while (!if_back_menu);
	
	system("pause");
	return 0;
}