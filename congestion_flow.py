import cvxpy as cp
from network import build_network

def congestion_aware_routing(total_demand=1000, alpha=0.01):
    G = build_network()
    edges = list(G.edges)

    flow = {e: cp.Variable(nonneg=True) for e in edges}

    objective = cp.Minimize(
        sum(
            G[e[0]][e[1]]["time"] * flow[e]
            + alpha * cp.square(flow[e]) / G[e[0]][e[1]]["capacity"]
            for e in edges
        )
    )

    constraints = []

    for node in G.nodes:
        inflow = sum(flow[e] for e in edges if e[1] == node)
        outflow = sum(flow[e] for e in edges if e[0] == node)

        if node == "RER":
            constraints.append(outflow - inflow == total_demand)
        elif node.startswith("L"):
            constraints.append(inflow - outflow == total_demand / 5)
        else:
            constraints.append(inflow == outflow)

    for e in edges:
        constraints.append(flow[e] <= G[e[0]][e[1]]["capacity"])

    problem = cp.Problem(objective, constraints)
    problem.solve()

    return {e: flow[e].value for e in edges}
