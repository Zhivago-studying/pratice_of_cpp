#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

/*
    学生类
*/
class Student {
protected:
    int id;
    char name[32];
    int age;
    char gender[8];
    float score[3];

public:
    /* 默认构造 */
    Student() : id(0), age(0) {
        memset(name, 0, sizeof(name));
        memset(gender, 0, sizeof(gender));
        for (int i = 0; i < 3; i++)
            score[i] = 0.0f;
    }

    /* 带参构造 */
    Student(const char* name, int id, int age,
        const char* gender, const float score[3])
        : id(id), age(age)
    {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';

        strncpy(this->gender, gender, sizeof(this->gender) - 1);
        this->gender[sizeof(this->gender) - 1] = '\0';

        for (int i = 0; i < 3; i++)
            this->score[i] = score[i];
    }

    /* 计算平均分 */
    float cal_average_score() const {
        float sum = 0.0f;
        for (int i = 0; i < 3; i++)
            sum += score[i];
        return sum / 3.0f;
    }

    /* 显示信息 */
    void showInfo() const {
        cout << "姓名: " << name
            << "\t学号: " << id
            << "\t性别: " << gender
            << "\t年龄: " << age
            << "\t成绩: "
            << score[0] << " "
            << score[1] << " "
            << score[2]
            << "\t平均: "
            << cal_average_score()
            << endl;
    }

    /* setter */
    void set_name(const char* name) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }

    void set_gender(const char* gender) {
        strncpy(this->gender, gender, sizeof(this->gender) - 1);
        this->gender[sizeof(this->gender) - 1] = '\0';
    }

    void set_id(int id) { this->id = id; }
    void set_age(int age) { this->age = age; }

    void set_score(const float score[3]) {
        for (int i = 0; i < 3; i++)
            this->score[i] = score[i];
    }

    /* getter */
    const char* get_name() const { return name; }
    const char* get_gender() const { return gender; }
    int get_id() const { return id; }
    int get_age() const { return age; }
    const float* get_score() const { return score; }
};


/*
    学生管理类
*/
class StudentManager {
protected:
    Student* students;
    int size;
    int capacity;
    string fileText;
    string fileBin;

public:
    /* 默认构造 */
    StudentManager()
        : size(0), capacity(100),
        fileText("students.txt"),
        fileBin("students.dat")
    {
        students = new Student[capacity];
    }

    /* 带参构造 */
    StudentManager(int capacity,
        const string& fileText,
        const string& fileBin)
        : size(0), capacity(capacity),
        fileText(fileText), fileBin(fileBin)
    {
        students = new Student[capacity];
    }

    /* 析构 */
    ~StudentManager() {
        delete[] students;
        students = nullptr;
    }

    /* 添加学生 */
    void addstudent(const Student& stu) {

        // 查重（只检查已有元素）
        for (int i = 0; i < size; i++) {
            if (students[i].get_id() == stu.get_id()) {
                cout << "学号重复！" << endl;
                return;
            }
        }

        // 扩容
        if (size >= capacity) {
            capacity *= 2;
            Student* tmp = new Student[capacity];

            for (int i = 0; i < size; i++)
                tmp[i] = students[i];

            delete[] students;
            students = tmp;
        }

        students[size++] = stu;
        cout << "添加成功!" << endl;
    }

