import networkx as nx

def build_network():
    G = nx.DiGraph()

    # Nodes
    nodes = [
        "RER", "N1", "N2",
        "L1", "L4", "L7", "L11", "L14"
    ]
    G.add_nodes_from(nodes)

    # Edges: (from, to, capacity, travel_time)
    edges = [
        ("RER", "N1", 1200, 2),
        ("N1", "N2", 960, 2),
        ("N1", "L1", 800, 3),
        ("N1", "L4", 750, 3),
        ("N1", "L14", 750, 3),
        ("N2", "L7", 700, 3),
        ("N2", "L11", 500, 3),
        ("L4", "RER", 500, 2),
    ]

    for u, v, cap, time in edges:
        G.add_edge(u, v, capacity=cap, time=time)

    return G
