/*
Problem Statement
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence a=(a1,a2,…,aN). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
Remove the element at the beginning or the end of a. The player earns x points, where x is the removed element.
Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize X−Y, while Jiro tries to minimize X−Y.
Assuming that the two players play optimally, find the resulting value of X−Y.

Constraints
All values in input are integers.
1≤N≤3000
1≤ai≤10^9
 
Input
Input is given from Standard Input in the following format:

N
a1 a2...... aN
​
Output
Print the resulting value of 
X−Y, assuming that the two players play optimally.

Sample Input 1
4
10 80 90 30

Sample Output 1
10
*/