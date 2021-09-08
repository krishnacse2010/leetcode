from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list) ;#Pass callable , so not list()

    def addEdge(self,v,e):
        print(f'Adding to Vertex{v} edge{e}',self.graph[v])
        self.graph[v].append(e)
        self.graph[e].append(v)

    def DFS(self,s,seenVertex):

        seenVertex.add(s)
        print(s)
        #print(self.graph[s])
        for elem in self.graph[s]:
            if elem not in seenVertex:
                self.DFS(elem,seenVertex)




g = Graph()
g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

print(g.DFS(2,set()))
