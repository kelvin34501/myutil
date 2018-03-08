#ifndef __MYUTIL_GRAPH_H__
#define __MYUTIL_GRAPH_H__

#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "vector_template.h"

/* enum */
typedef enum {
        VERTEX_UNDISCOVERED,
        VERTEX_DISCOVERED,
        VERTEX_VISITED
} v_status;

typedef enum {
        EDGE_UNDETERMINED,
        EDGE_TREE,
        EDGE_CROSS,
        EDGE_FORWARD,
        EDGE_BACKWORD
} e_status;

/* vertex */
typedef struct _vertex vertex;
struct _vertex {
        int data;

        int i_degree, o_degree;
        v_status status;
        int d_time, f_time;
        int parent;
        int priority;
};

void vertex_init(vertex * p_vertex, int d);

/* edge */
typedef struct _edge edge;
struct _edge {
        int weight;
        e_status status;
};

void edge_init(edge ** pp_edge,  int w);
void edge_cleanup(edge ** pp_edge);

/* graph */
vector_(vertex,vertex)
vector_(edge,edge *)
vector_(vector_edge,vector_edge)

typedef struct _graph graph;
struct _graph {
        int n_vertex;
        int n_edge;
        vector_vertex v_vertex;
        vector_vector_edge adj_matrix;
};

void graph_init(graph * p_graph);
void graph_insert_vertex(graph * p_graph, int d);
void graph_insert_edge(graph * p_graph, int i, int j, int w);
void graph_remove_edge(graph * p_graph, int i, int j);
void graph_remove_vertex(graph * p_graph, int i);
int graph_incident(graph * p_graph, int i, int j);
void graph_vertex_neibour(int i_vertex, int * p_cursor);
void graph_cleanup(graph * p_graph);
void graph_debug();

#endif
