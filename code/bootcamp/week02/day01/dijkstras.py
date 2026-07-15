# en kısa node bul
# bulduğun node'dan komşulara gitmeyi hesapla maliyetleri güncelle
# tekrarla (bütün nodelar bitene kadar)

def dijkstra(graph, start, target):
    costs = {}
    parents = {}
    unvisited = set(graph.keys())
    for k in graph.keys():
        if k == start:
            costs[start] = 0
            continue
        costs[k] = float('inf')
            
    while unvisited:
        shortest = min(unvisited, key=lambda node:costs[node])
        if costs[shortest] == float('inf'):
            break
        if shortest == target:
            break
        for k in graph[shortest]:
            new_cost = graph[shortest][k] + costs[shortest]
            if costs[k] > new_cost:
                costs[k] = new_cost
                parents[k] = shortest
        unvisited.remove(shortest)
    
    current = target
    path = []
    while current != start:
        path.append(current)
        current = parents[current]
    path.append(start)
    print(" -> ".join(path[::-1]))
    return parents, costs
            


# test
graph = {
    'A': {'B': 2, 'C': 5},
    'B': {'C': 1, 'D': 6},
    'C': {'D': 2},
    'D': {}
}

# test 2
graph2 = {
    'A': {'B': 4, 'C': 3},
    'B': {'C': 1, 'D': 2, 'E': 7},
    'C': {'D': 4, 'F': 6},
    'D': {'E': 1, 'F': 2},
    'E': {'G': 3},
    'F': {'G': 1},
    'G': {}
}

p,c = dijkstra(graph2,'A','G')