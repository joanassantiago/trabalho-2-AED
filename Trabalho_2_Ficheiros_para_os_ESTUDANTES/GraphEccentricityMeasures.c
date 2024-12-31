//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira - Dec 2024
//
// GraphEccentricityMeasures
//

// Student Name : Joana Santiago 
// Student Number : 119705
// Student Name : Raquel Meira 
// Student Number : 118928

/*** COMPLETE THE GraphEccentricityMeasuresCompute FUNCTION ***/
/*** COMPLETE THE GraphGetCentralVertices FUNCTION ***/
/*** COMPLETE THE GraphEccentricityMeasuresPrint FUNCTION ***/

#include "GraphEccentricityMeasures.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphAllPairsShortestDistances.h"

struct _GraphEccentricityMeasures {
  unsigned int*
      centralVertices;  // centralVertices[0] = number of central vertices
                        // array size is (number of central vertices + 1)
  int* eccentricity;    // the eccentricity value of each vertex
  Graph* graph;         // the graph
  int graphRadius;      // the graph radius
  int graphDiameter;    // the graph diameter
};

// Allocate memory
// Compute the vertex eccentricity values
// Compute graph radius and graph diameter
// Compute the set of central vertices
GraphEccentricityMeasures* GraphEccentricityMeasuresCompute(Graph* g) {
  assert(g != NULL);

  // COMPLETE THE CODE
  // CREATE AUXILIARY (static) FUNCTIONS, IF USEFUL
  // Graph radius --- the smallest vertex eccentricity value
  // Graph diameter --- the largest vertex eccentricity value
  // Do not forget that -1 represents an IDEFINITE value

  // Computing the set of central vertices
  // Allocate the central vertices array : number of central vertices + 1
  // Fill in the central vertices array

  GraphEccentricityMeasures* result = (GraphEccentricityMeasures*)malloc(sizeof(struct _GraphEccentricityMeasures));
  assert(result != NULL);
  
  result->graph = g;
  unsigned int numVertices = GraphGetNumVertices(g);

  GraphAllPairsShortestDistances* allPairsDistance = GraphAllPairsShortestDistancesExecute(g);
  assert(allPairsDistance != NULL);

  result->eccentricity = (int*)malloc(numVertices * sizeof(int));
  result->graphRadius = numVertices;
  result->graphDiameter = 0;

  unsigned int v = 0;
  for(;v < numVertices; v++){
    int maxDistance = 0;
    for(unsigned int w = 0; w < numVertices; w++){
      int distance = GraphGetDistanceVW(allPairsDistance,v,w);
      if(distance > maxDistance){
        maxDistance = distance;
      }
    }
    result->eccentricity[v] = maxDistance;
    if(result->eccentricity[v] < result->graphRadius){
      result->graphRadius = result->eccentricity[v];
    }
    if(result->eccentricity[v] > result->graphDiameter){
      result->graphDiameter = result->eccentricity[v];
    }
  }

  unsigned int numCentralVertices = 0;
  for (unsigned int v = 0; v < numVertices; v++) {
    if (result->eccentricity[v] == result->graphRadius) {
      numCentralVertices++;
    }
  }

  result->centralVertices = (unsigned int*)malloc((numCentralVertices + 1) * sizeof(unsigned int));
  assert(result->centralVertices != NULL);
  result->centralVertices[0] = numCentralVertices;

  unsigned int index = 1;
  for (unsigned int v = 0; v < numVertices; v++) {
    if (result->eccentricity[v] == result->graphRadius) {
      result->centralVertices[index++] = v;
    }
  }
  GraphAllPairsShortestDistancesDestroy(&allPairsDistance);
  return result;
}

void GraphEccentricityMeasuresDestroy(GraphEccentricityMeasures** p) {
  assert(*p != NULL);

  GraphEccentricityMeasures* aux = *p;

  free(aux->centralVertices);
  free(aux->eccentricity);

  free(*p);
  *p = NULL;
}

// Getting the computed measures

int GraphGetRadius(const GraphEccentricityMeasures* p) {
  assert(p != NULL);

  return p->graphRadius;
}

int GraphGetDiameter(const GraphEccentricityMeasures* p) {
  assert(p != NULL);

  return p->graphDiameter;
}

int GraphGetVertexEccentricity(const GraphEccentricityMeasures* p,
                               unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));
  assert(p->eccentricity != NULL);

  return p->eccentricity[v];
}

// Getting a copy of the set of central vertices
// centralVertices[0] = number of central vertices in the set
unsigned int* GraphGetCentralVertices(const GraphEccentricityMeasures* p) {
  assert(p != NULL);
  assert(p->centralVertices != NULL);

  // COMPLETE THE CODE

  unsigned int numCentralVertices = p->centralVertices[0];
  unsigned int* centralVertices = (unsigned int*)malloc(numCentralVertices * sizeof(unsigned int));

  for (unsigned int i = 1; i <= numCentralVertices; i++) {
    centralVertices[i-1] = p->centralVertices[i];
  } 
  return centralVertices;
}

// Print the graph radius and diameter
// Print the vertex eccentricity values
// Print the set of central vertices
void GraphEccentricityMeasuresPrint(const GraphEccentricityMeasures* p) {
  // COMPLETE THE CODE

  printf("Graph radius: %d\n", p->graphRadius);
  printf("Graph diameter: %d\n", p->graphDiameter);

  unsigned int numVertices = GraphGetNumVertices(p->graph);
  printf("Vertex eccentricities values:\n");
  for (unsigned int v = 0; v < numVertices; v++) {
    printf("Vertex %u: %d\n", v, p->eccentricity[v]);
  }

  unsigned int numCentralVertices = p->centralVertices[0];
  printf("Central vertices (%u):", numCentralVertices);
  for (unsigned int i = 1; i <= numCentralVertices; i++) {
    printf("%u ", p->centralVertices[i]);
  }
  printf("\n");
}
