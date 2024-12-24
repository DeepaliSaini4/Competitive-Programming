# Centroid

The node about which, when the tree is rooted, each subtree has a size less than \( n/2 \).  
It acts as a weighted center that divides the tree into small chunks.

## How many centroids can a tree have?
- **Max 2**

## Is Center And Centroid the same?
- **No (not always).**

## Significance of center and centroid of a tree

- **Center of a Tree**: The most centrally located node(s), minimizing the farthest distance to other nodes. Useful for minimizing communication delays or distances.
- **Centroid of a Tree**: The node(s) that balance the tree when split, minimizing the size of the largest resulting subtree. Useful for dividing the tree efficiently.

## How to find the centroid?

### Intuitional approach

1. No two subtrees can have a size greater than \( n/2 \).
2. The subtree having the size greater than \( n/2 \) will contain the centroid.
3. Calculate the subtree size of all the trees, then consider the subtree's root whose size is greater than \( n/2 \) as the centroid and recursively solve for its subtrees.
4. Start from a random node and keep going to the subtree which is the heaviest.
5. Need to calculate the subtree size only once as propagating downwards.

---

### Q1: Find Summation of distances between all pairs of nodes in a tree (distance is the number of edges between two nodes).

**Naive Approach:**  
Do a DFS on each node and add (\( O(n^2) \)).

**Special Technique Needed:** Edge Contribution Technique

1. Every edge is counted some number of times.
2. Count the number of times each edge will be counted.
3. How many times the given edge will be part of the distance between any two pairs of nodes?
4. **Idea:** One-to-one correspondence between the edge and the vertex next to it.
5. **Formula:**
$$
\sum_{v=1}^{n} (\text{size of vertex}) \times (n - \text{size of vertex})
$$
(For the root vertex, size is equal to \( n \)).\
6. **Extra:** For a leaf node, its edge contributes a distance of \( \text{total nodes} - 1 \) because it connects to all other nodes in the tree through that single edge.

#### Q2: For a given tree, calculate $$ \max \left(|\text{val}[x] - \text{val}[y]|) \right)$$, where \( y \) is the ancestor of \( x \).

- Maintain **max** and **min** of the parent values (one of these two is the farthest).
- Use DFS (coded).

#### Q3: For a given tree, calculate $$ \min \left( |\text{val}[x] - \text{val}[y]| \right) $$, where \( y \) is the ancestor of \( x \).

- Need a data structure (DS) that can insert, erase, and give the closest to \( x \) at any point in time.
- Maintain a **multiset** along with DFS.
- Maintaining a DS with DFS helps to solve complex queries.

---

## Advanced Techniques
- **Data structures + Euler Tour**
- **Heavy Light Decomposition (HLD)**
- **Reachability**

