// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <stdio.h>
#include <pthread.h>
#include <pthread.h>

#define NTHREADS 64

// Global array
// This is our 'canvas' we are painting on.
// It is 64 rows by 64 columns (each pixel stores 3 color components: R, G, B)
int colors[64][64*3];

// Gobal Counter
int counter =0;

// Our Mutual Exclusive object
// Prevents editing on the same work area at the same time
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


// Paint function called from each thread.
void paint (int workCounter){
    printf("Thread %d is painting\n", workCounter);

        // workID corresponds to the 'artist'
        // Each artist owns one row to paint on.
        // An artist paints along each pixel 1 at a time, painting an
        // R,G,B value (that is why it is 64*3)
        int i = 0;
        for(i =0; i< 64*3; i++){
            colors[workCounter][i]= workCounter; // Try doing something more interesting with the colors!
        }
}

// Thread with variable arguments
void *thread(void *vargp){
    pthread_mutex_lock(&mutex1);
    paint(counter);    
    counter = counter +1;
    pthread_mutex_unlock(&mutex1);
    return 0;
}

// Write out the PPM file
void savePainting() {
    FILE *fp;
    fp = fopen("threads.ppm", "w");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);
    int i = 0;
    for ( i = 0; i < 64; ++i){
       int j =0;
      for ( j = 0; j < 64*3; ++j){
            fprintf(fp, "%d", colors[i][j]);
            fputs(" ", fp);
      }
     fputs("\n",fp);
    }
    fclose(fp);
}

int main () {
    //Store our Pthread ID
    pthread_t tids[NTHREADS];
    printf("Counter starts at: %d\n", counter);
    // Create and execute multiple threads
    int i =0;
    for(i =0; i< NTHREADS; ++i) {
        pthread_create(&tids[i], NULL, thread, NULL);
    }
    
    // Create and execute multiple threads
    int j=0;
    for(j =0; j< NTHREADS; ++j) {
        pthread_join(tids[j], NULL);
    }
    printf("Final Counter value: %d\n", counter);
    // save painting
    savePainting();

    // end program
    return 0;
}
    
