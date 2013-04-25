/* 
 * File:   disk.c
 * Author: admin
 *
 * Created on April 24, 2013, 5:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
/*
 * 
 */
 int log_to_phys(int logaddr, physaddr_t *phaddr)
 {
 	phaddr->cyl = logaddr/(NUM_OF_SECTS*NUM_OF_HEADS);
 	phaddr->head = (logaddr/NUM_OF_SECTS) % NUM_OF_HEADS; 
 	phaddr->sect = (logaddr%NUM_OF_SECTS) + 1;
 	return 0;
 }

int phys_to_log(physaddr_t *phaddr)
{
	return ((phaddr->cyl*NUM_OF_HEADS)+phaddr->head)*NUM_OF_SECTS+phaddr->sect-1;
}


int read(int logical_block_num, int num_of_sectors, void **buffer)
{
	
	return 1;
}

int write(int logical_block_num, int num_of_sectors, void *buffer)
{
	return 1;
}

int main(int argc, char** argv) {

    printf("Testing\n");
    printf("Test\n");
    return (EXIT_SUCCESS);
}


