
#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include "common.h"

int main()
{
  int semid, i;
  struct sembuf sb[NUM_SEMAPHORES];

  /* Get the semaphore with the id MY_SEM_ID */
  semid = semget( MY_SEMARRAY_ID, NUM_SEMAPHORES, 0 );

  if (semid >= 0) {

    for (i = 0 ; i < NUM_SEMAPHORES ; i++) {
      sb[i].sem_num = i;
      sb[i].sem_op = -1;
      sb[i].sem_flg = 0;
    }

    printf( "semaacq: Attempting to acquire semaphore %d\n", semid );

    /* Acquire the semaphore */
    if (semop( semid, &sb[0], NUM_SEMAPHORES ) == -1) {

      printf("semaacq: semop failed.\n");
      exit(-1);

    }

    printf( "semaacq: Semaphore acquired %d\n", semid );

  }

  return 0;
}

