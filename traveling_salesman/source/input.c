#include "../include/input.h"
#include <stdio.h>
char **load_airports(const char *file_name, int airport_count) {
  FILE *fp = fopen(file_name, "r");
  if (!fp) {
    printf("[error][load_airports]->failed opening file %s", file_name);
    exit(-1);
  }
  char **airports = malloc(airport_count * sizeof(char *));
  if (airports == NULL) {
    printf("[error][input]->failed to allocate memory");
    exit(-1);
  }
  int i = 0;
  for (; i < airport_count; i++) {
    airports[i] = malloc(AIRPORT_BUFFER_LEN);
    if (airports[i] == NULL) {
      printf("[error][input]->failed to allocate memory");
    }
  }
  char buffer[AIRPORT_BUFFER_LEN];
  int idx = 0;
  while (fgets(buffer, AIRPORT_BUFFER_LEN, fp) != NULL) {
    memcpy(airports[idx], buffer, AIRPORT_BUFFER_LEN);
    buffer[3]='\0';
    fseek(fp,1,SEEK_CUR);
    idx++;
  }
  fclose(fp);
  return airports;
}
int find_airport_idx(char *airport, char **airports) {
  int idx=0;
  int iter=0;
  while(strcmp(airport,airports[idx]) != 0){
    idx++;
    iter++;
  }
  return iter;
}
int **init_adj_matrix(const char *filename, char **airports,int airport_count) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    printf("[error][init_adj_matrix]->failed opening file %s", filename);
    exit(-1);
  }
  int **adj_matrix = (int **)calloc(airport_count-1, sizeof(int *));
  if (adj_matrix == NULL) {
    printf("[error][init_adj_matrix]->failed to allocate memory");
    exit(-1);
  }
  int i = 0;
  for (; i < airport_count; i++) {
    adj_matrix[i] = calloc(airport_count-1, sizeof(int));
    if (adj_matrix == NULL) {
      printf("[error][init_adj_matrix]->failed to allocate memory");
      exit(-1);
    }
  }
  char src[AIRPORT_BUFFER_LEN];
  char dst[AIRPORT_BUFFER_LEN];
  int src_idx = 0;
  int dst_idx = 0;
  while (fgets(src, AIRPORT_BUFFER_LEN, fp) != NULL) {
    fseek(fp,ROUTE_OFFSET,SEEK_CUR);
    if (fgets(dst, AIRPORT_BUFFER_LEN, fp) == NULL) {
      printf("[error][init_adj_matrix]->airport %s does not have a pair",src);
    }
    src_idx = find_airport_idx(src,airports);
    dst_idx = find_airport_idx(dst,airports);
    adj_matrix[src_idx][dst_idx] = 1;
    fseek(fp, 1, SEEK_CUR);
  }
  return adj_matrix;
}