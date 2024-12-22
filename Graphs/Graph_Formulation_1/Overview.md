## Flow for Solving Graph Problems

### Abstracting the Graph from the Problem Statement

1. **Identify the Graph**:
   - Determine what represents the graph in the problem.
   - Understand how nodes (vertices) are defined.
   - Analyze transitions and state changes to create edges based on the problem rules.

2. **Recognize the Graph Problem Type**:
   - **DFS/BFS-based**: Component-related, cycle detection, or bipartite checking problems.
   - **Shortest Path**: Problems requiring shortest path computations.
   - **Topological Problem**: Ordering-related problems.
   - **MST (Minimum Spanning Tree)**: Finding the minimum cost to connect all nodes.
   - **Articulation-Based**: Finding articulation points or bridges.

### Modeling the Problem
- For shortest path or tree-based problems, accurately model the graph:
  - Define the structure clearly.
  - Ensure edges and weights are appropriately represented.

---

### Algorithms for Shortest Path Problems

#### Single Source Shortest Path (SSSP)

1. **BFS**:
   - Used for unweighted graphs.
   - Efficient for shortest paths when edge weights are uniform.

2. **0-1 BFS**:
   - Optimized for graphs with edge weights of 0 and 1.
   - Utilize a deque (double-ended queue) for traversal.

3. **Dijkstra’s Algorithm**:
   - Handles graphs with non-negative edge weights.
   - Uses a priority queue (min-heap) for optimal performance.

4. **Bellman-Ford Algorithm**:
   - Works with negative edge weights.
   - Can detect the presence of negative weight cycles.

> **Note**: All the above algorithms are suitable for SSSP.

#### Multi-Source Shortest Path (MSSP)

- Initialize the distance of all sources to 0.
- Add all sources into a queue (or priority queue for Dijkstra’s).

#### All Pair Shortest Path (APSP)

5. **Floyd-Warshall Algorithm**:
   - Solves APSP problems.
   - Uses dynamic programming to compute shortest paths between all pairs of nodes.

---

### Key Takeaways

- Start by abstracting the graph and identifying the problem type.
- Select the appropriate algorithm based on the graph’s properties and the problem’s requirements.
- Pay attention to the graph’s components (nodes, edges, weights) for accurate modeling.

---

