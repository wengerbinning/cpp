#ifndef __CONTACT_H
#define __CONTACT_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <regex>
#include <algorithm>

using namespace std;

enum ConSort
{
    NAME,
    GROUP,
    NUMBER
};

/** @class Contact
 *  @brief   It's class abstracting a contact.
 *  @details Contact have three data member: Name, Number, Group is meaning contact name,contact phone number and contact group.
 */
class Contact {
    private:
        string Name;        /** This is contact name. */
        string Group;       /** This is contact group. */
        string Number;      /** This is contact phone number. */
    public:
        /** @func Contact()
         *  @brief This is constructor.
         *  @details This is default constructor without paramater.
         */
        Contact();

        /** @func Contact(const Contact& contact)
         *  @brief This is a constructor.
         *  @details This is a initialization way using  quote Contact object.
         *  @param contact It's Contact object initializing object.
         */
        Contact(const Contact &contact);

        /** @func Contact(string name, string number, string group)
         *  @brief It's a constructor.
         *  @details This is a basic constructor,it have three string paramater to initialize Contact member.
         *  @param name It's paramater initializing Contact.Name.
         *  @param number It's paramater initializing Contact.Number.
         *  @param group group is paramater initializing Contact.Group.  
         */
        Contact(string name, string number, string group);
    
        /** @func setName(string name)
         *  @brief Set Contact's Name.
         *  @param name It's a string.
         */
        void setName(string name);

        /** @func getName()
         *  @brief Get Contact's Name.
         *  @return string It's Contact's Name.
         */
        string getName();

        /** @func setNumber(string number)
         *  @brief Set Contact's Number.
         *  @param number It's a string.
         */
        void setNumber(string number);

        /** @func getNumber()
         *  @brief Get Contact's Number.
         *  @return string It's Contact's Number.
         */
        string getNumber();

        /** @func setGroup(string group)
         *  @brief Set Contact's Group.
         *  @param group It's a string.
         */
        void setGroup(string group);

        /** @func getGroup()
         *  @brief Get Contact's Group.
         *  @return It's Contact's Group.
         */
        string getGroup();

        /** @func setContact()
         *  @brief This is a set function.
         *  @details This is a set function using three string.
         *  @param name name is paramater initializing Contact.Name.
         *  @param number number is paramater initializing Contact.Number.
         *  @param group group is paramater initializing Contact.Group.
         */
        void setContact(string name, string number, string group);

        /** @func Math(string name, string number, string group)
         *  @ brief Match matched Contact object.
         *  @ detail Determines whether an object matches based on the three string.
         *  @param name It's string.
         *  @param number It's string.
         *  @param group It's string.
         *  @return bool
         *      - true The Contact is matched.
         *      - false The Contact isn't matched.
         */
        bool Match(string name, string number, string group);

        /** @func Print()
         *  @brief Print Contact content.
         */
        void Print();

        /** @func operator<
         *  @brief This is a override operator<.
         *  @detail override operator< in order to sort by name.
         *  @param contact contact is a quote Contact object. 
         *  @return true is this object is small.
         */
        bool operator<(Contact& contact);
     
        /** @func operator<<
         * 
         */
        friend ostream& operator<<(ostream& out, Contact contact);

        /** @func operator>>
         * 
         */
        friend istream& operator>>(istream& in, Contact contact);
        
        /** @func pr()
         * 
         */
        friend bool Compare(const Contact& con1, const Contact& con2,ConSort sort);

        /** @func ~Contact()
         *  @brief It's destructor.
         *  @detail When the Contact object is destroyed, clean up the environment.
         */
        ~Contact();
};

/** @class Contacts
 *  @brief It's a Contact's vector.
 *  @detail 
 */
class Contacts {
    private:
        vector<Contact> contact;      /** contact is a Contact vector. */
    public:
        /** @func Contacts()
         *  @brief It's a constructor.
         *  @details Contacts is default constructor.
         */
        Contacts();

        /** @func Contacts(string name, string number, string group)
         *  @brief Add a Contact element.
         *  @detail Add creates a Contact object based on three string values and appends it to Contacts.
         *  @param name It's a string.
         *  @param number It's a string.
         *  @param group It's a string.
         */
        void Add(string name, string number, string group);

        /** @func Get(int index)
         *  @brief Get element by index.
         *  @param index It's a int.
         *  @return const Contact&
         *          return find element.
         */
        const Contact Get(int index);

        /** @func Find(string name, string number, string group)
         *  @brief Find Contact element matches the matching string.
         *  @param name
         *  @param number
         *  @param group
         *  @return vector<int>
         *      This is int vector.
         */
        vector<int> Find(string name, string number, string group);

        /** @func Delete(string name, string number, string group)
         *  @brief Delete 
         *  @param name
         *  @param number
         *  @param group
         *  @return int
         */
        int Delete(string name, string number, string group);

        /** @func Sort()
         *  @brief Sort by name.
         */
        void Sort();

        /** @func SortGroup()
         * 
         */
        void SortGroup();

        /** @func List()
         * 
         */
        void List();

        /** @func ListGroup()
         * 
         */
        void ListGroup(string &group);
        
        /** @func operator[]
         * 
         */
        Contact operator[](int index);
        
        /** @func ~Contacts()
         * 
         */
        ~Contacts();
};



#endif
