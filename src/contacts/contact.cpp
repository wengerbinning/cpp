#include "contact.h"

////
Contact::Contact(string name, string number, string group):
    Name(name),
    Number(number),
    Group(group)
{}

////
Contact::Contact(const Contact& contact):
    Name(contact.Name),
    Number(contact.Number),
    Group(contact.Group)
{}

////
Contact::Contact():
    Contact("root","00000000000","all")
{}

////
void Contact::setName(string name) {
    this->Name = name;
}

////
void Contact::setNumber(string number) {
    this->Number = number;
}

////
void Contact::setGroup(string group) {
    this->Group = group;
}

////
string Contact::getName() {
    return this->Name;
}

////
string Contact::getNumber() {
    return this->Number;
}

////
string Contact::getGroup() {
    return this->Group;
}

////
void Contact::setContact(string name, string number, string group)
{
    this->setName(name);
    this->setNumber(number);
    this->setGroup(group);
}

////
bool Contact::Match(string name, string number, string group) {
    regex pattern("([0-9a-zA-Z_-\s]*)(\\*)");
    name = regex_replace(name, pattern, "$1.*");
    number = regex_replace(number, pattern, "$1.*");
    group = regex_replace(group, pattern, "$1.*");
    regex patter_name(name);
    regex patter_number(number);
    regex patter_group(group);
    if ( regex_match(this->Name,patter_name) ) {
        if ( regex_match(this->Number,patter_number) ) {
            if( regex_match(this->Group,patter_group) ) {
                return true;
            }
        }
    }
    return false;
}

////
void Contact::Print()
{
    cout << setiosflags(ios::left);
    cout << setw(10) << "姓名：" << setw(20) << this->getName();
    cout << setw(10) << "电话：" << setw(20) << this->getNumber();
    cout << setw(10) << "分组：" << setw(20) << this->getGroup() <<endl;
}

////
bool Contact::operator<(Contact& contact)
{
    if(this->Name < contact.Name) {
        return true;
    } else if(this->Name == contact.Name) {
        if (this->Group < contact.Group) {
            return true;
        } else if (this->Group == contact.Group) {
            if(this->Number < contact.Number)
                return true;
        }
    }
    return false;
}

////
Contact::~Contact() {

}

////
ostream& operator<<(ostream& out,Contact contact) {
    out << setiosflags(ios::left);
    out << setw(20) << contact.getName();
    out << setw(20) << contact.getGroup();
    out << setw(20) << contact.getNumber();
    return out;
}

////
istream& operator>>(istream& in, Contact contact) {
    in >> contact.Name;
    in >> contact.Number;
    in >> contact.Group;
}

/** @version 0.0.1
 *  @author Clark Aaron
 *  @date 2020-11-25 21:00
 *  @bug 合法性检测。
 *  
 */
bool Compare(const Contact& con1,const Contact& con2,ConSort sort) {
    switch(sort) {
        case NAME:
            if(con1.Name < con2.Name)
                return true;
            else if (con1.Name == con2.Name)
        case GROUP:
            if(con1.Group < con2.Group)
                return true;
        case NUMBER:
            if(con1.Number < con2.Number)
                return true;
    }
    return false;
}


////
Contacts::Contacts() {}

////
void Contacts::Add(string name,string number, string group) {
    Contact contact = Contact(name, number, group);
    this->contact.push_back(contact);
}

/** @version 0.0.1
 *  @author Clark Aaron
 *  @date 2020-11-25 21:23
 *  @bug It isn't reasonable.
 */
const Contact Contacts::Get(int index) {
    return this->contact[index];
}

////
vector<int> Contacts::Find(string name, string number, string group) {
    vector<int> count;
    for (int i = 0; i < this->contact.size(); i++)
    {
        if(this->contact[i].Match(name,number,group)) {
            contact[i].Print();
            count.push_back(i);
        }
    }
    return count;
}

////
int Contacts::Delete(string name, string number, string group) {
    vector<Contact>::iterator iter_start = this->contact.begin();
    vector<Contact>::iterator iter_end = this->contact.end();
    int num = 0;
    while (iter_start != iter_end)
    {
        
        if ( iter_start->Match(name, number, group) ) {
            this->contact.erase(iter_start);
            num++;
        }
        iter_start++;
    }
    return num;
}

////
void Contacts::Sort() {
    sort(this->contact.begin(), this->contact.end());
}

////
void Contacts::SortGroup() {
    int count = this->contact.size();
    for (int i = 1; i <count; i++) {
        for (int j = 0; j < i;j++) {
            if(this->contact[i].getGroup() < this->contact[j].getGroup()) {
                swap(this->contact[i], this->contact[j]);
            }
        }
    }
}

////
void Contacts::List() {
    this->Find("*", "*", "*");
}

////
void Contacts::ListGroup(string& group) {
    this->Find("*", "*", group);
}

////
Contact Contacts::operator[](int index) {
    return this->contact[index];
}

////
Contacts::~Contacts() {
    this->contact.clear();
}

/** @test This is a Demo main.
 * 
 */
int main(int agrc, char *argv[])
{
    Contacts con;
    con.Add("abc", "17816110001", "zstu1");
    con.Add("bca", "17816110002", "zstu2");
    con.Add("aca", "17816110003", "zstu1");
    con.Add("baa", "17816110004", "zstu2");
    con.Add("cca", "17816110002", "zstu1");
    con.Add("caa", "17816110006", "zstu2");

    con.List();
    cout << "[INFO] 排序开始。" << endl;
    con.Sort();
    con.SortGroup();
    cout << "[INFO] 排序完成。" << endl;
    con.List();
}
