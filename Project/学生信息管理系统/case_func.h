#pragma once
/*
	main.cpp中各类菜单功能函数
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "student.h"
using namespace std;

/*
	功能：		添加学生到数组中
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_1(StudentManager &sm);

/*
	功能：		显示所有学生信息
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_2(StudentManager &sm);

/*
	功能：		按照学号查找学生
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_3(StudentManager& sm);

/*
	功能：		按照学号删除学生
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_4(StudentManager& sm);

/*
	功能：		修改学生信息，按照姓名或者学号查找
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_5(StudentManager& sm);

/*
	功能：		从文件读取数据并添加到数组中
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_6(StudentManager& sm);

/*
	功能：		将学生信息写入文件
				格式如下：
				1001 张三 20 男 89.5 78.0 90.0
	参数：		学生管理类StudentManager
	返回值：	无
*/
void case_7(StudentManager& sm);