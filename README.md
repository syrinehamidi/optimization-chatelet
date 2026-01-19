# optimization-chatelet
Congestion-aware optimization of pedestrian flows at Châtelet–Les Halles using network flow models.
# optimization-chatelet
Congestion-aware optimization of pedestrian flows at Châtelet–Les Halles using network flow models.
1.Project description

Châtelet–Les Halles is one of the busiest transportation hubs in Europe, with several metro and RER lines intersecting in a complex underground network. During peak hours, pedestrian congestion can significantly increase travel times and create safety concerns.
The goal of this project is to model pedestrian flows inside a simplified representation of Châtelet–Les Halles and to optimize the routing of pedestrians while accounting for congestion effects. The project compares a classical shortest-path routing strategy with a congestion-aware optimization approach based on network flow models.
This work is inspired by concepts from operations research, network flow theory, and convex optimization.

2.Methods

The station is modeled as a directed graph, where:
Nodes represent major corridors, platforms, and access points.
Edges represent pedestrian corridors with: a travel time,a maximum capacity.
Two routing strategies are implemented and compared:

2.1 Shortest-path routing (baseline)

A baseline method where all pedestrians follow the path that minimizes total travel time, ignoring congestion effects. This approach typically concentrates flow on a small number of corridors and can lead to severe congestion.

2.2 Congestion-aware routing (optimization)

A congestion-aware routing strategy is formulated as a convex optimization problem. The objective minimizes:
total travel time, plus a congestion penalty proportional to the square of the flow divided by corridor capacity.
Flow conservation constraints and capacity constraints are enforced. The optimization problem is solved using CVXPY.

3.Experiments and results

The two routing strategies are compared by analyzing the load-to-capacity ratio on each corridor. Results show that:
shortest-path routing leads to highly uneven flow distribution,congestion-aware optimization distributes pedestrians more evenly across the network,congestion levels are significantly reduced.
A comparison figure is automatically generated and saved in the figures/ directory.

4.Project structure
optimization-chatelet/
│
├── network.py           # Network graph construction
├── shortest_path.py     # Shortest-path baseline routing
├── congestion_flow.py   # Congestion-aware optimization model
├── experiments.py       # Experimental comparison and plotting
├── requirements.txt     # Python dependencies
├── figures/
│   └── comparison.png   # Load/capacity comparison figure
└── README.md

5.How to run the project
5.1 Install dependencies
pip install -r requirements.txt

5.2 Run experiments
python experiments.py
This will generate the comparison figure:
figures/comparison.png

6.Technologies used
Python 3 , NetworkX , CVXPY , Matplotlib , NumPy , Course context
This project was developed as part of an Operations Research course. It applies concepts from: network flow models,shortest-path algorithms, convex optimization,congestion modeling.

7.Authors
Syrine Hamidi and Emilie Arrive-Bannier

8.Notes
The network structure and demand values are simplified representations intended for educational purposes. The framework can be extended to larger networks or real-world datasets.