    /*显示所有学生信息*/
    void show_all_info() const{
        cout << "-----------------------学生信息-----------------------" << endl;
        cout << "学生总人数: " << size << endl;
        cout << "姓名"
            << "\t性别"
            << "\t年龄"
            << "\t学号"
            << "\t三门成绩" << "\t平均成绩" << endl;

        for (int i = 0; i < size; i++) {
            cout << students[i].get_name() << "\t"
                << students[i].get_gender() << "\t"
                << students[i].get_age() << "\t"
                << students[i].get_id() << "\t"
                << students[i].get_score()[0] << " " << students[i].get_score()[1]<< " "<< students[i].get_score()[2] << "\t"
                << students[i].cal_average_score() << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }

    /*按照学号查找学生*/
    Student* search_stu(int id) const {
        for (int i = 0; i < size; i++) {
            if (students[i].get_id() == id) {
                //找到该学生，返回对象
                return &students[i];
            }
        }
        return nullptr;
    }

    /*按照学号删除学生*/
    bool delete_stu(int id) {
        for (int i = 0; i < size; i++) {
            if (students[i].get_id() == id) {
                //删除当前学生
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                return true;
            }
        }
        //没有找到匹配的学生
        return false;
    }

    /*修改学生信息*/
    void change_stu_info() {
        bool is_real_back = false;
        while (!is_real_back) {
            cout << "请选择要输入的学生信息:(1.按姓名查找   2.按学号查找) ";
            int num;
            cin >> num;
            if (num == 1) {
                //姓名
                cout << "姓名: ";
                char name[32];
                cin >> name;
                int stu_num = -1;
                for (int i = 0; i < size; i++) {
                    if (strcmp(students[i].get_name(), name) == 0) {
                        //找到该学生，记录顺序👌，退出for循环
                        students[i].showInfo();
                        stu_num = i;
                        break;
                    }
                }
                if (stu_num == -1) {
                    //没有找到学生
                    cout << "没有匹配的学生姓名" << endl;
                }
                else {
                    change_info_menu(stu_num);
                    is_real_back = true;
                }
            }
            else if (num == 2) {
                //学号
                cout << "学号: ";
                int id;
                cin >> id;
                int stu_num = -1;
                for (int i = 0; i < size; i++) {
                    if (students[i].get_id() == id) {
                        //找到该学生，记录顺序👌，退出for循环
                        students[i].showInfo();
                        stu_num = i;
                        break;
                    }
                }
                if (stu_num == -1) {
                    //没有找到学生
                    cout << "没有匹配的学生学号" << endl;
                }
                else {
                    change_info_menu(stu_num);
                    is_real_back = true;
                }
            }
            else {
                cout << "输入无效，请重新输入..." << endl;
            }
        }
    }

    /*从文本文件加载数据*/
    void read_data_from_text() {
        /*
            格式：1001 张三 20 男 89.5 78.0 90.0
        */
        ifstream ifs;
        ifs.open(this->fileText, ios::in);
        if (!ifs.is_open()) {
            cout << "文件打开失败！" << endl;
            return;
        }
        int id;
        char name[32],gender[8];
        int age;
        float score[3];

        while (ifs >> id >> name >> age >> gender >> score[0] >> score[1] >> score[2]) {
            Student stu(name, id, age, gender, score);
            addstudent(stu);
        }
        ifs.close();
        cout << "文件加载完毕！" << endl;
    }

    /*文件写入学生信息*/
    void write_info_to_file() const{
        ofstream ofs;
        ofs.open(this->fileText, ios::out);
        for (int i = 0; i < size; i++) {
            ofs << students[i].get_id() << "\t" << students[i].get_name() << "\t" << students[i].get_age()
                << "\t" << students[i].get_score()[0] << " " << students[i].get_score()[1] << " " << students[i].get_score()[2] << endl;
        }
        ofs.close();
    }

protected:
    //修改学生信息菜单函数
    void change_info_menu(int stu_num) {
        //开始修改菜单
        int cnt = -1;
        while (cnt != 0) {
            cout << "请选择要修改的信息(1.姓名 2.学号 3.年龄 4.性别 5.成绩1 6.成绩2 7.成绩3 0.退出): ";
            cin >> cnt;
            switch (cnt) {
            case 0:
                cout << "已退出" << endl;
                break;
            case 1:
                char new_name[32];
                cout << "请输入(新姓名): ";
                cin >> new_name;
                students[stu_num].set_name(new_name);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            case 2:
                int new_id;
                cout << "请输入(新学号): ";
                cin >> new_id;
                students[stu_num].set_id(new_id);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            case 3:
                int new_age;
                cout << "请输入(新年龄): ";
                cin >> new_age;
                students[stu_num].set_age(new_age);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            case 4:
                char new_gender[8];
                cout << "请输入(新性别): ";
                cin >> new_gender;
                students[stu_num].set_gender(new_gender);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            case 5:
                float new_score1[3];
                cout << "请输入(新成绩1): ";
                cin >> new_score1[0];
                new_score1[1] = students[stu_num].get_score()[1];
                new_score1[2] = students[stu_num].get_score()[2];
                students[stu_num].set_score(new_score1);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            case 6:
                float new_score2[3];
                cout << "请输入(新成绩2): ";
                cin >> new_score2[1];
                new_score2[0] = students[stu_num].get_score()[0];
                new_score2[2] = students[stu_num].get_score()[2];
                students[stu_num].set_score(new_score2);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            case 7:
                float new_score3[3];
                cout << "请输入(新成绩3): ";
                cin >> new_score3[2];
                new_score3[0] = students[stu_num].get_score()[0];
                new_score3[1] = students[stu_num].get_score()[1];
                students[stu_num].set_score(new_score3);
                cout << "设置成功! " << endl;
                cnt = -1;
                break;
            default:
                cout << "输入无效，请重新输入..." << endl;
                cnt = -1;
                break;
            }
        }
    }
};

	