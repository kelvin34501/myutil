#include "graph.h"

/* vertex */
void vertex_init(vertex * p_vertex, int d)
{
        p_vertex->data = d;
        p_vertex->i_degree = p_vertex->o_degree = 0;
        p_vertex->status = VERTEX_UNDISCOVERED;
        p_vertex->d_time = p_vertex->f_time = 0;
        p_vertex->parent = 0;
        p_vertex->priority = INT_MAX;
}

/* edge */
void edge_init(edge ** pp_edge, int w)
{
        (*pp_edge) = malloc(sizeof(edge));
        (*pp_edge)->weight = w;
        (*pp_edge)->status = EDGE_UNDETERMINED;
}

void edge_cleanup(edge ** pp_edge)
{
        free(*pp_edge);
        (*pp_edge) = NULL;
}

/* graph */
void graph_init(graph * p_graph)
{
        p_graph->n_vertex = 0;
        p_graph->n_edge = 0;
        vector_vertex_init(&(p_graph->v_vertex));
        vector_vector_edge_init(&(p_graph->adj_matrix));
}

void graph_insert_vertex(graph * p_graph, int d)
{
        for(int i=0; i<p_graph->n_vertex; i++)
                vector_edge_push(vector_vector_edge_at(&(p_graph->adj_matrix), i), NULL);

        p_graph->n_vertex++;

        vector_edge tmp;
        vector_edge_init_n(&tmp, p_graph->n_vertex, NULL);
        vector_vector_edge_push(&(p_graph->adj_matrix), tmp);

        vertex v;
        vertex_init(&v, d);
        vector_vertex_push(&(p_graph->v_vertex), v);
}

void graph_insert_edge(graph * p_graph, int i, int j, int w)
{
        edge * tmp;
        edge_init(&tmp, w);
        * vector_edge_at(vector_vector_edge_at(&(p_graph->adj_matrix), i), j) = tmp;

        vector_vertex_at(&(p_graph->v_vertex), i)->o_degree++;
        vector_vertex_at(&(p_graph->v_vertex), j)->i_degree++;
}

void graph_remove_edge(graph * p_graph, int i, int j)
{
        if(vector_edge_(vector_vector_edge_at(&(p_graph->adj_matrix), i), j)!=NULL)
        {
                edge_cleanup(vector_edge_at(vector_vector_edge_at(&(p_graph->adj_matrix), i), j));

                vector_vertex_at(&(p_graph->v_vertex), i)->o_degree--;
                vector_vertex_at(&(p_graph->v_vertex), j)->i_degree--;
        }
}

void graph_remove_vertex(graph * p_graph, int i)
{
        int counter=0;
        for(int j=0; j<p_graph->n_vertex; j++)
                if(graph_incident(p_graph, i, j))
                {
                        vector_vertex_at(&(p_graph->v_vertex), j)->i_degree--;
                        counter++;
                }


        for(int j=0; j<p_graph->n_vertex; j++)
                if(graph_incident(p_graph, j, i))
                {
                        vector_vertex_at(&(p_graph->v_vertex), j)->o_degree--;
                        counter++;
                }

        p_graph->n_vertex--;
        p_graph->n_edge-=counter;
        vector_vertex_remove(&(p_graph->v_vertex), i);
        vector_edge_cleanup(vector_vector_edge_at(&(p_graph->adj_matrix), i),edge_cleanup);
        vector_vector_edge_remove(&(p_graph->adj_matrix), i);

        for(int k=0; k<p_graph->n_vertex; k++)
                vector_edge_remove(vector_vector_edge_at(&(p_graph->adj_matrix), k) , i);
}

int graph_incident(graph * p_graph, int i, int j)
{
        return (vector_edge_(vector_vector_edge_at(&(p_graph->adj_matrix), i),j) != NULL);
}

void graph_vertex_neibour(int i_vertex, int * p_cursor)
{

}

void graph_cleanup(graph * p_graph)
{
        for(int i=0; i<p_graph->n_vertex; i++)
                vector_edge_cleanup(vector_vector_edge_at(&(p_graph->adj_matrix), i),edge_cleanup);
        vector_vector_edge_free(&(p_graph->adj_matrix));
        vector_vertex_free(&(p_graph->v_vertex));
        p_graph->n_vertex = 0;
        p_graph->n_edge   = 0;
}

/* debug */
#include <stdio.h>

void graph_debug()
{
        graph g;
        graph_init(&g);
        graph_insert_vertex(&g, 10);
        graph_insert_vertex(&g, 20);
        printf("%d\n",g.n_vertex);
        printf("%d\n",g.v_vertex.size);
        printf("%d\n",g.adj_matrix.size);
        printf("%d\n",(g.adj_matrix.data[0]).size);
        printf("%d\n",(g.adj_matrix.data[1]).size);
        printf("=%d=\n",graph_incident(&g,0,1));
        graph_insert_vertex(&g, 15);
        graph_insert_vertex(&g, 37);
        graph_insert_vertex(&g, 4);
        graph_insert_vertex(&g, 26);
        graph_insert_edge(&g, 0, 5, 1);
        graph_insert_edge(&g, 3, 4, 2);
        graph_remove_edge(&g, 0, 5);
        graph_remove_vertex(&g, 0);
        graph_remove_vertex(&g, 4);
        graph_remove_vertex(&g, 1);
        printf("%d\n",g.n_vertex);
        printf("%d\n",g.v_vertex.size);
        printf("%d\n",g.adj_matrix.size);
        printf("%d\n",(g.adj_matrix.data[0]).size);
        printf("%d\n",(g.adj_matrix.data[1]).size);
        printf("=%d=\n",graph_incident(&g,0,1));
        graph_cleanup(&g);
}
