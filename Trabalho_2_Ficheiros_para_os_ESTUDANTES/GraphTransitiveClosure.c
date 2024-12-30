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

  InstrName[0] = "memops";
  InstrName[1] = "ops";
  InstrCalibrate();
  InstrReset();

  int numVertices = GraphGetNumVertices(g);                                 // Obter o numero de vertices

  Graph* TransitiveClosure = GraphCreate(numVertices, 1, 0);                // Criar um novo grafo (TransitiveClosure) com o mesmo numero de vertices que o grafo inicial 

  for (int u = 0; u < numVertices; u++){                                    // Iterar cada vertice u
    GraphBellmanFordAlg* result = GraphBellmanFordAlgExecute(g,u);          // Executar o algoritmo de Bellman-Ford para obter todos os vertices alcançáveis a partir de u
    InstrCount[0]++;

    for (int v = 0; v < numVertices; v++) {                                 // Para cada vertice u, se o veritce v for alcançável a partir de u
      if (GraphBellmanFordAlgReached(result, v)) {                          //adicionar ao grafo (TransitiveClosure) a aresta (u,v)
        GraphAddEdge(TransitiveClosure, u, v);
        InstrCount[0]++;
      }
      InstrCount[1]++;
    }

  GraphBellmanFordAlgDestroy(&result);                                                   // Housekeeping

  InstrCount[1]++;
  }


  return TransitiveClosure;                                                // Retorno do grafo TransitiveClosure
}
