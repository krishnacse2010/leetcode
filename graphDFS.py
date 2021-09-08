from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list) ;#Pass callable , so not list()

    def addEdge(self,v,e):
        # For undirected graph we need to add both v <-> e
        self.graph[v].append(e)
        self.graph[e].append(v)

    def DFS(self,s,seenVertex):
        #add vertex
        seenVertex.add(s)
        
        #Call recursively the neighbours and add if not already added using the set
        for elem in self.graph[s]:
            if elem not in seenVertex:
                self.DFS(elem,seenVertex)





g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

# Using set DS to ensure vertex is added only once
print(g.DFS(2,set()))
