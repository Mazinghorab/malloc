#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "malloc.c"
#include "free.c"
#include "include/realloc.h"

void copy_data(meta_ptr src, meta_ptr dest) {
  int *src_data = src->data;
  int *dest_data = dest->data;
  size_t i;
  for(i = 0; i * 4 < src->size && i * 4 < dest->size; i++) {
    dest_data[i] = src_data[i];
  }
}

void *realloc(void *p, size_t size)
{
  size_t s;
  meta_ptr new_block, old_block;
  void *new_ptr;
  if(!p) {
      return malloc(size);
    }

    if(is_addr_valid(p)) {
      s = align4(size);
      old_block = get_block_addr(p);
      if(old_block->size >= s) {
        if(old_block->size >= (META_BLOCK_SIZE + 4)) {
          split_space(old_block, s);
        }
      }

      else {
        if(old_block->next && old_block->next->free && (old_block->size + old_block->next->size + META_BLOCK_SIZE) >= s) {
            merge_blocks(old_block);
            if (old_block - s >= (META_BLOCK_SIZE + 4)) {
              split_space(old_block, s);
            }
        }
        
        else {
          new_ptr = malloc(s);
          if (!new_ptr) return NULL;
          new_block = get_block_addr(new_ptr);
          copy_data(old_block, new_block);
          free(p);
          return new_ptr;
        }
      }
      return p;
  }
  return NULL;
}