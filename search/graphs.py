#!/usr/bin/python

"""
  Standard depth first search algorithm(s)
"""

class Graph(object):
    def __init__(self, dict=None, search_algo=None):
        if dict == None:
            dict = {}
        self.dict = dict
        self.search_algo = search_algo

    def vertices(self):
        return list(self.dict.keys())

    def edges(self):
        return self.gen_edges()

    def add_vertex(self, vertex):
        """
          add a vertex to the dictionary if it isn't there
        """
        if vertex not in self.dict:
            self.dict[vertex] = []

    def add_edge(self, edge):
        """
          edge is of type set, tuple or list
          multiple edges are possible between 2 vertices
          assume edge is a tuple of Vertices
        """
        edge = set(edge) # remove duplicates
        (v1, v2) = tuple(edge)
        print((v1, v2))
        if v1 in self.dict:
            self.dict[v1].append(v2) # connect v1 and v2

    def gen_edges(self):
        edges = []
        for v in self.dict:
            for neighbor in self.dict[v]:
                if {neighbor, v} not in edges:
                    edges.append((v, neighbor))
        return edges

    def vertex_degree(self, vertex):
        """defined to be the number of edges connected to this vertex"""
        adj_vertices = self.dict[vertex]
        return len(adj_vertices) + adj_vertices.count(vertex)

    def degree_seq(self):
        seq = []
        for vertex in self.dict:
            seq.append(self.vertex_degree(vertex))
        seq.sort(reverse=True)
        return tuple(seq)        

    def find_all_paths(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            return [path]
        paths = []
        for vertex in self.dict[start]:
            if vertex not in path:
                extended_paths = self.find_all_paths(vertex, end, path)
            for p in extended_paths:
                paths.append(p)
        return paths

    def diameter(self):
        v = self.vertices()
        pairs = [ (v[i], v[j]) for i in range(len(v)-1) for j in range(i+1, len(v)) ]
        smallest_paths = []
        for (s, e) in pairs:
            paths = self.find_all_paths(s, e)
            smallest_paths.append(sorted(paths, key = len)[0])
            
            smallest_paths.sort(key = len)
        # longest path is at the end of the list
        return len(smallest_paths[-1]) - 1

    def find_path(self, start, end, path=[], path_algo=None):
        if path_algo: return path_algo(start, end)
        else return sorted(self.find_all_paths(start, end, path))[0]

if __name__ == "__main__":

    g = { "a" : ["d"],
          "b" : ["c"],
          "c" : ["b", "c", "d", "e"],
          "d" : ["a", "c"],
          "e" : ["c"],
          "f" : [] }

    graph = Graph(g)
    print(graph.find_path("a", "e"))
    print(graph.vertices())
    print(graph.edges())



