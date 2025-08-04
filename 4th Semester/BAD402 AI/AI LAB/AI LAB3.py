import heapq

def a_star_search(graph, start, goal, heuristic):
    open_list = []  # Priority queue for A*
    heapq.heappush(open_list, (0, start))  # (f-score, node)
    came_from = {}  # To store the path
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0
    f_score = {node: float('inf') for node in graph}
    f_score[start] = heuristic[start]
    
    while open_list:
        current_f, current = heapq.heappop(open_list)
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]  # Return reversed path
        
        for neighbor, cost in graph[current].items():
            tentative_g_score = g_score[current] + cost
            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic[neighbor]
                heapq.heappush(open_list, (f_score[neighbor], neighbor))
    
    return None  # No path found

# Example Graph (Adjacency List with Costs)
graph = {
    'A': {'B': 3, 'C': 4},
    'B': {'A': 3, 'C': 6, 'D': 5},
    'C': {'A': 4, 'B': 6, 'D': 1, 'E':2},
    'D': {'B': 5, 'C': 1, 'E': 8},
    'E': {'D': 8, 'C':2, 'F':1},
    'F':{'E':1}
}

# Example Heuristic Values (Straight-line distance to goal)
heuristic = {'A': 8, 'B': 6, 'C': 5, 'D': 4, 'E': 3,'F':0}

start = 'A'
goal = 'F'
path = a_star_search(graph, start, goal, heuristic)
print("Shortest path using A*:", path)

