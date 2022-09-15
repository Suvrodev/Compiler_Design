#include<iostream>
#include<set>
using namespace std;
int main(){
    string str;
    set<string> s;


    for(int i=1;i<=5;i++){
        cout<<"Input String: ";
        getline(cin,str);
        s.insert(str);
    }

    cout<<"Inputed String: ";
     for (auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
   
}