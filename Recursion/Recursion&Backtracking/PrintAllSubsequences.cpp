#include<bits/stdc++.h>
using namespace std;

int n;
int curr;
int arr[100];
int sol[10];

void gen(int i){
    if(i==n){
        for(int i=0;i<curr;i++){
            cout<<sol[i]<<" ";
        }
            cout<<'\n'; 
            return;
    }
    gen(i+1);
    sol[curr]=arr[i];
    curr++;
    gen(i+1);
    curr--;
    sol[curr] = 0;
}

int main(){
    n = 4;
    arr[0] = 1,arr[1] = 2, arr[2] = 3, arr[3] = 4;
    gen(0);
    return 0;
}
