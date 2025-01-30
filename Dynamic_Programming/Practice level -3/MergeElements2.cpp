/*
Q -> Description
You are given N elements, in an array A. You are also given 3 constants X, Y, and Z. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (aX+bY+Z)%50 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2*X+A3*Y+Z)%50, A4].
 

Find the Minimum cost to merge all the elements into a single element.

Input Format
The first line contains 4 integers, N, X, Y, Z. 1 <= N <= 50, 0<= X,Y,Z < 50.

The Second line contains N space-separated integers, the Ai for the Array.  0 <= Ai < 50

Output Format
Output a single integer, the Minimum cost to Merge all the elements.

Sample Input 1
3 1 2 3
1 2 4

Sample Output 1
21
*/
