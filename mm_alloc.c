/*
 * mm_alloc.c
 *
 * Stub implementations of the mm_* routines. Remove this comment and provide
 * a summary of your allocator's design here.
 */

#include "mm_alloc.h"

#include <stdlib.h>

/* Your final implementation should comment out this macro. */
#define MM_USE_STUBS

void* mm_malloc(size_t size)
{
#ifdef MM_USE_STUBS
  t_block b, last;
  size_t s;
  s = allign4(size);
  if(base){
    last = base;
    b = find_block(&last,s);
    if(b){
      if((b->size - s) >= (BLOCK_SIZE +4)) 
	slpit_blockb,s);
    b->free=0;
  }
#else
  else{
    b = extend_heap(last,s);
    if(!B)
      return (NULL);
    base = b;
  }
  /*return calloc(1, size);*/
  return(b->data);

#error Not implemented.
#endif
}
/*Note: for memory allocator 
use systemcall: sbrk() to request memory from the kernel 
main job: / memory into reasonable sized blocks -> allocated to app
						-> freed ( left for subsequent allocations
#include<unistd.h>
int brk(void *addr);
void*sbrk(intptr_t increment);
brk(),sbrk();
if ( sbrk() == 0){
	 return calloc(1, size);
	void*calloc(size_t nitems, size_t size);
	int size= 4026 bytes;
	
// calloc sets the memory to zero difference between bmallac
}	
Else{
	//if error what must it do??
}
 */

void* mm_realloc(void* ptr, size_t size)
{
#ifdef MM_USE_STUBS
  size_t s;
  t_block b,new;
  void *newptr;
  if(! ptr){
    return realloc(ptr, size);/*return malloc(size);*/
    if (valid_addr(ptr))
      {
	s = align4(size);
	b = get_block(ptr);
	if(b->size >= size);
	{
	  if(b->size - s>= (BLOCK_SIZE + 4))
	    split_block(b,s);
	}
#else
	else {
	  if(b->next && b->next->free && (b->size + BLOCK_SIZE + b->next->size) >= s){
	    fusion(b);
	    if( b->size -s >= (BLOCK_SIZE + 4) )
	      split_block(b,s);
	  }
	  else 
	    {
		  newp = malloc(s);
		  if(!newp)
		    return(NULL);
		  new= get_block(newp);
		  copy_block(b,new);
		  free(ptr);
		  return(newptr);
		}
	    }
	    return(ptr);
	  }
	  return(NULL);
	  } 


    #error Not implemented.
    #endif
    }

    void mm_free(void* ptr)
    {
    #ifdef MM_USE_STUBS
	free(ptr);
      t_block b;
      if( valid_addr(ptr))
	{
	  b = get_block(ptr);
	  b->free;
	  /* fusion with previous if possible */ 
	  if(b->prev && b->prev->free)
	    b = fusion(b->prev);
	  /*then fusion with the next */ 
	  if(b->next)
	    fusion(b);
#else
      else
	{
	  /* free the end of the heap */ 
	  if(b->prev)
	    b->prev->next = NULL;
	  else
	    /* No more block !=*/
	    base = NULL;
	  brk(b);
	}
    }
#error Not implemented.
#endif
}
