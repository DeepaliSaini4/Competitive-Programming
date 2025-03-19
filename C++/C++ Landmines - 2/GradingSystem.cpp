/*

You are given the marks of a student in mid-term, final-term and the make-up examinations. If the student does not attend an exam, marks are assigned as -1. You have to 
find the grade of the student according to the following guidelines:

If the student does not take the mid-term or the final-term exam, grade is F
If the total score in mid-term and final-term is greater than or equal to 80, grade is A.
If the total score in mid-term and final-term is greater than or equal to 65 and less than 80, grade is B.
If the total score in mid-term and final-term is greater than or equal to 50 and less than 65, grade is C.
If the total score in mid-term and final-term is greater than or equal to 30 and less than 50, grade is D. However, if the score of the make-up examination is
greater than or equal to 50, the grade will be C.
If the total score in mid-term and final-term is less than 30, grade is F.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int m,f,r;
        cin>>m>>f>>r;
        if(m==-1 || f==-1) cout<<"F"<<'\n';
        else if(f+m>=80) cout<<"A"<<'\n';
        else if(m+f>=65 && m+f <=80) cout<<"B"<<'\n';
        else if(m+f>=50 && m+f <=65) cout<<"C"<<'\n';
        else if(m+f>=30 && m+f<=50){
            if(r>=50) cout<<"C"<<'\n';
            else cout<<"D"<<'\n';
        }
        else if(m+f<=30) cout<<"F"<<'\n';
    }
    return 0;
}
