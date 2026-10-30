🏫 Campus Route Finder Using Graphs (C)

📌 Project Overview

Campus Route Finder is a mini project developed using the C programming language and Data Structures. It uses Graphs to represent different locations on a college campus and helps users find the shortest route between two locations.

The project implements Breadth-First Search (BFS), Depth-First Search (DFS), and graph traversal techniques to explore campus locations and check connectivity.

🎯 Objectives

- To understand Graph data structures.
- To implement Breadth-First Search (BFS).
- To implement Depth-First Search (DFS).
- To find the shortest path between campus locations.
- To check connectivity and reachability.
- To understand adjacency list representation.

✨ Features

- Display Campus Graph.
- Find Shortest Route using BFS.
- Explore Campus using DFS.
- Check Reachability of locations.
- Identify disconnected locations.
- Menu-driven interface.
- User input validation.

🛠️ Technologies Used

- Programming Language: C
- Data Structure: Graph
- Graph Representation: Adjacency List
- Algorithms: BFS and DFS
- Header Files: stdio.h, string.h
- Platform: GitHub

🧠 DSA Concepts Implemented

1. Graph

Represents campus locations as vertices and paths as edges.

2. Adjacency List

Stores connections between different campus locations.

3. Breadth-First Search (BFS)

Finds the shortest path between two locations in an unweighted graph.

4. Depth-First Search (DFS)

Explores connected campus locations using a stack.

5. Reachability

Identifies reachable and disconnected locations.

📍 Campus Locations

1. Main Gate
2. Library
3. Block 1
4. Block 2
5. Cafeteria
6. Auditorium
7. Parking
8. Lab
9. Medical Centre

Note: Medical Centre is intentionally kept disconnected to demonstrate graph connectivity.

⏱️ Time Complexity

Operation| Complexity
Add Edge| O(1)
Display Graph| O(V + E)
BFS| O(V + E)
DFS| O(V + E)
Reachability| O(V + E)
Find Location| O(V)

Where V = Vertices and E = Edges.

▶️ How to Run the Project

1. Download or clone the repository.
2. Open the project in a C compiler.
3. Open "main.c".
4. Compile and execute the program.

GCC Commands

gcc main.c -o campus
./campus

📋 Main Menu

===== CAMPUS ROUTE FINDER =====

1. Display Campus Graph
2. Find Shortest Route (BFS)
3. Explore Campus (DFS)
4. Check Reachability
5. Exit

Enter your choice:

📸 Sample Output

Shortest Route (BFS)

Enter your choice: 2

Enter source location: Main Gate
Enter destination location: Auditorium

Shortest Route:
Main Gate -> Library -> Cafeteria -> Auditorium

Number of edges: 3

Reachability

Reachable Locations:
Main Gate
Library
Block 1
Block 2
Cafeteria
Auditorium
Parking
Lab

Disconnected Locations:
Medical Centre

📂 Project Structure

Campus-Route-Finder/
│
├── README.md
└── main.c

🚀 Future Improvements

- Add more campus locations.
- Implement weighted graphs.
- Calculate actual distances.
- Add an interactive campus map.
- Develop a graphical user interface.
- Implement Dijkstra's shortest path algorithm.

👨‍💻 Developer

Shahzad Chauhan

B.Tech – Artificial Intelligence & Data Science

GitHub: "@shahzadChauhan" (https://github.com/shahzadChauhan)

GitHub Profile: https://github.com/shahzadChauhan

📜 Conclusion

The Campus Route Finder project demonstrates the practical implementation of Graph data structures and traversal algorithms in C. It helps users understand BFS, DFS, shortest path finding, adjacency list representation, and graph connectivity through a real-world campus navigation example.

---

⭐ If you find this project useful, don't forget to star the repository!
