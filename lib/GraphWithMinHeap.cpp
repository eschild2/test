#include "GraphWithMinHeap.h"
#include "DList.h"
#include "IntegerSet.h"
#include "Queue.h"
#include <climits>
#include <stdio.h>

namespace ece309{
class node_helper {
        public:
            node_helper() {
            distance = 1000000;
            pred = -1;
        }
        int distance;
        int pred;
        };

        class minHeap{
        public:
        int *heapArray;    // this is the minheap
        int heapArraySize; // size of the array
        int nextIndex;     // location of next free array entry
        node_helper *nodesH;
        minHeap(int size = 100, node_helper* n=NULL){
            heapArraySize = size;
            heapArray = new int[size];
            for (int i = 0; i < size; i++){
                heapArray[i] = 0; // initialize heap to zero
            }
            nextIndex = 0;
            nodesH = new node_helper[size];
            for(int i = 0; i < size; i++){
                nodesH[i].distance = n[i].distance;
                nodesH[i].pred = n[i].pred;
            }
        }
        void print(){
            for (int i = 0; i < nextIndex; i++) {
                printf("%d ", heapArray[i]);
            }
            printf("\n");
        }
           
            
        bool insert(int data){
            if (nextIndex < heapArraySize) {
            heapArray[nextIndex] = data;
                return true;
            } else {
                return false;
            }
        }
        
        void percolate_up(int index, node_helper* nodesH){
            while (index > 0) {
            int parent_index = (index - 1) / 2;
            if (nodesH[index].distance < nodesH[parent_index].distance) {
                int tmp = heapArray[index];
                heapArray[index] = heapArray[parent_index];
                heapArray[parent_index] = tmp;
                index = parent_index;
            } else
                return;
            }
            }
        };


SparseGraph::SparseGraph(int n) : Graph(n) { nodes = new Node[numNodes]; }

void SparseGraph::addEdge(int v1, int v2) {
  nodes[v1].edge.append(v2);
  nodes[v2].edge.append(v1);
}

bool SparseGraph::isAdjacent(int v1, int v2) const {
  List::iterator it = nodes[v1].edge.begin();
  while (!it.end()) {
    if (it.getItem() == v2) {
      return true;
    }
    it.increment();
  }
  return false;
}

DenseGraph::DenseGraph(int n) : Graph(n) {
  edges = new bool[numNodes * numNodes];
  for (int i = 0; i < numNodes * numNodes; i++)
    edges[i] = false;
}
void DenseGraph::addEdge(int v1, int v2) {
  edges[v1 * numNodes + v2] = true;
  edges[v2 * numNodes + v1] = true;
}

bool DenseGraph::isAdjacent(int v1, int v2) const {
  return edges[v1 * numNodes + v2];
}

bool doesPathExist(Graph &g, int *path, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (!g.isAdjacent(path[i], path[i + 1]))
      return false;
  }
  return true;
}

void visit(int node) { printf("%d ", node); }

void BreadthFirstSearch(Graph &graph, int start) {
  IntegerSetHT discovered(1000);
  Queue frontier;
  frontier.push(start);
  discovered.insert(start);
  while (!frontier.empty()) {
    int node = frontier.peek();
    visit(node);
    List adjList = graph.getAdjacencyList(node);
    List::iterator it = adjList.begin();
    while (!it.end()) {
      int j = it.getItem();
      if (!discovered.search(j)) {
        frontier.push(j);
        discovered.insert(j);
      }
      it.increment();
    }
    frontier.pop();
  }
}

void DepthFirstSearch_helper(Graph &g, IntegerSet &visitedSet, int node) {
  if (!visitedSet.search(node)) {
    visit(node); // take action upon visit to node
    visitedSet.insert(node);
    List adjList = g.getAdjacencyList(node);
    for (List::iterator it = adjList.begin(); !it.end(); it.increment())
      DepthFirstSearch_helper(g, visitedSet, it.getItem());
  }
}

void DepthFirstSearch(Graph &g, int node) {
  IntegerSetHT ht(1000);
  DepthFirstSearch_helper(g, ht, node);
}

void WeightedDenseGraph::addWeight(int from, int to, int weight) {
  weights[from * numNodes + to] = weight;
  weights[to * numNodes + from] = weight;
}

void WeightedDenseGraph::addEdge(int from, int to, int weight) {
  addEdge(from, to);
  addWeight(from, to, weight);
  
}

node_helper* ShortestPath(Graph &g, int startV) {

    int numNodes = g.getNumNodes();
    node_helper *nodesH = new node_helper[numNodes]; //an array of node helpers

    nodesH[startV].distance = 0; //distance from startV to self is 0
    minHeap m(numNodes, nodesH); //create a new minHeap
    
    int min_node = 0;
    
    int min_distance = nodesH[min_node].distance;
    
    for(int i = 0; i < numNodes; i++){
        m.insert(i);
        if(nodesH[i].distance < min_distance){
            min_node = i;
            min_distance = nodesH[min_node].distance;
        }
        int currentV = min_node;
        List adjList = g.getAdjacencyList(currentV);
        for (List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
            int toNode = lit.getItem();
            if (g.getWeight(currentV, toNode) + min_distance <
            nodesH[toNode].distance) {
                nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
                nodesH[toNode].pred = currentV;
            }
        }
    m.percolate_up(m.nextIndex, nodesH);
    m.nextIndex++; 
    }  
  return nodesH;
}

int main() {

  SparseGraph g(14);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);

  g.addEdge(1, 4);
  g.addEdge(3, 5);
  g.addEdge(2, 6);
  g.addEdge(3, 6);
  g.addEdge(2, 7);
  g.addEdge(1, 8);
  g.addEdge(7, 8);
  g.addEdge(1, 9);
  g.addEdge(4, 10);
  g.addEdge(6, 11);
  g.addEdge(7, 12);
  g.addEdge(8, 13);

  /*  int path[3] = {0, 1, 9};
    if (doesPathExist(g, path, 3))
      printf("Exists!\n");*/

  printf("BFS(0)=");
  BreadthFirstSearch(g, 0);
  printf("\nBFS(13)=");

  BreadthFirstSearch(g, 13);

  printf("\nDFS(0): ");
  DepthFirstSearch(g, 0);

  printf("\nDFS(13): ");
  DepthFirstSearch(g, 13);

  WeightedDenseGraph wg(6);
  wg.addEdge(0, 1, 450);
  wg.addEdge(0, 3, 150);
  wg.addEdge(0, 2, 370);
  wg.addEdge(1, 3, 550);
  wg.addEdge(2, 4, 210);
  wg.addEdge(3, 4, 370);
  wg.addEdge(3, 5, 340);
  wg.addEdge(2, 5, 130);
  wg.addEdge(4, 5, 5);

  printf("\nwg DFS(0): ");
  DepthFirstSearch(wg, 0);
  printf("\n\n");

  node_helper *nodesH = ShortestPath(wg, 0);

 printf("My algorithm produces the following results:\n");
  for (int j = 0; j < wg.getNumNodes(); j++) {
    printf("%d: dist=%d pred=%d \n", j, nodesH[j].distance, nodesH[j].pred);
  }
  printf("What the algorithm should print:\n");
  
  printf("0: dist=0 pred=-1\n1: dist=450 pred=0\n2: dist=370 pred=0\n");
  printf("3: dist=150 pred=0\n4: dist=495 pred=5\n5: dist=490 pred=3\n");

  return 0;
}
}