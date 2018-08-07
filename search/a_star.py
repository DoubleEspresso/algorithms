#!/usr/bin/python

from graph import Graph

class AStar(object):
    def __init__(self, data):
        self.g = Graph()
        self.data = data
        self.dirs = [[0,1], [0,-1], [-1,0], [1,0]]
        self.rows = len(data)
        self.cols = len(data[0])
        self.goal = -1
        self.walls = []
        self.init()

    def init(self):
        for r in range(self.rows):
            for c in range(self.cols):
                if self.data[r][c] == 1: self.walls.append((r, c))
                elif self.data[r][c] == 2: self.goal = (r, c)

    def dist(self, p1, p2):
        return abs(p1[0]-p2[0]) + abs(p1[1] - p2[1])

    def in_maze(self, p):
        return (p[0] >= 0 and p[0] < self.rows and p[1] >= 0 and p[1] < self.cols)


    def path(self, camefrom, current):
        total_path = [current]
        while current in camefrom.keys():
            current = camefrom[current]
            total_path.append(current)
        return list(reversed(total_path))

    
    def neighbors(self, node):
        n = []
        for d in self.dirs:
            p = (node[0] + d[0], node[1] + d[1])
            if self.in_maze(p): n.append(p)
        return n


    def idx(self, p):
        return p[0] * self.rows + p[1]


    def search(self, start, goal):
        visited = []
        open = [start]
        
        camefrom = {}
        score = {}
        fscore = {}
        for r in range(len(self.data)):
            for c in range(len(self.data[0])):
                score[(r,c)] = 999
                fscore[(r,c)] = 999

        score[start] = 0
        fscore[start] = self.dist(start, goal)

        while open:

            min = 999
            current = None
            for o in open:
                if fscore[o] < min:
                    current = o
                    min = fscore[o]

            if current == goal: 
                return self.path(camefrom, current)

            open.remove(current)
            visited.append(current)

            for neighbor in self.neighbors(current):

                if neighbor in visited: continue
                if neighbor in self.walls: continue

                s = score[current] + 1
                
                if neighbor not in open:
                    open.append(neighbor)
                elif s >= score[neighbor]:
                    continue # not a better path

                    
                camefrom[neighbor] = current
                score[neighbor] = s
                fscore[neighbor] = s + self.dist(neighbor, goal)



if __name__ == "__main__":
    maze = [
        [0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 1, 0],
        [2, 1, 0, 1, 0, 0, 0],
        [0, 1, 1, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 1, 0]
    ]

    astar = AStar(maze)
    path = astar.search((0,0), (2,0))

    print(path)

