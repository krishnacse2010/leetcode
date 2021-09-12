import heapq


def calculate_distances(graph, starting_vertex):
    distances = {v:float('infinity') for v in graph}
    distances[starting_vertex] = 0

    pq = [(0,starting_vertex)]
    visited = set()
    while len(pq) > 0:
            # take the current vertex and current distance which is initially the starting vertex
            #then we pop the least one from the graph
            currentDistance , vertex = heapq.heappop(pq)

            # if already visited leave it
            if vertex in visited:
                    continue

            # check all the vertex distance of all edges from current vertex based on input

            for vertex , distance1 in graph[vertex].items():
                    # calculate the distance by current Distance and value in the input
                    distance = currentDistance + distance1
                    # if the distance is smaller than the distances where we contructed infinity
                    # initially all will be smaller than inifinity
                    # all distances from starting vertex along with vertex pushed to distances
                    # then starts the heapq logic
                    if distance < distances[vertex]:

                            #update the distances where everything vertex is infinity
                            distances[vertex] = distance
                            #push to heap
                            heapq.heappush(pq,(currentDistance + distance1,vertex))
    # Distances will have all the best path to the vertex
    return distances





    print(distances)

example_graph = {
        'U': {'V': 2, 'W': 5, 'X': 1},
        'V': {'U': 2, 'X': 2, 'W': 3},
        'W': {'V': 3, 'U': 5, 'X': 3, 'Y': 1, 'Z': 5},
        'X': {'U': 1, 'V': 2, 'W': 3, 'Y': 1},
        'Y': {'X': 1, 'W': 1, 'Z': 1},
        'Z': {'W': 5, 'Y': 1},
}
print(calculate_distances(example_graph, 'X'))