## Flow for Solving Graph Problems

### Abstracting the Graph from the Problem Statement

1. **Identify the Graph**:
   - what represents the graph in the problem?
   - how nodes (vertices) are defined?
   - transitions and state changes to create edges based on the problem rules.

2. **Recognize the Graph Problem Type**:
   - **DFS/BFS-based**: Component-related, cycle detection, or bipartite checking problems.
   - **Shortest Path**: shortest path computations.
   - **Topological Problem**: Ordering-related problems.
   - **MST (Minimum Spanning Tree)**: Finding the minimum cost to connect all nodes.
   - **Articulation-Based**: Finding articulation points or bridges.

### Modeling the Problem
- shortest path or tree-based problems require more attention.
---

### Algorithms for Shortest Path Problems

#### Single Source Shortest Path (SSSP)

1. **BFS** O(V + E): 
   - Unweighted graphs.

2. **0-1 BFS** O(V + E):
   - Edge weights of 0 and 1.
   - U deque (double-ended queue) 

3. **Dijkstra’s Algorithm** O((V + E) log V):
   - non-negative edge weights.
   - Uses a priority queue (min-heap)

4. **Bellman-Ford Algorithm** O(V * E):
   -  negative edge weights.
   - detects negative weight cycles.

> **Note**: All the above algorithms are suitable for SSSP.

#### Multi-Source Shortest Path (MSSP)

- Initialize the distance of all sources to 0.
- Add all sources into a queue (or priority queue for Dijkstra’s).

#### All Pair Shortest Path (APSP)
** Use sssp from every source O(V.(sssp))
5. **Floyd-Warshall Algorithm** O(V^3):
   - Uses dp 

---

### Key Takeaways

- Abstract graph
- identify problem
- Select appropriate algorithm (based on the graph’s properties and requirements).
- Pay attention components (nodes, edges, weights) 

---

