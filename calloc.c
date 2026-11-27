#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include "malloc.c"
#include "include/calloc.h"

void *calloc(size_t number, size_t size) {
  size_t *new;
  size_t s, i;

  new = malloc(number * size);
  if(new) {
    s = align4(number * size) << 2;
    for(i = 0; i < s; i++) {
      new[i] = 0;
    }
  }
  return new;
}