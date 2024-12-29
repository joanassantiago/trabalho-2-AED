//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira - Dec 2024
//
// GraphAllPairsShortestDistances
//

// Student Name :
// Student Number :
// Student Name :
// Student Number :

/*** COMPLETE THE GraphAllPairsShortestDistancesExecute FUNCTION ***/

#include "GraphAllPairsShortestDistances.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphBellmanFordAlg.h"

struct _GraphAllPairsShortestDistances {
  int** distance;  // The 2D matrix storing the all-pairs shortest distances
                   // It is stored as an array of pointers to 1D rows
                   // Idea: an INDEFINITE distance value is stored as -1
  Graph* graph;
};

// Allocate memory and initialize the distance matrix
// Compute the distances between vertices by running the Bellman-Ford algorithm
GraphAllPairsShortestDistances* GraphAllPairsShortestDistancesExecute(
    Graph* g) {
  assert(g != NULL);

  // COMPLETE THE CODE

  GraphAllPairsShortestDistances* result = (GraphAllPairsShortestDistances*)malloc(sizeof(GraphAllPairsShortestDistances));   //Alocar memória para a estrutura 
  assert(result != NULL);

  int numVertices = GraphGetNumVertices(g);                                    //Obter numero de vertices do grafo

  result->graph = g;

  result->distance=(int**)malloc(numVertices * sizeof(int*));                  //Alocar memória para a criação da matriz de distâncias
  assert(result->distance != NULL);

  for(int l = 0; l < numVertices; l++ ){                                       //Inicializar a matriz toda a -1 (distâncias indefinidas)

    result->distance[l] = (int*)malloc(numVertices * sizeof(int));
    assert(result->distance[l] != NULL);

    for (int c = 0; c < numVertices; c++){

      result->distance[l][c] = -1;
    }

  }

  for(int u = 0; u < numVertices; u++){                                         //Iterar sobre cada vertice u

    GraphBellmanFordAlg* bellman = GraphBellmanFordAlgExecute(g,u);             //Executar o algoritmo de Bellman-Ford para obter todos os vertices alcançáveis a partit de u

    for(int v = 0; v < numVertices; v++){

      if(GraphBellmanFordAlgReached(bellman, v)){                              //Para cada vertice u, se o veritce v for alcançável a partir de u
        result->distance[u][v] = GraphBellmanFordAlgDistance(bellman, v);      //Definir a distância entre vertices e adicionar à matriz

      }
    }

    GraphBellmanFordAlgDestroy(&bellman);                                      //Housekeeping
  }

  return result;
}

void GraphAllPairsShortestDistancesDestroy(GraphAllPairsShortestDistances** p) {
  assert(*p != NULL);

  GraphAllPairsShortestDistances* aux = *p;
  unsigned int numVertices = GraphGetNumVertices(aux->graph);

  for (unsigned int i = 0; i < numVertices; i++) {
    free(aux->distance[i]);
  }

  free(aux->distance);

  free(*p);
  *p = NULL;
}

// Getting the result

int GraphGetDistanceVW(const GraphAllPairsShortestDistances* p, unsigned int v,
                       unsigned int w) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));
  assert(w < GraphGetNumVertices(p->graph));

  return p->distance[v][w];
}

// DISPLAYING on the console

void GraphAllPairsShortestDistancesPrint(
    const GraphAllPairsShortestDistances* p) {
  assert(p != NULL);

  unsigned int numVertices = GraphGetNumVertices(p->graph);
  printf("Graph distance matrix - %u vertices\n", numVertices);

  for (unsigned int i = 0; i < numVertices; i++) {
    for (unsigned int j = 0; j < numVertices; j++) {
      int distanceIJ = p->distance[i][j];
      if (distanceIJ == -1) {
        // INFINITY - j was not reached from i
        printf(" INF");
      } else {
        printf(" %3d", distanceIJ);
      }
    }
    printf("\n");
  }
}
