#!/usr/bin/python


"""
  Standard depth first search algorithm(s)
"""


class Vertex(object):
    """
      the vertex object for our graph
    """
    def __init__(self, data=None):
        if data == None:
            data = []
        self.data = data

    def set(self, data = []):
        self.data = data        

class Graph(object):
    """
      basic data structure to be searched
      this class stores the problem definition
      and is a collection of vertex/edge/data objects
    """
    def __init__(self, dict=None):
        if dict == None:
            dict = {}
        self.dict = dict

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
        print(v1, v2)
        if v1 in self.dict:
            self.dict[v1].append(v2) # connect v1 and v2

    def gen_edges(self):
        edges = []
        for v in self.dict:
            for neighbor in self.dict[v]:
                if {neighbor, v} not in edges:
                    edges.append([v, neighbor])
        return edges

    
if __name__ == "__main__":

    graph = Graph()
    
    graph.add_vertex(Vertex("v1"))
    graph.add_vertex(Vertex("v2"))
    graph.add_vertex(Vertex("v3"))
    graph.add_vertex(Vertex("v4"))
    
    vs = graph.vertices()
    print(vs[0].data)
    graph.add_edge({vs[0], vs[1]})
    graph.add_edge({vs[0], vs[2]})
    graph.add_edge({vs[0], vs[3]})
    
    edges = graph.edges()
    d = [ [e[0].data, e[1].data] for e in edges ]
    print(d)
