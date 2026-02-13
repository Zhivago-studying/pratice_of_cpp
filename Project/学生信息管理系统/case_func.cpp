#include "case_func.h"
#define _CRT_SECURE_NO_WARNINGS

void case_1(StudentManager &sm) {
	Student stu;
	char stu_name[32];
	char  stu_gender[8];
	int stu_id;
	int stu_age;
	float stu_score[3];
	cout << "请输入学生信息:" << endl;
	cout << "姓名: ";
	cin >> stu_name;
	cout << "年龄: ";
	cin >> stu_age;
	cout << "性别: ";
	cin >> stu_gender;
	cout << "学号: ";
	cin >> stu_id;
	cout << "成绩: ";
	cin >> stu_score[0];
	cin >> stu_score[1];
	cin >> stu_score[2];
	stu.set_name(stu_name);
	stu.set_gender(stu_gender);
	stu.set_age(stu_age);
	stu.set_id(stu_id);
	stu.set_score(stu_score);
	sm.addstudent(stu);
}

void case_2(StudentManager &sm) {
	sm.show_all_info();
}

void case_3(StudentManager &sm) {
	int id;
	cout << "请输入学号: ";
	cin >> id;
	Student * ptr = sm.search_stu(id);
	if (ptr == nullptr) {
		cout << "没有匹配的学生" << endl;
	}
	else {
		ptr->showInfo();
	}
}

void case_4(StudentManager& sm) {
	int id;
	cout << "请输入学号: ";
	cin >> id;
	if (!sm.delete_stu(id)) {
		cout << "没有匹配的学号" << endl;
	}
	else {
		cout << "删除成功" << endl;
	}
}

void case_5(StudentManager& sm) {
	sm.change_stu_info();
}

void case_6(StudentManager& sm) {
	sm.read_data_from_text();
}

void case_7(StudentManager& sm) {
	sm.write_info_to_file();
	cout << "已将全部学生信息写入到文件: \"student.txt\" " << endl;
}