/*
Description:
You want to visit the country of Wonderland. There are N cities in the country. Not all cities are connected by roads, but you know which cities are connected.

You landed in city A, and you want to visit city B. You already booked your car, but it doesn’t have any petrol. The capacity of the tank of the car is C. You know the Per Liter cost of petrol in each city, and you also have the map of the country (i.e., you know the length of the road between two cities).

To travel one unit of distance, you need one liter of petrol.

Your task is to find the minimum cost to travel from city A to city B.

Input Format:
The first line of input contains N - the number of cities in the country of Wonderland.

The second line contains M - the number of roads in the country.

The next M lines each contain three integers u, v, and d:

There is a road between city u and v of length d.

The next line contains N space-separated integers:

P[1], P[2], ..., P[N] - where P[i] is the per liter cost of petrol in city i.


The last line of input contains three integers A, B, and C:

A: The starting city.

B: The destination city.

C: The capacity of the car's petrol tank.


It is guaranteed that it’s always possible to reach city B from city A.

Output Format:
Print the minimum cost to reach city B on a new line.

Constraints:
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ C ≤ 100
1 ≤ u, v ≤ N
1 ≤ d ≤ C
1 ≤ A, B ≤ N
1 ≤ P[i] ≤ 100

sample input:
5
5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 6
1 10 10 10 1
1 5 8

6
6
1 2 1
2 3 1
3 4 1
4 5 1
1 6 1
6 5 5
10 10 10 10 1 1
1 5 8

ouput:
4
15

Note
Explanation 1:

Fill petrol of 4 liters in city 1, and travel via path 1 → 2 → 3 → 4 → 5.

Explanation 2:

Fill 1 liter of petrol in city 1 of cost 10, travel to city 6. Fill 5 liters of petrol at city 6 of cost 5 x 1 = 5. Travel to city 5. Total cost = 10 + 5 = 15. The path took 1 → 6 → 5.
*/
#include<bits/stdc++.h>
using namespace std;

# define int long long
# define pii pair <int,int>
# define F first
# define S second

using state = pair <int,int>; // {node,Current amount of petrol}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


}


