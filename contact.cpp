#include <iostream>
#include <string>
using namespace std;
/*
	---------------------通讯录管理系统---------------------
	通讯录管理系统实现的功能：
	1.添加联系人：向通讯录中添加新人，信息包括：姓名、性别、年龄、联系电话，最多纪录20人
	2.显示联系人：显示通讯录中所有联系人的信息
	3.删除联系人：按照姓名删除指定联系人
	4.查找联系人：按照姓名查找指定联系人
	5.修改联系人：按照姓名重新修改指定联系人
	6.清空联系人：清空通讯录
	7.退出通讯录：退出通讯录
*/
struct contact {
	string name;	//联系人姓名
	string gender;	//联系人性别
	int age;		//联系人年龄
	string phonenumber;//联系人电话号码
};
struct bulm {
	int contact_num;	//通讯录总人数
	contact menu[20];	//通讯录里每个联系人的结构体，最多20个人
};
//添加联系人，在通讯录末尾添加
void add_contact(bulm * book) {
	if (book->contact_num >= 20) {
		cout << "通讯录已满！" << endl;
	}
	else {

		//联系人数量加一
		book->contact_num++;

		//输入联系人信息
		cout << "请输入联系人信息:" << endl;
		cout << "姓名:";
		cin >> book->menu[book->contact_num - 1].name;
		cout << "性别:";
		cin >> book->menu[book->contact_num - 1].gender;
		cout << "年龄:";
		cin >> book->menu[book->contact_num - 1].age;
		cout << "电话号码:";
		cin >> book->menu[book->contact_num - 1].phonenumber;

		cout << "添加成功!" << endl;
	}
}
//显示联系人
void show_contact(const bulm * book) {
	cout << "通讯录总人数:" << book->contact_num << endl;
	//遍历联系人信息并显示
	for (int i = 0; i <= book->contact_num - 1; i++) {
		cout << "姓名:" << book->menu[i].name
			<< "\t性别:" << book->menu[i].gender
			<< "\t年龄:" << book->menu[i].age
			<< "\t电话:" << book->menu[i].phonenumber << endl;
	}
}
//删除联系人
void del_contact(bulm* book) {
	string name;
	cout << "请输入要删除的联系人姓名：" << endl;
	cin >> name;
	for (int i = 0; i <= book->contact_num - 1; i++) {
		if (book->menu[i].name == name) {
			//从第i个联系人开始，将后一个联系人的信息覆盖到前一个
			for (int j = i; j < book->contact_num - 1; j++) {
				book->menu[j].name = book->menu[j + 1].name;
				book->menu[j].age = book->menu[j + 1].age;
				book->menu[j].gender = book->menu[j + 1].gender;
				book->menu[j].phonenumber = book->menu[j + 1].phonenumber;
			}
			//删除最后一个
			book->contact_num--;
			//跳出for循环
			break;
		}
	}
	cout << "删除成功！" << endl;
}
//查找联系人
void find_contact(bulm* book) {
	string name;
	cout << "请输入要查找的联系人姓名:" << endl;
	cin >> name;
	for (int i = 0; i <= book->contact_num - 1; i++) {
		if (book->menu[i].name == name) {
			//找到该联系人了，打印联系人信息并退出for循环
			cout << "姓名:" << book->menu[i].name
				<< "\t性别:" << book->menu[i].gender
				<< "\t年龄:" << book->menu[i].age
				<< "\t电话:" << book->menu[i].phonenumber << endl;
			break;
		}
	}
}
//修改联系人
void modify_contact(bulm* book) {
	string name;
	string to_modify;
	bool if_find = false;	//标记是否找到联系人
	cout << "请输入要修改的联系人姓名:" << endl;
	cin >> name;
	for (int i = 0; i <= book->contact_num - 1; i++) {
		if (book->menu[i].name == name) {
			//找到该联系人了，打印修改联系人信息并退出for循环
			if_find = true;
			cout << "姓名:" << book->menu[i].name
				<< "\t性别:" << book->menu[i].gender
				<< "\t年龄:" << book->menu[i].age
				<< "\t电话:" << book->menu[i].phonenumber << endl;
			cout << "请输入要修改的内容(姓名、性别、年龄、电话号码、退出):" << endl;
			cin >> to_modify;
			if (to_modify == "姓名") {
				string new_name;
				cout << "联系人新姓名:";
				cin >> new_name;
				book->menu[i].name = new_name;
			}
			else if (to_modify == "性别") {
				string new_gender;
				cout << "联系人新性别:";
				cin >> new_gender;
				book->menu[i].gender = new_gender;
			}
			else if (to_modify == "年龄") {
				int new_age;
				cout << "联系人新年龄:";
				cin >> new_age;
				book->menu[i].age = new_age;
			}
			else if (to_modify == "电话号码") {
				string new_phone_number;
				cout << "联系人新号码:";
				cin >> new_phone_number;
				book->menu[i].phonenumber = new_phone_number;
			}
			else if (to_modify == "退出") {
				cout << "已退出！" << endl;
				break;
			}
			cout << "姓名:" << book->menu[i].name
				<< "\t性别:" << book->menu[i].gender
				<< "\t年龄:" << book->menu[i].age
				<< "\t电话:" << book->menu[i].phonenumber << endl;
			cout << "修改成功!" << endl;
			break;
		}
	}
	//没有找到该联系人
	if (!if_find) {
		cout << "联系人不存在！" << endl;
	}
	
}
//清空通讯录
void clean_contact(bulm* book) {
	string input_letter;
	cout << "是否确定清空通讯录？（是：Y	否：N）" << endl;
	cin >> input_letter;
	if (input_letter == "Y") {
		book->contact_num = 0;
		cout << "清除成功！" << endl;
	}
}
int main() {
	cout << "----进入通讯录----" << endl;
	bulm bulm1 = {0,};	//定义通讯录，目前是0个联系人
	bool back_up = false;	//退出标记
	while (!back_up) {
		int num = 0;			//选项
	
		cout << "======请选择要进行的操作：======" << endl;
		cout << "1.添加联系人" << endl;
		cout << "2.显示联系人" << endl;
		cout << "3.删除联系人" << endl;
		cout << "4.查找联系人" << endl;
		cout << "5.修改联系人" << endl;
		cout << "6.清空联系人" << endl;
		cout << "7.退出通讯录" << endl;

		//选择要进行的操作
		cin >> num;
		switch (num) {
			case 1:
				//添加联系人
				add_contact(&bulm1);
				break;
			case 2:
				//显示联系人
				cout << "------------联系人------------" << endl;
				show_contact(&bulm1);
				break;
			case 3:
				//删除联系人
				del_contact(&bulm1);
				break;
			case 4:
				//查找联系人
				find_contact(&bulm1);
				break;
			case 5:
				//修改联系人
				modify_contact(&bulm1);
				break;
			case 6:
				//清空联系人
				clean_contact(&bulm1);
				break;
			case 7:
				//退出通讯录
				cout << "已退出" << endl;
				back_up = true;
				break;
			default:
				//其他输入
				break;
		}

	}
	system("pause");
	return 0;
}