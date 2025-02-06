/*
You are given an integer k and an integer x. The price of a number num is calculated by the count of 
set bits
 at positions x, 2x, 3x, etc., in its binary representation, starting from the least significant bit. The following table contains examples of how price is calculated.

x	num	Binary Representation	Price
1	13	000001101	            3
2	13	000001101	            1
2	233	011101001	            3
3	13	000001101	            1
3	362	101101010           	2
The accumulated price of num is the total price of numbers from 1 to num. num is considered cheap if its accumulated price is less than or equal to k.
Return the greatest cheap number.
*/
class Solution {
public:
    //utility function to calculate the number of bits
    int countbits(long long n){
        int count = 0;
        while(n){
            count++;
            n=n>>1;
        }
        return count;
    }
    //function to calculate the price through set bits at positions 'x','2x' and so on..
    long long price(long long n, int x){
        int i = countbits(n);//gives the number of columns to be considered
        long long price = 0;
        // increment n to account 0th row in the count of groups
        n++;
        while(i){
            //if current column is valis count the number of set bits present in the column
            if(i%x == 0){
                //add a complete contribution + remaining left over contribution
                price+=((n/(1LL<<i)))*(1LL<<(i-1))+max(((n%(1LL<<i))-(1LL<<i-1)),0LL);
                //move to the next column
            }
                i--;
        }
            return price;

    }
    long long findMaximumNumber(long long k, int x) {
        long long lo = 1,hi =1e15;
        //binary search to find the greatest cheapest number
        while(lo <= hi){
            long long mid = (hi-lo)/2 +lo;
            if(price(mid,x)<=k){
                lo = mid+1;
            }
            else hi = mid -1;    
        }
        return hi;
    }
};
// tc = O(log range * log n)
