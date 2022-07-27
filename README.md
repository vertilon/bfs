# Example algorithm for Breadth First Search
Implementation of BFS algorithm that finds shortest path from specified node.

Compiled executable gets input from stdout, data is entered in next format:
* first row accepts 3 numbers with space " " as a delimiter, sygnifying number of nodes, number of connections(edges) between them, and numerical node id(starting from 1) for which to find shortest path
* all other rows specifies connections between nodes in the next format - node id, next id and weight(distance)

## Test
1. There's sample.txt provided with nodes and connections between them, so it's easy to check how it works and what is the data format program accepts
2. To build and test, please run:
```
make
make test
```
