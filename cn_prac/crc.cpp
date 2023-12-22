#include <iostream>
#include <cstring>

using namespace std;

// Length of the generator polynomial
int N=0;

// Data to be transmitted and received
string transmission_data;
// CRC value
char check_value[28];
// Generator polynomial
string gen_poly="";
// Variables
int data_length, i, j;

// Function that performs XOR operation
void XOR() {
    // If both bits are the same, the output is 0
    // If the bits are different, the output is 1
    for (j = 1; j < N; j++)
        check_value[j] = ((check_value[j] == gen_poly[j]) ? '0' : '1');
}

void crc() {
    // Initializing check_value
    for (i = 0; i < N; i++)
        check_value[i] = transmission_data[i];
    do {
        // Check if the first bit is 1 and call XOR function
        if (check_value[0] == '1')
            XOR();
        // Move the bits by 1 position for the next computation
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];
        // Append a bit from transmission_data
        check_value[j] = transmission_data[i++];
    } while (i <= data_length + N - 1);
    // Loop until the data ends
}

// Function to check for errors on the receiver side
void receiver() {
    // Get the received data
    cout << "Enter the received data: ";
    cin >> transmission_data;
    cout << "\n-----------------------------\n";
    cout << "Data received: " << transmission_data;

    // Cyclic Redundancy Check
    crc();

    // Check if the remainder is zero to find the error
    cout << "Check value: " << check_value;
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++);
    if (i < N - 1)
        cout << "\nError detected\n\n";
    else
        cout << "\nNo error detected\n\n";
}

int main() {
    // Get the data to be transmitted
    cout << "\nEnter data to be transmitted: ";
    cin >> transmission_data;
    cout << "\nEnter the Generating polynomial: ";
    // Get the generator polynomial
    string g;
    cin>>g;
    int ind[100]={0};
    bool cons;
   if(isdigit(g[g.length()-1]) && g[g.length()-2]!='^') {ind[0]++; cons=true;}
   int l=cons?g.length()-1:g.length();
    for(int a=0;a<l;a++){
         if(g[a]=='^') {
            int d=g[a+1]-'0';
            ind[d]++;
         }
    }
    for(int a=0;a<10;a++) cout<<ind[a]<<" ";
    cout<<endl;
    for(int a=99;a>=0;a--){
        if(ind[a]==1) {
            // cout<<"a:"<<a<<endl;
            for(int j=a;j>=0;j--) gen_poly+=ind[j]+'0';
            break;
        }
    }
    // cout<<"gen_poly: "<<gen_poly<<endl;


    // cin >> gen_poly;
    N=gen_poly.length();
    cout << "N: " << N << endl;

    // Find the length of data
    data_length = transmission_data.length();
    cout<<data_length<<endl;

    // Append N-1 zeros to the data
    for (i = data_length; i < data_length + N - 1; i++)
        transmission_data+= '0';

    // Print the data with padded zeros
    cout << "\n----------------------------------------";
    cout << "\nData padded with N-1 zeros: " << transmission_data;
    cout << "\n----------------------------------------";

    // Cyclic Redundancy Check
    crc();

    // Print the computed check value
    cout << "\nCRC or Check value is: " << check_value;

    // Append data with check_value (CRC)
    for (i = data_length; i < data_length + N - 1; i++)
        transmission_data[i] = check_value[i - data_length];

    // Printing the final data to be sent
    cout << "\n----------------------------------------";
    cout << "\nFinal data to be sent: " << transmission_data;
    cout << "\n----------------------------------------\n";

    // Call the receiver function to check errors
    receiver();

    return 0;
}
