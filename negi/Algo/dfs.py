from queue import Queue

class Graph:
    def __init__(self, num_of_nodes):
        self.m_num_of_nodes = num_of_nodes
        self.m_nodes = range(self.m_num_of_nodes)

        # Graph representation - Adjacency list
        self.m_adj_list = {node: set() for node in self.m_nodes} 
        self.visited = set()     
	
    # Add edge to the graph
    def add_edge(self, node1, node2):
        self.m_adj_list[node1].add(node2)
        self.m_adj_list[node2].add(node1)

        # A function used by DFS
    def DFS(self, v):
        # Mark the current node as visited
        # and print it
        self.visited.add(v)
        print(v, end=' ')
 
        # Recur for all the vertices
        # adjacent to this vertex
        for neighbour in self.m_adj_list[v]:
            if neighbour not in self.visited:
                self.DFS(neighbour)

graph = Graph(6)

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(0, 4)
graph.add_edge(1, 2)
graph.add_edge(2, 5)
graph.add_edge(3, 4)
graph.add_edge(3, 5)
graph.add_edge(4, 5)

graph.DFS(0)