/*
Q--> find two five digit numbers such that their ratio is equal to given number N and all the digits are distinct.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n = 12;
    string s="0123456789";
    do{
        int num = stoi(s.substr(0,5));
        int den = stoi(s.substr(5,5));
        if(num == n*den)
        cout<<num<<" "<<den<<'\n';
    }while(next_permutation(s.begin(),s.end()));
    
    return 0;
}
/////////////////////////////FASTER APPROACH-O(10^5 * 10)////////////////////////
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n = 12;
    for(int abcde = 01234; abcde <= 98765;abcde++){
        if(abcde%n!=0) continue;
        int fghij = abcde/n;
        set <int> st;
        int x = abcde;
        for(int i=0;i<5;i++){
            st.insert(x%10);
            x/=10;
        }
        
         x = fghij;
        for(int i=0;i<5;i++){
            st.insert(x%10);
            x/=10;
        }
        
        if(st.size()==10){
            cout<<abcde<<" "<<fghij<<'\n';
        }
    }
    return 0;
}
/////////////////////////BITMASK LOGIC APPROACH/////////////////////
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n = 12;
    for(int abcde = 01234; abcde <= 98765;abcde++){
        if(abcde%n!=0) continue;
        int fghij = abcde/n;
        
        int pre_mask = 0;
        
        int x = abcde;
        for(int i=0;i<5;i++){
            pre_mask !=(1<<(x%10));
            x/=10;
        }
        
         x = fghij;
        for(int i=0;i<5;i++){
            pre_mask!=(1<<(x%10));
            x/=10;
        }
        
        if(pre_mask==((1<<10)-1)){
            cout<<abcde<<" "<<fghij<<'\n';
        }
    }
    return 0;
}

//Always use the tighter condition as the generating condtion so that less possible outcomes are generated causing less computation.