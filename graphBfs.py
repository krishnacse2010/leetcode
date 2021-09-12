from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list) ;#Pass callable , so not list()

    def addEdge(self,v,e):
        print(f'Adding to Vertex{v} edge{e}',self.graph[v])
        self.graph[v].append(e)
        self.graph[e].append(v)

    def BFS(self,s):
        #visited[0] will always be False
        visited = [False] * (len(self.graph) + 1)

        queue = []
        queue.append(s)
        visited[s] = True
        while len(queue):

            visitedVertex = queue.pop(0)
            visited[visitedVertex] = True
            #print(self.graph[s])
            print(f'Visited {visitedVertex}')
            #print(self.graph[visitedVertex],len(queue))
            for elem in self.graph[visitedVertex]:

                if visited[elem] == False:
                    queue.append(elem)
                    visited[elem] = True




g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 2)

print(g.BFS(0))