#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     int n=4;
   // cin>>n;
    for(int mask=0;mask<(1<<n);mask++){
        bitset<4> x(mask);
        cout<<x.to_string()<<endl;
    }
    
    cout<<"Bitwise operations:"<<'\n';
    //bitset<4> b1(1001) --> not valid as considered as decimal number and on converting to binary its bitset will contain 9 bits that exceeds the declared bitset size leads to undefined behaviour
    bitset<4> b1("0011"),b2(0b1101); // bitset constructor expects a string of 0's and 1's which it interorets directly as a binary number // '0b' is a binary literal or prefix
    cout<<"or : "<<(b1|b2)<<'\n';
    cout<<"and: "<<(b1&b2)<<'\n';
    cout<<"Operations on bitset b1 "<<'\n';
    //set bit Operation
    cout<<b1<<'\n';
    cout<<"1.Set Bit 2nd     :";
    b1.set(2);      //**It takes indices from the left
    cout<<b1<<'\n';
    cout<<"2.Reset Bit 2nd   :";
    b1.reset(2);     
    cout<<b1<<'\n';
    cout<<"3.Acessing 1st bit:";
    bool bitvalue= b1[1];
    cout<<bitvalue<<'\n';
    cout<<"4.Flipping 1st bit:";
    b1.flip(1);
    cout<<b1<<'\n';
    cout<<"5.Counting set bit:";
    size_t count=b1.count();
    cout<<count<<'\n';
    cout<<"6.Bitwise Operation"<<"\n";
    cout<<"b1= "<<b1<<",b2= "<<b2<<" 1.(b1 |= b2):";
    b1|=b2;//|= means perform bitwise OR operation and assign the resulting value to the left operand
    cout<<b1<<"\n";
    cout<<"b1= "<<b1<<",b2= "<<b2<<" 2.(b1 &= b2):";
    b1&=b2;//&= means perform bitwise AND operation and assign the resulting value to the left operand
    cout<<b1<<"\n";
    cout<<"b1= "<<b1<<",b2= "<<b2<<" 3.(b1 ^= b2):";
    b1^=b2;//^= means perform bitwise XOR operation and assign the resulting value to the left operand
    cout<<b1<<"\n";
    cout<<"7.Integer Conversion of b2:";
    unsigned long intval=b2.to_ulong();//convert b2 bitset to unsigne long
    cout<<intval<<"\n";
    cout<<"8.String Conversion of b2:";
    string BitString=b2.to_string();//convert b2 bitset to unsigne long
    cout<<BitString<<"\n";
    
    
  
    return 0;
}
//Bitset-->Middlemen between array and bits
/*
no of integers required to store given number of bits== (unmber of bits/32)