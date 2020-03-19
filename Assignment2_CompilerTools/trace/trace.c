#include <stdio.h>
#include <time.h>

// a static global variable used for counting calls.
static int function_counter = 0;

// using <time.h> objects to initiate time tracking variables.
clock_t start_t;
clock_t end_t;

//The syntax __attribute__((constructor)) is used to execute a function when the
//program starts.
void __attribute__((constructor)) executeAtStart();

//The syntax __attribute__((destructor)) is used to execute the function when
//main() function is completed.
void __attribute__((destructor)) executeAtFinish();


__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){
        function_counter++;
	printf("Function entered\n");

}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){
	printf("Function exited\n");

}

void executeAtStart() {
    start_t = clock(); // get current time
}

void executeAtFinish() {
    end_t = clock();
    printf("Function Call Counts = %d\n", function_counter);
    printf("Total Time =  %f seconds\n" , (double)(start_t - end_t)/(CLOCKS_PER_SEC));
}
