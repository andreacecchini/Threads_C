/**
 * @file main.c
 * @author Andrea Cecchini (andrea.cecchini13@studio.unibo.it)
 * @brief 
 * @version 0.1
 * @date 2022-12-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#define N_PTHREADS 10

static pthread_t threads[N_PTHREADS];

/**
 * @brief A function executed by a pthread without arguments
 * 
 * @return void* 
 * 
 */
void* func()
{
    /* Do something ... */
    fprintf(stdout, "I'm the pthread with id: %ld\n", pthread_self());
    pthread_exit(NULL);
}


/**
 * @brief A function executed by a pthread with arguments 
 * 
 * @param arg The data structures argument passed as argument to the function 
 * @return void*  
 */
void* func_with_param(void *arg)
{
    int input; 
    input = ( *(int*)arg );
    /* Waiting the previous pthread*/
    if(input != 0)
    {
        pthread_join(threads[input - 1], NULL);    
    }
    /* Do something ...*/
    fprintf(stdout, "I'm the pthread called with param: %d\n", input);
    pthread_exit(NULL);
}

/**
 * @brief Entry Point of the program 
 * 
 * @param argc Number of argument passed through command line  
 * @param argv Arguements passed through command line 
 * @return int Exit-status of the program. 
 */
int main(int argc, char const *argv[])
{
    size_t i;    
    /* Result get by the pthreads library functions */
    int rc;
    int* param;

    for( i = 0 ; i < N_PTHREADS ; ++i)
    {
        param = (int *)malloc(sizeof(int));
        *param = i;
        rc = pthread_create(&threads[i], NULL, func_with_param, (void *)param);
        if( rc != 0 )
        {
            fprintf(stderr, "Error while creating current POSIX Thread:%ld",i);
            exit(1);
        }  
    }
    /* Killing the main thread */
    pthread_exit(NULL);
    /*
     * The return istruction won't be reached because main thread will exit 
     * before it 
     */
    return (EXIT_SUCCESS); 
}



