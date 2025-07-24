#include <bits/stdc++.h>
using namespace std;

int main()
{
//   int arr[6]={1,2,3,4,5,6};
//   do{
//   for(int i=0;i<6;i++){
//       cout<<arr[i]<<",";
//   }
//       cout<<endl;
//   }while(next_permutation(arr,arr+3));
  string arr="bac";
 do{
     for(int i=0;i<3;i++){
         cout<<arr[i]<<",";
     }
     cout<<endl;
 }while(next_permutation(arr.begin(),arr.end()));

    return 0;
}
