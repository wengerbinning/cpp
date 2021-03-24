#include <iostream>
#include <iomanip>

using namespace std;

int print(int len=4,char str='*');

int main(int args, char* argv[]) {
    //print(10,'@');
    print();
}

int print(int len,char str) {
    char chars = str;
    for(int i=1; i<=len; i++) {
        for(int j=1;j<len+i;j++) {
            if(j<=len-i)   chars = ' ';
            else            chars = str;
            cout<<chars;
        }    
        cout<<endl;
    }
    return 0;
}