//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - Dec 2024
//
// Testing the Bellman-Ford algorithm
//

#include <assert.h>

#include "Graph.h"
#include "GraphBellmanFordAlg.h"
#include "instrumentation.h"

int main(void) {
  // Graph dig01
  Graph* dig01 = GraphCreate(6, 1, 0);
  GraphAddEdge(dig01, 1, 2);
  GraphAddEdge(dig01, 1, 4);
  GraphAddEdge(dig01, 3, 4);
  printf("The graph dig01:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig01);
  printf("\n");

  GraphCheckInvariants(dig01);

  // Bellman-Ford Algorithm for dig01
  for (unsigned int i = 0; i < 6; i++) {
    GraphBellmanFordAlg* BF_result = GraphBellmanFordAlgExecute(dig01, i);
    printf("The shortest path tree rooted at %u\n", i);
    GraphBellmanFordAlgDisplayDOT(BF_result);
    printf("\n");
    
    GraphBellmanFordAlgDestroy(&BF_result);
  }
  InstrPrint();
  InstrReset();

  // Graph g01
  Graph* g01 = GraphCreate(6, 0, 0);
  GraphAddEdge(g01, 0, 5);
  GraphAddEdge(g01, 2, 4);
  GraphAddEdge(g01, 2, 3);
  GraphAddEdge(g01, 1, 2);
  GraphAddEdge(g01, 0, 1);
  GraphAddEdge(g01, 3, 4);
  GraphAddEdge(g01, 3, 5);
  GraphAddEdge(g01, 0, 2);
  printf("The graph g01:\n");
  // Displaying in DOT format
  GraphDisplayDOT(g01);
  printf("\n");

  GraphCheckInvariants(g01);

  // Bellman-Ford Algorithm for g01
  for (unsigned int i = 0; i < 6; i++) {
    GraphBellmanFordAlg* BF_result = GraphBellmanFordAlgExecute(g01, i);
    printf("The shortest path tree rooted at %u\n", i);
    GraphBellmanFordAlgDisplayDOT(BF_result);
    printf("\n");
    
    GraphBellmanFordAlgDestroy(&BF_result);
  }
  InstrPrint();
  InstrReset();

  // Reading a directed graph from file
  FILE* file = fopen("DG_2.txt", "r");
  Graph* dig03 = GraphFromFile(file);
  fclose(file);
  printf("The graph dig03:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig03);
  printf("\n");

  GraphCheckInvariants(dig03);

  // Bellman-Ford Algorithm for dig03
  for (unsigned int i = 0; i < GraphGetNumVertices(dig03); i++) {
    GraphBellmanFordAlg* BF_result = GraphBellmanFordAlgExecute(dig03, i);
    printf("The shortest path tree rooted at %u\n", i);
    GraphBellmanFordAlgDisplayDOT(BF_result);
    printf("\n");
    
    GraphBellmanFordAlgDestroy(&BF_result);
  }
  InstrPrint();
  InstrReset();

  // Graph dig04 - Medium size
  Graph* dig04 = GraphCreate(10, 1, 0);
  GraphAddEdge(dig04, 0, 1);
  GraphAddEdge(dig04, 1, 2);
  GraphAddEdge(dig04, 2, 3);
  GraphAddEdge(dig04, 3, 4);
  GraphAddEdge(dig04, 4, 5);
  GraphAddEdge(dig04, 5, 6);
  GraphAddEdge(dig04, 6, 7);
  GraphAddEdge(dig04, 7, 8);
  GraphAddEdge(dig04, 8, 9);
  GraphAddEdge(dig04, 0, 9);
  printf("The graph dig04:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig04);
  printf("\n");

  GraphCheckInvariants(dig04);

  // Bellman-Ford Algorithm for dig04
  for (unsigned int i = 0; i < 10; i++) {
    GraphBellmanFordAlg* BF_result = GraphBellmanFordAlgExecute(dig04, i);
    printf("The shortest path tree rooted at %u\n", i);
    GraphBellmanFordAlgDisplayDOT(BF_result);
    printf("\n");
    
    GraphBellmanFordAlgDestroy(&BF_result);
  }
  InstrPrint();
  InstrReset();

  // Graph dig05 - Large size
  Graph* dig05 = GraphCreate(15, 1, 0);
  for (int i = 0; i < 14; i++) {
    for (int j = i + 1; j < 15; j++) {
      GraphAddEdge(dig05, i, j);
    }
  }
  printf("The graph dig05:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig05);
  printf("\n");

  GraphCheckInvariants(dig05);

  // Bellman-Ford Algorithm for dig05
  for (unsigned int i = 0; i < 15; i++) {
    GraphBellmanFordAlg* BF_result = GraphBellmanFordAlgExecute(dig05, i);
    printf("The shortest path tree rooted at %u\n", i);
    GraphBellmanFordAlgDisplayDOT(BF_result);
    printf("\n");
    
    GraphBellmanFordAlgDestroy(&BF_result);
  }

  InstrPrint();
  InstrReset();

  GraphDestroy(&g01);
  GraphDestroy(&dig01);
  GraphDestroy(&dig03);
  GraphDestroy(&dig04);
  GraphDestroy(&dig05);

  return 0;
}
