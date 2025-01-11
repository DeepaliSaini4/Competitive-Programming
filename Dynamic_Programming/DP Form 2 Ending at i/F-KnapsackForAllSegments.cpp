/*
Problem Statement
Given are a sequence of 
N integers A1, A2, …,AN and a positive integer S.For a pair of integers (L,R) such that 1≤L≤R≤N, let us define f(L,R) as follows:
f(L,R) is the number of sequences of integers (x1,x2,…,xk) such that L≤x 1<x 2<⋯<xk≤R and Ax1 + Ax2+⋯+Axk=S.
Find the sum of f(L,R) over all pairs of integers (L,R) such that 1≤L≤R≤N. Since this sum can be enormous, print it modulo 998244353.

Constraints
All values in input are integers.
1≤N≤3000
1≤S≤3000
1≤Ai≤3000

Input
Input is given from Standard Input in the following format:

N S
A1 
A2
​.
.
. 
AN
​
Output
Print the sum of 
f(L,R), modulo 998244353.

Sample Input 1

3 4
2 2 4
Sample Output 1

5
*/
