#include "../include/input.h"
#include <stdlib.h>
#include "../include/algorithms.h"
int main(int argc, char *argv[]) {
if(argc != 3){
    printf("[error][main]->wrong usage. use it like this: ./graph_algorithm SOURCE_AIRPORT DESTINATION_AIRPORT");
    return -1;
}

  char *src = argv[1];
  char *trg = argv[2];
  const char *airport_txt = "../airports.txt";
  const char *nodes_txt = "../nodes.txt";
  char **airports = load_airports(airport_txt, 18);
  int **adj_matrix = init_adj_matrix(nodes_txt, airports,18);
  int src_idx = find_airport_idx(src,airports);
  int trg_idx = find_airport_idx(trg,airports);
  int rs = BFS(adj_matrix,src_idx,trg_idx,18);
  printf("from %s to %s minimin hops required is -> %d",src,trg,rs);
  return 0;
}
