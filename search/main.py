#!/usr/bin/python

import graph as G
import dfs as D



if __name__ == "__main__":
    
    graph = G.Graph()
    graph.add_vertex(G.Vertex("a"))

    graph.add_vertex(G.Vertex("b"))
    graph.add_edge({graph.find("a"), graph.find("b")})    

    graph.add_vertex(G.Vertex("c"))
    graph.add_edge({graph.find("c"), graph.find("b")})

    graph.add_vertex(G.Vertex("d"))
    graph.add_edge({graph.find("d"), graph.find("c")})

    graph.add_vertex(G.Vertex("e"))
    graph.add_edge({graph.find("e"), graph.find("d")})

    
    depth_first = D.DFS(graph)
    depth_first.search(graph.find("a"))
