//Generate all Subsets of a n integer array
#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //2^n=(1<<n) two to the power n is equivalent to one left shifted by n
    for(int mask=0;mask<(1<<n);mask++){
        cout<<mask<<" : ";
        // e.g. mask= 2-->010
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                cout<<arr[i]<<", ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// in binary representation the indexing is done right to left
//precedence of & has to be taken care by adding an extra bracket each time when the operation is being performed
//condtition for printing the elements which are not present in the subset: ((mask>>i)&1)==010
// 2^(31-1)--> limit of integer to print 2^31--> (1LL>>31) defining datatype for the constant