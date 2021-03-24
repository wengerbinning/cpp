#include<string>
#include<iostream>

using namespace std;


class Publication {
    protected:
        string title;
        string name;
        float price;
    public:
        Publication(string title, string name, float price);
        virtual void inputData();
        virtual void display();
        ~Publication();
};

class Book: public Publication {
    private:
        int page;
    public:
        Book(string title, string name, float price, int page);
        void inputData() override;
        void display() override;
        ~Book();
};

class CD: public Publication {
    private:
        string playtime;
    public:
        CD(string title, string name, float price, string playtime);
        void inputData() override;
        void display() override;
        ~CD();
};

// class Publication.

Publication::Publication(string title,string name,float price):
title(title),
name(name),
price(price)
{}

Publication::~Publication() {
    cout << "Publication析构函数调用." << endl;
}

// class Book.

Book::Book(string title, string name, float price, int page):
Publication(title,name,price),
page(page)
{}

void Book::inputData() {
    cout << "请输入出版物标题:";
    cin >> this->title;
    cout << "请输入出版物名称:";
    cin >> this->name;
    cout << "请输入出版物价格:";
    cin >> this->price;
    cout << "请输入出版物页数:";
    cin >> this->page;
}

void Book::display() {
    cout << "出版物标题:" << this->title << endl;
    cout << "出版物名称:" << this->name << endl;
    cout << "出版物价格:" << this->price << endl;
    cout << "出版物页数:" << this->page<< endl;
}

Book::~Book() {
    cout << "Book析构函数调用." << endl;
}

// class CD.

CD::CD(string title, string name, float price, string playtime):
Publication(title,name,price),
playtime(playtime)
{}

void CD::inputData() {
    cout << "请输入出版物标题:";
    cin >> this->title;
    cout << "请输入出版物名称:";
    cin >> this->name;
    cout << "请输入出版物价格:";
    cin >> this->price;
    cout << "请输入出版物播放时间:";
    cin >> this->playtime;
}

void CD::display() {
    cout << "出版物标题:" << this->title << endl;
    cout << "出版物名称:" << this->name << endl;
    cout << "出版物价格:" << this->price << endl;
    cout << "出版物播放时间:" << this->playtime  << endl;
}

CD::~CD() {
    cout << "CD析构函数调用." << endl;
}