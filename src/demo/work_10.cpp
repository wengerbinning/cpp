#include <iostream>
#include <string>

using namespace std;

class Salary {
    private:
        double Wage, Subsidy, Rent, WaterFee, ElecFee;
    public:
        Salary();
        Salary(double wage, double subsidy, double rent, double waterfee,double elecfee);
        void setWage(double f);
        void setSubsidy(double f);
        void setRent(double f);
        void setWaterFee(double f);
        void setElecFee(double f);
        double getWage();
        double getSubsidy();
        double getRent();
        double getWaterFee();
        double getElectFee();
        // 计算实发工资。
        double RealSalary();
};

// 有参构造函数。
Salary::Salary(double wage,double subsidy,double rent,double waterfee,double elecfee):
    Wage(wage),Subsidy(subsidy),Rent(rent),WaterFee(waterfee),ElecFee(elecfee) 
{}
// 无参构造函数。
Salary::Salary():Salary(0,0,0,0,0) {}
// 设定基本工资。
void Salary::setWage(double f) {
    Wage = f;
}
// 设定岗位津贴。
void Salary::setSubsidy(double f) {
    Subsidy = f;
}
// 设定房租。
void Salary::setRent(double f) {
    Rent = f;
}
// 设定水费。
void Salary::setWaterFee(double f) {
    WaterFee = f;
}
// 设定电费。
void Salary::setElecFee(double f) {
    ElecFee = f;
}
// 获取基本工资。
double Salary::getWage() {
    return Wage;
}
// 获取岗位津贴。
double Salary::getSubsidy() {
    return Subsidy;
}
// 获取房租。
double Salary::getRent() {
    return Rent;
}
// 获取水费。
double Salary::getWaterFee() {
    return WaterFee;
}
// 获取电费。
double Salary::getElectFee() {
    return ElecFee;
}
// 计算实发工资。
double Salary::RealSalary() {
    return Wage + Subsidy - Rent - WaterFee - ElecFee;
}


class Worker {
    private:
        string Name, Dept;
        int Age;
        Salary Salarys;
        static int Count;
    public:
        Worker(string name, string dept, int age,Salary salary);
        void setName(string name);
        void setDept(string Dept);
        void setAge(int age);
        void setSalarys(Salary salary);
        string getName();
        string getDept();
        int getAge();
        double getSalarys();
        static int getCount();
};

// 静态成员初始化。
int Worker::Count = 0;
// 有参构造函数。
Worker::Worker(string name,string dept,int age,Salary salary):
    Name(name),Dept(dept),Age(age),Salarys(salary)
{
    Count++;
}
// 设定工人姓名。
void Worker::setName(string name) {
    Name = name;
}
// 设定工作部门。
void Worker::setDept(string dept) {
    Dept = dept;
}
// 设定工人年龄。
void Worker::setAge(int age) {
    Age = age;
}
// 设定工人工资。
void Worker::setSalarys(Salary salary) {
    Salarys = salary;
}
// 获取工人姓名。
string Worker::getName() {
    return Name;
}
// 获取工作部门。
string Worker::getDept() {
    return Dept;
}
// 获取工人年龄。
int Worker::getAge() {
    return Age;
}
// 获取工人工资。
double Worker::getSalarys() {
    return Salarys.RealSalary();
}
// 获取工人数量。
int Worker::getCount() {
    return Count;
}

class List {
    private:
        int data;
        List* next;
    public:
        List(int count, int datas[]);
        void Insert(int index,int value);
        void Delete(int index);
        void Print();
};

// 无参构造函数。
List::List(int value) {
    data = value;
    next = nullptr;
}

void List::Insert(int value) {
    next = new (List);
    next->data = value;
    next->next = nullptr;
}

void List::Delete(int value) {
     
}

void List::Print() {
    cout << data<<endl;
    while(next) {
        next->Print();
    }
}







int main() {
    List list;
    list.Print();
    return 0;
}