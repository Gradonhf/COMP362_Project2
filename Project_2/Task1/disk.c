/*
 * Project 2 Task 1
 * Author: Gradon H. Faulkner
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
    if(logaddr>0 && logaddr<MAX_LOGICAL_SECTOR)
    {
        phaddr->cyl = logaddr/(NUM_OF_SECTS*NUM_OF_HEADS);
        phaddr->head = (logaddr/NUM_OF_SECTS) % NUM_OF_HEADS;
        phaddr->sect = (logaddr%NUM_OF_SECTS) + 1;
        return 1;
    }
    else
    {
        return 0;
    }

}

int phys_to_log(physaddr_t *phaddr)
{

    if(phaddr!=NULL)
    {
        return ((phaddr->cyl*NUM_OF_HEADS)+phaddr->head)*NUM_OF_SECTS+phaddr->sect-1;
    }
    else
    {
        return 0;
    }
}

/**
This function copies num_of_sectors sectors from the disk to the buffer starting with sector pointed to by logical_block_num. You should validate the parameters before serving the request.
**/

int read(int logical_block_num, int num_of_sectors, void **buffer)
{
    int i;
    physaddr_t *phaddr = malloc(sizeof(physaddr_t));
    if(log_to_phys(logical_block_num,phaddr)==1)
    {
    printf("");
        for(i=0; i<num_of_sectors; i++)
        {
            //memcpy(*buffer[i],disks[(phaddr->cyl)*(phaddr->head)*(phaddr->sect)],num_of_sectors);
        }
        memcpy(*buffer,*disks+((phaddr->cyl)*(phaddr->head)*(phaddr->sect)),num_of_sectors);
        return 1;
    }
    return 0;
}

/**
This function copies num_of_sectors sectors from the buffer to the disk starting at sector pointed to by logical_block_num. Here, you also should validate the parameters.
**/
int write(int logical_block_num, int num_of_sectors, void *buffer)
{
    int i;
    physaddr_t *phaddr = malloc(sizeof(physaddr_t));
    if(log_to_phys(logical_block_num,phaddr)==1)
    {
        for(i=0; i<num_of_sectors; i++)
        {
            //memcpy(disks[(phaddr->cyl)*(phaddr->head)+phaddr->sect],*buffer[i],1);
        }
        memcpy(disks+((phaddr->cyl)*(phaddr->head)+(phaddr->sect)),buffer,num_of_sectors);
        printf("write after the For loop\n");
        return 1;
    }

    printf("write after the if loop\n");
    return 0;
}

int main(int argc, char** argv) {

    int logaddr = 123;
    int test;
    char *str;
    printf("Test logical to physical %d\n",logaddr);
    physaddr_t *phaddr = malloc(sizeof(physaddr_t));
    test =log_to_phys(logaddr,phaddr);
    printf("Test physical to logical %d\n", phys_to_log(phaddr));
   	test = write( 123, 2, (void*) str);
    return (EXIT_SUCCESS);
}


