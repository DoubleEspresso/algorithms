#!/usr/bin/python


import graph as G


class DFS(object):
    """
      standard depth first search of a graph
    """
    def __init__(self, g):
        self.G.graph = g
        self.dict = {}
        
    def search(self, vertex):
        """searches a graph starting a vertex and touches all vertices connected"""
        stack = []
        stack.append(vertex)
        
        while stack:
            v = stack.pop()
            print(v.data)
            if not v.visited:
                v.visited = True
                [ stack.append(w) for w in G.graph.connected(v.data) ]
                
