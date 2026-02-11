#include <iostream>
#include <string>
using namespace std;
//抽象基类，Employee
class Employee {
protected:
	//成员
	string name;
	int id;

	//行为
	//有参构造函数
	Employee(string name,int id) {
		this->name = name;
		this->id = id;
	}
public:
	virtual int calcSalary() = 0;	//计算薪资
	virtual void showInfo() = 0;	//显示员工信息
	virtual ~Employee() = 0;		//基类纯虚析构函数
};
//基类纯虚析构函数定义
Employee::~Employee() {
	return;
}
/*
	派生员工类型
	worker		普通员工	固定工资
	Engineer	技术人员	基础工资 + 项目奖金
	Manager		经理		基础工资 + 团队提成
*/

class worker :public Employee {
public:
	//行为
	//有参构造函数
	worker(string name,int id,int base_salary): Employee(name,id){
		this->base_salary = base_salary;
	}
	/*
		对属性的操作
	*/
	//设置固定工资
	void set_base_salary(int money) {
		this->base_salary = money;
	}
	//获取固定工资
	int get_base_salary() {
		return this->base_salary;
	}
	//计算薪资
	int calcSalary() {
		return base_salary;
	}
	//显示员工信息
	void showInfo() {
		cout << "姓名: " << this->name << "\tID: " << this->id << "\t薪资: " << this->calcSalary() << endl;
	}
protected:
	//成员
	int base_salary;
};

class Engineer :public Employee {
public:
	//行为
	//有参构造函数
	Engineer(string name, int id, int base_salary,int project_reward): Employee(name, id){
		this->base_salary = base_salary;
		this->project_reward = project_reward;
	}
	/*
		对属性的操作
	*/
	//设置固定工资
	void set_base_salary(int money) {
		this->base_salary = money;
	}
	//获取固定工资
	int get_base_salary() {
		return this->base_salary;
	}
	//设置项目奖金
	void set_project_reward(int money) {
		this->project_reward = money;
	}
	//获取项目奖金
	int get_project_reward() {
		return this->project_reward;
	}
	//计算薪资
	int calcSalary() {
		return base_salary + project_reward;
	}
	//显示员工信息
	void showInfo() {
		cout << "姓名: " << this->name << "\tID: " << this->id << "\t薪资: " << this->calcSalary() << endl;
	}
protected:
	//成员
	int base_salary;
	int project_reward;
};

class Manager :public Employee {
public:
	//行为
	//有参构造函数
	Manager(string name, int id, int base_salary, int team_reward) : Employee(name, id) {
		this->base_salary = base_salary;
		this->team_reward = team_reward;
	}
	/*
		对属性的操作
	*/
	//设置固定工资
	void set_base_salary(int money) {
		this->base_salary = money;
	}
	//获取固定工资
	int get_base_salary() {
		return this->base_salary;
	}
	//设置团队提成
	void set_team_reward(int money) {
		this->team_reward = money;
	}
	//获取团队提成
	int get_team_reward() {
		return this->team_reward;
	}
	//计算薪资
	int calcSalary() {
		return base_salary + team_reward;
	}
	//显示员工信息
	void showInfo() {
		cout << "姓名: " << this->name << "\tID: " << this->id << "\t薪资: " << this->calcSalary() << endl;
	}
protected:
	//成员
	int base_salary;
	int team_reward;
};

/*
	管理类 Company
*/
class Company {
public:
	//行为
	//构造函数
	Company(int capacity) {
		this->capacity = capacity;
		employees = new Employee * [capacity];
		this->size = 0;
	}
	//添加员工
	void addEmployee(Employee * employee) {
		//判断是否满员
		if (size >= capacity) {
			cout << "公司满员，添加失败!" << endl;
			return;
		}
		employees[size] = employee;
		size++;
	}
	//显示信息
	void showAll() {
		cout << "------------------------------------------" << endl;
		cout << "公司员工总数: " << size << endl;
		for (int i = 0; i < size; i++) {
			employees[i]->showInfo();
		}
		cout << "------------------------------------------" << endl;
	}
	//计算薪资总额
	int calcTotalSalary() {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += employees[i]->calcSalary();
		}
		return sum;
	}
	//析构函数
	~Company() {
		//释放employees空间
		if (employees != NULL) {
			for (int i = 0; i < size; i++) {
				delete employees[i];
			}
			delete[] employees;
			employees = NULL;
		}
	}
protected:
	//成员
	Employee** employees;
	int size;			//公司现在有的人数
	int capacity;		//公司能够容纳的人数

};
int main() {
	Company c(10);

	c.addEmployee(new worker("Tom", 1001, 5000));
	c.addEmployee(new Engineer("Alice", 1002, 8000, 3000));
	c.addEmployee(new Manager("Bob", 1003, 12000, 5000));

	c.showAll();
	cout << "Total Salary: " << c.calcTotalSalary() << endl;

	system("pause");
	return 0;
}