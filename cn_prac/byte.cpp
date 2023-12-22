#include<iostream>
using namespace std;

string bytestuff(string data){
    string s="";
    int n=data.length();
    s+="FLAG ";
    for(int i=0;i<n;i++){
        if(i<n && i+1<n && i+2<n && i+3<n && data[i]=='f' && data[i+1]=='l' && data[i+2]=='a' && data[i+3]=='g') s+="ESC";
        if(i<n && i+1<n && i+2<n && data[i]=='e' && data[i+1]=='s' && data[i+2]=='c') s+="ESC";
        s+=data[i];
    }
    s+=" FLAG";
    return s;
}
string bytedestuff(string data){
    string s="";
    int n=data.length();
    for(int i=0;i<n;i++){
        if(i<n && i+1<n && i+2<n && i+3<n && data[i]=='F' && data[i+1]=='L' && data[i+2]=='A' && data[i+3]=='G') { i+=3;}
        else if(i<n && i+1<n && i+2<n && data[i]=='E' && data[i+1]=='S' && data[i+2]=='C') { i+=2;}
        else s+=data[i];
    }
    return s;
}

int main(){
    string data;
    cout<<"senders side:"<<endl;
    cout<<"enter data:"<<endl;
    getline(cin,data);
    cout<<"After stuffing: "<<bytestuff(data)<<endl;
    cout<<"Recievers side:"<<endl;
    string rdata;
    cout<<"enter recieved data:"<<endl;
    getline(cin,rdata);
    cout<<"After destuffing: "<<bytedestuff(rdata);
}