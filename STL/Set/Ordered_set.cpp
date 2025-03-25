/*
Description
You are given Q queries and have to perform the following operations:

add x - If x doesn't exist in the set, add element x to the set. Otherwise, do nothing.
remove x - Remove element x from the set, if it exists. Otherwise, do nothing.
find x - Find the value at position x (0-indexing) if it exists. Otherwise, print -1.
findpos x - Find the position (0-indexing) of the element with value x if it exists. Otherwise, find the position where the element x would be in the set.
The set is ordered in non-decreasing order of the elements.
*/
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int q;
        cin>>q;

        ordered_set st;

        while(q--){
            string s;
            int x;
            cin>>s>>x;

            if(s=="add"){
                st.insert(x); 

            }else if(s=="remove"){
                if(st.find(x)!=st.end()){
                    st.erase(st.find(x));
                }

            }  else if(s=="find"){
                if(x >= (int)st.size()){
                    cout<<"-1\n";
                }else{
                    cout<<*(st.find_by_order(x))<<'\n';
                }
            } else{
                cout<<st.order_of_key(x)<<'\n';
               }
            }
        }
    return 0;
    }
