#include <iostream>
#include <string>

using namespace std;

int main(int args,char* argv[]) {
    string name;
    int work=0;
    float hours,salary=0;
    cout << "请输入教师姓名：";
    cin >> name;
    cout << "请输入教师职称（输入职称对应的序号）\n"<<"（1.教授、2.副教授、3.讲师、4.助教）：";
    cin >> work;
    cout << "请输入教师授课时数：";
    cin >> hours;

    if(work == 1)          salary = 100*hours;
    else if(work == 2)   salary = 80*hours;
    else if(work == 3)     salary = 60*hours;
    else if(work == 4)     salary = 40*hours;
    else
    {
        cout << work<<"输入职称错误,请重新输入!"<<endl;
        return 1;
    }
    cout << "教师"<<name<<"共授课"<<hours<<"课时,总计"<<salary<<"元课酬。"<<endl;

    return 0;
}