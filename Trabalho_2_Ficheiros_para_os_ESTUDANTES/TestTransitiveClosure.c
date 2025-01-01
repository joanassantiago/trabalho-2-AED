//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - Dec 2024
//
// Testing the Transitive Closure algorithm
//

#include <assert.h>

#include "Graph.h"
#include "GraphTransitiveClosure.h"
#include "instrumentation.h"

int main(void) {
  // What kind of graph is dig01?
  Graph* dig01 = GraphCreate(6, 1, 0);
  GraphAddEdge(dig01, 1, 2);
  GraphAddEdge(dig01, 1, 4);
  GraphAddEdge(dig01, 3, 4);
  printf("The graph:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig01);
  printf("\n");

  GraphCheckInvariants(dig01);

  Graph* tcdig01 = GraphComputeTransitiveClosure(dig01);
  InstrPrint();
  InstrReset();
  
  printf("The transitive closure:\n");
  // Displaying in DOT format
  GraphDisplayDOT(tcdig01);
  printf("\n");

  GraphCheckInvariants(tcdig01);

  // Reading a directed graph from file
  FILE* file1 = fopen("DG_2.txt", "r");
  Graph* dig03 = GraphFromFile(file1);
  fclose(file1);
  // Displaying in DOT format
  GraphDisplayDOT(dig03);
  printf("\n");

  GraphCheckInvariants(dig03);

  Graph* tcdig03 = GraphComputeTransitiveClosure(dig03);
  InstrPrint();
  InstrReset();
  printf("The transitive closure:\n");
  // Displaying in DOT format
  GraphDisplayDOT(tcdig03);
  printf("\n");

  GraphCheckInvariants(tcdig03);

  // Adding new graph dig04
  Graph* dig04 = GraphCreate(8, 1, 0);
  GraphAddEdge(dig04, 0, 1);
  GraphAddEdge(dig04, 1, 2);
  GraphAddEdge(dig04, 2, 3);
  GraphAddEdge(dig04, 3, 4);
  GraphAddEdge(dig04, 4, 5);
  GraphAddEdge(dig04, 5, 6);
  GraphAddEdge(dig04, 6, 7);
  printf("The graph dig04:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig04);
  printf("\n");

  GraphCheckInvariants(dig04);

  Graph* tcdig04 = GraphComputeTransitiveClosure(dig04);
  InstrPrint();
  InstrReset();
  printf("The transitive closure of dig04:\n");
  // Displaying in DOT format
  GraphDisplayDOT(tcdig04);
  printf("\n");

  GraphCheckInvariants(tcdig04);

  // Adding new graph dig05
  Graph* dig05 = GraphCreate(5, 1, 0);
  GraphAddEdge(dig05, 0, 1);
  GraphAddEdge(dig05, 1, 2);
  GraphAddEdge(dig05, 2, 0);
  GraphAddEdge(dig05, 2, 3);
  GraphAddEdge(dig05, 3, 4);
  printf("The graph dig05:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig05);
  printf("\n");

  GraphCheckInvariants(dig05);

  Graph* tcdig05 = GraphComputeTransitiveClosure(dig05);
  InstrPrint();
  InstrReset();
  printf("The transitive closure of dig05:\n");
  // Displaying in DOT format
  GraphDisplayDOT(tcdig05);
  printf("\n");

  GraphCheckInvariants(tcdig05);

  // Adding a large graph dig06
  Graph* dig06 = GraphCreate(20, 1, 0);
  for (int i = 0; i < 19; i++) {
    for (int j = i + 1; j < 20; j++) {
      GraphAddEdge(dig06, i, j);
    }
  }
  printf("The large graph dig06:\n");
  // Displaying in DOT format
  GraphDisplayDOT(dig06);
  printf("\n");

  GraphCheckInvariants(dig06);

  Graph* tcdig06 = GraphComputeTransitiveClosure(dig06);
  InstrPrint();
  InstrReset();
  printf("The transitive closure of dig06:\n");
  // Displaying in DOT format
  GraphDisplayDOT(tcdig06);
  printf("\n");

  GraphCheckInvariants(tcdig06);

  GraphDestroy(&dig01);
  GraphDestroy(&dig03);
  GraphDestroy(&dig04);
  GraphDestroy(&dig05);
  GraphDestroy(&dig06);

  GraphDestroy(&tcdig01);
  GraphDestroy(&tcdig03);
  GraphDestroy(&tcdig04);
  GraphDestroy(&tcdig05);
  GraphDestroy(&tcdig06);

  return 0;
}
