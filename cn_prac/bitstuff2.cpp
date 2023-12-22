#include<iostream>
using namespace std;
string stuff(string j,string flag){
    string s="";
    s+=flag;
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
    for(int i=flag.length();i<j.length()-flag.length();i++) s+=j[i];
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
    int fs;
    bool padd;
    string data;
    cout<<"Senders side"<<endl;
    cout<<"Enter data to be transmitted!"<<endl;
    cin>>data;
    string flag="01111110";
    cout<<"Enter frame size"<<endl;
    cin>>fs;
    int max_frames=data.length()/fs;
    (data.length()%fs==0)?padd=false:padd=true;
    cout<<"max frames: "<<max_frames<<endl;
    int l=0,h=fs;
    for(int i=0;i<max_frames;i++){
        string ndata="";
        for(int j=l;j<h;j++) ndata+=data[j];
        l+=fs;
        h+=fs;
        cout<<"After stuffing [frame "<<i+1<<"] :"<<stuff(ndata,flag)<<endl;
    }
    if(padd){
        string pdata="";
        int rem=0;
        for(int i=l;data[i]!='\0';i++) {pdata+=data[i]; rem++;}
        for(int i=0;i<fs-rem;i++) pdata+='0';
        cout<<"After stuffing [padded]: "<<stuff(pdata,flag)<<endl;
    }
    cout<<"Receievrs side!"<<endl;
    int n;
    cout<<"Enter no of frames recieved"<<endl;
    cin>>n;
    string check="";
    for(int i=0;i<n;i++){
    string rdata;
    cout<<"Enter recieved data"<<endl;
    cin>>rdata;
    cout<<"After destuffing: "<<destuff(rdata,flag)<<endl;
    check+=destuff(rdata,flag);
    }
    cout<<"After destuffing all frames: ";
    for(int i=0;i<data.length();i++) cout<<check[i];



}
