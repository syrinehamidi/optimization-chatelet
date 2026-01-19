import networkx as nx
from network import build_network

def shortest_path_routing(demand=1000):
    G = build_network()

    path = nx.shortest_path(G, source="RER", target="L1", weight="time")

    flows = {edge: 0 for edge in G.edges}

    for i in range(len(path) - 1):
        edge = (path[i], path[i + 1])
        flows[edge] += demand

    return flows, path
