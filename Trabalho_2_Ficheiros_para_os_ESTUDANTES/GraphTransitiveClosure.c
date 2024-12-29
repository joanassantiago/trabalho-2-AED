//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira - Dec 2024
//
// GraphTransitiveClosure - Transitive Closure of a directed graph
//

// Student Name : Joana Santiago  
// Student Number : 119705
// Student Name : Raquel Meira
// Student Number : 118928

/*** COMPLETE THE GraphComputeTransitiveClosure FUNCTION ***/

#include "GraphTransitiveClosure.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphBellmanFordAlg.h"
#include "instrumentation.h"

// Compute the transitive closure of a directed graph
// Return the computed transitive closure as a directed graph
// Use the Bellman-Ford algorithm
Graph* GraphComputeTransitiveClosure(Graph* g) {
  assert(g != NULL);
  assert(GraphIsDigraph(g));
  assert(GraphIsWeighted(g) == 0);

  // COMPLETE THE CODE

  int numVertices = GraphGetNumVertices(g);                                 // Get number of vertices

  Graph* TransitiveClosure = GraphCreate(numVertices, 1, 0);                // Create a new Graph for the Transitive Closure Graph with the same number of vertices of the initial graph
  

  for (int u = 0; u < numVertices; u++){                                    // Iterate every vertex u
    GraphBellmanFordAlg* result = GraphBellmanFordAlgExecute(g,u);          // Execute the Bellman-Ford Algorithm to get all the reachable vertices from u

    for (int v = 0; v < numVertices; v++) {                                 // For every U and v, if v is reachable from u,
      if (GraphBellmanFordAlgReached(result, v)) {                          //add to the new transitive closure graph the (u,v) edge
        GraphAddEdge(TransitiveClosure, u, v);
      }
    }

  GraphDestroy(&result);                                                   // Housekeeping


  }


  return TransitiveClosure;                                                // Return the new Graph
}
