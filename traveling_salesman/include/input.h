#ifndef INPUT_H
#define INPUT_H
#define AIRPORT_BUFFER_LEN 4
#define ROUTE_OFFSET 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **load_airports(const char *file_name, int airport_count);
int **init_adj_matrix(const char *filename, char **airports, int airport_count);
int find_airport_idx(char *airport, char **airports);
#endif
