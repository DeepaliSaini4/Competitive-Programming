/*
Q -> Description
You are given a non-empty string S consisting of lower case characters. You can change at most K letters to maximise the cost. If in the final string, X immediately precedes Y, you get an increase in cost by C. You have to determine the maximum cost possible.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


The first line of each test case contains string S and an integer K - the number of characters you can change at most.


The second line of each test case contains M - the number of cost values.


The following M lines contain two space-separated integers along with a character X Y C - you get an increase in cost by C if X immediately precedes Y.

Output Format
For each test case, print a single integer denoting the maximum cost possible on a separate line.

1≤T≤100
1≤∣S∣≤100 where ∣S∣ denotes the length of the string S
0≤K≤100
0≤M≤676
a≤X,Y≤z
−1000≤C≤1000

It is guaranteed that no pair XY is mentioned twice in the input data.

Sample Input 1
3
akcbd 2
3
a d 55
b z 100
b c 50
srtlmx 2
2
e a -167
c v -932
abcd 2
4
x y 10
y z 100
a x -150
z d -150

Sample Output 1
155
0
100
*/
