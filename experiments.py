import matplotlib.pyplot as plt
from shortest_path import shortest_path_routing
from congestion_flow import congestion_aware_routing
from network import build_network

def run_experiment():
    G = build_network()
    sp_flows, _ = shortest_path_routing()
    ca_flows = congestion_aware_routing()

    labels = []
    sp_load = []
    ca_load = []

    for edge in G.edges:
        labels.append(f"{edge[0]}→{edge[1]}")
        sp_load.append(sp_flows.get(edge, 0) / G[edge[0]][edge[1]]["capacity"])
        ca_load.append(ca_flows.get(edge, 0) / G[edge[0]][edge[1]]["capacity"])

    x = range(len(labels))
    plt.bar(x, sp_load, width=0.4, label="Shortest path")
    plt.bar([i + 0.4 for i in x], ca_load, width=0.4, label="Congestion-aware")

    plt.xticks(x, labels, rotation=45)
    plt.ylabel("Load / Capacity")
    plt.legend()
    plt.tight_layout()
    plt.savefig("figures/comparison.png")
