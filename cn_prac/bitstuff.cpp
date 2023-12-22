#include<iostream>
using namespace std;


string stuff(string j,string flag){
    string s="";
    s=flag;
    int c=0;
    for(int i=0;j[i]!='\0';i++){
        if(j[i]=='1') c++;
        else c=0;
        s+=j[i];
        if(c>=5) {
            c=0;
            s+='0';
        }
   }
    s+=flag;
    return s;
   

}
string destuff(string j,string flag){
    string s="";
    for(int i=flag.length();i<j.length()-flag.length();i++){
        s+=j[i];

    }
    int c=0;
    string f="";
    for(int i=0;s[i]!='\0';i++){
          if(c>=5){
            c=0;
            continue;
          }
          if(s[i]=='1') c++;
          f+=s[i];
       

    }

    return f;
    

}
int main(){
    string data;
    cout<<"Senders side"<<endl;
    cout<<"Enter data to be transmitted!"<<endl;
    cin>>data;
    string flag="01111110";
    cout<<"After stuffing: "<<stuff(data,flag)<<endl;
    string rdata;
    cout<<"Receievrs side!"<<endl;
    cout<<"Enter recieved data"<<endl;
    cin>>rdata;
    cout<<"After destuffing: "<<destuff(rdata,flag)<<endl;


}