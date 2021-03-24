#include<string>
#include<iostream>
using namespace std;

class people {
    protected:
        string name;
        int gender;
        int age;
    public:
        people(string name,int gender,int age);
        void setName(string name);
        void setGender(int gender);
        void setAge(int age);
        virtual void print();
};

class teacher: public people {
    private:
        string tid;
        string rank;
        string major;
    public:
        teacher(string name, int gender, int age, string tid, string rank, string major);
        void setTID(string tid);
        void setRank(string rank);
        void setMajor(string major);
        void print() override;
};

class student: public people {
    private:
        string sid;
        string classroom;
        int chineseScore, mathScore, englishScore;
    public:
        student(string name, int gender, int age, string sid, string classroom, int chineseScore, int mathScore, int englishScore);
        void setSID(string sid);
        void setClassromm(string classroom);
        void setScore(int chineseScore, int mathScore, int englishScore);
        void print() override;
};

//Class people. 

people::people(string name,int gender, int age) :
    name(name),
    gender(gender),
    age(age)
{}

void people::setName(string name) {
    this->name = name;
}

void people::setGender(int gender) {
    this->gender = gender;
}

void people::setAge(int age) {
    this->age = age;
}

// Class teacher.

teacher:: teacher(string name,int gender,int age,string tid,string rank,string major):
people(name,gender,age),
tid(tid),
rank(rank),
major(major)
{}

void teacher::setTID(string tid) {
    this->tid = tid;
}

void teacher::setRank(string rank) {
    this->rank = rank;
}

void teacher::setMajor(string major) {
    this->major = major;
}

void teacher::print() {
    cout << "教师编号:" + this->tid << endl;
    cout << "教师姓名:" + this->name << endl;
    cout << "教师性别:" + this->gender << endl;
    cout << "教师年龄:" + this->age << endl;
    cout << "教师职称:" + this->rank << endl;
    cout << "教师专业:" + this->major << endl;
}

// Class student.

student::student(string name, int gender, int age, string sid, string classroom, int chineseScore, int mathScore, int englishScore):
people(name,gender,age),
sid(sid),
classroom(classroom),
chineseScore(chineseScore),
mathScore(mathScore),
englishScore(englishScore)
{}

void student::setSID(string sid) {
    this->sid = sid;
}

void student::setClassromm(string classroom) {
    this->classroom = classroom;
}

void student::setScore(int chineseScore, int mathScore, int englishScore) {
    this->chineseScore = chineseScore;
    this->mathScore = mathScore;
    this->englishScore = englishScore;
}

void student::print() {
    cout << "学生学号:" + this->sid << endl;
    cout << "学生姓名:" + this->name << endl;
    cout << "学生性别:" + this->gender << endl;
    cout << "学生年龄:" + this->age << endl;
    cout << "学生班级:" + this->classroom << endl;
    cout << "语文分数:" + this->chineseScore << endl;
    cout << "数学分数:" + this->mathScore << endl;
    cout << "英语分数:" + this->englishScore << endl;
}