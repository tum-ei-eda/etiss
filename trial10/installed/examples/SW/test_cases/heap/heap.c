/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "heap.h"
#include "../cust_print/cust_print.h"

#define malloc(X)  OS_HeapMalloc(NULL, X)
#define HEAP_MAGIC 0x1234abcd
#define HEAP_COUNT 8
#define NULL       0

typedef unsigned long int uint32;
typedef struct HeapNode_s {
	struct HeapNode_s  *next;
	int                size;
} HeapNode_t;
typedef   struct OS_Heap_s {
	uint32            magic;
	const char        *name;
	HeapNode_t        *available;
	HeapNode_t        base;
	struct OS_Heap_s  *alternate;
} OS_Heap_t;

static    OS_Heap_t  *HeapArray[HEAP_COUNT];

OS_Heap_t *OS_HeapCreate(const char *Name, void *thisHeapStorage, uint32 Size, int hp__ADDR)
{	
	//assert(((uint32)thisHeap & 3) == 0);
	
	OS_Heap_t *heap;
	heap                  = (OS_Heap_t*)thisHeapStorage;
	heap->magic           = HEAP_MAGIC;
	heap->name            = Name;
	heap->available       = (HeapNode_t*)(heap + 1);
	heap->available->next = &heap->base;
	heap->available->size = (Size - sizeof(OS_Heap_t)) / sizeof(HeapNode_t);
	heap->base.next       = heap->available;
	heap->base.size       = 0;
	
	//printf("HeapCreate: Returned hp=%d\n", (int)heap);
	return heap;
}

void *OS_HeapMalloc(OS_Heap_t *Heap, int Bytes)
{
	//printf("Malloc: for 'Heap'= %d;  alloc %d bytes ... \n", (int)Heap, Bytes);

	HeapNode_t *node, *prevp;
	int        nunits;

	if((int)Heap < HEAP_COUNT){
		//printf("Malloc: 'Heap' aligned to first item in HeapArray.\n");
		Heap = HeapArray[(int)Heap]; //WP_HPARRAY[HEAP]
	}
	
	nunits = (Bytes + sizeof(HeapNode_t) - 1) / sizeof(HeapNode_t) + 1;
	//printf("Malloc: numUnits = %d \n", nunits);
	
	prevp = Heap->available;
	for(node = prevp->next; ; prevp = node, node = node->next)
	{
		//printf("  Malloc: process node with size=%d ...\n", node->size);
		
		if(node->size >= nunits)       //Big enough?
		{
			if(node->size == nunits){
				//printf("  Malloc: CASE: Big enough and exact! \n");
				prevp->next = node->next;
			}
			else
			{   
				//printf("  Malloc: CASE: Big enough and divide! \n");

				#ifdef REQ_SYN

				#else

				#endif
				node->size -= nunits;
				node += node->size;
				node->size = nunits;
			}
			Heap->available = prevp;
			node->next = (HeapNode_t*)Heap;
			return (void*)(node + 1);
		}
		if(node == Heap->available)
		{
			//printf("  Malloc: CASE: No free place in this heap block! \n");

			if(Heap->alternate){
				/*return 1;  //*/return OS_HeapMalloc(Heap->alternate, Bytes);
			}
			return NULL;
		}
	//bb7
	#ifdef REQ_SYN

		#else

	#endif
	}
}

void heap(volatile char* logger_addr){
  custom_print_string(logger_addr, "heap called!\n");

    HeapArray[0] = OS_HeapCreate("Heap1", (uint32*)HeapArray, HEAP_COUNT, 4096);
    OS_HeapMalloc(NULL, 100);
}
/*
 * ░░░░░░░░░░░░░░░ Use steps ░░░░░░░░░░░░░░░░
 *   ├─ Init 
 *   │    ├─ a global heap storage:  static OS_Heap_t *HeapArray[HEAP_COUNT];
 *   │    ├─ the heap array       :  	OS_Heap_t *hp;
 *   │    ├                       :  	HeapArray[0] = OS_HeapCreate("Heap1", (uint32*)HeapArray, 1000);
 *   │
 *   ├─ Use:                         OS_HeapMalloc(NULL, 100);
 */
