#ifndef FUNC_H
#define FUNC_H

#define MAX_NODES 65536
#define min(A,B) ((A)<=(B)?(A):(B))

struct node {
  int name;
  int type;
  struct node *next;
};

struct node *desti, *source, *newNode, *temp, *pCrawl;

struct Graph {
    int num_V; // number of nodes
    struct node ** a_list_c; //adjacency list
    struct node ** a_list_r; //adjacency list
    struct node ** a_list_p; //adjacency list

    struct node ** bgp_clients; //adjacency list
    int * a_list; //adjacency list
    int * tier1; //stores tier 1 nodes
    int n_tier1; //number of tier 1 nodes
};

struct Queue {
  int * array; //stores sons of visited nodes
  int count; //number of items in queue
  int head; //location to pop from
  int tail;  //location to push from
};

struct Graph *graph;
struct Queue queue;

struct node * createNode(int id_node, int type);
struct Graph* createGraph();
struct Queue* createQueue();
void addEdge(struct Graph* graph, int src, int dest, int type);
void printGraph(struct Graph* graph);
int findTier1(struct Graph* graph);
int pop_queue(struct Queue* queue);
int push_queue(struct Queue* queue, int a);
int CommerciallyConn(struct Graph* graph);
void check_length_type(struct Graph * graph, struct Queue * queue, int src, int dest, int question);
int BGP(struct Graph * graph, struct Queue * queue, int src, int * length, int * curr_type,
      int * final_length, int * final_type, int source, int dest, int question);
void check_length_shortest(struct Graph * graph, struct Queue * queue, int src, int dest, int question);
int BGP_shortest(struct Graph * graph, struct Queue * queue, int src, int * length,int * length_p, int * length_r, int * length_c,
      int * curr_type, int * final_length, int * final_type, int source, int dest, int question);

void freeAll(struct Graph* graph, struct Queue * queue);

#endif