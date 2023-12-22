#include<iostream>
using namespace std;
int T(),B();
string s;
int i=0;
int main(){
    cout<<"Enter a string:"<<endl;
    cin>>s;
    if(T()) cout<<"Valid string"<<endl;
    else cout<<"Invalid string"<<endl;

}

//for grammer B->a*a

//for grammer T->aT|a
int T(){
    if(s[i]=='a'){
        i++;
        if(T()){
            return 1;
        }
        else return 0;
    }
    else if(s[i]=='a') return 1;
    return 0;
}