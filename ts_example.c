#include "time_stats.h"
#include <inttypes.h>
#include <stdlib.h>

int main()
{
    int i;
    volatile uint64_t j = 0;

    time_stats_t ts;
    time_stats_init_named(&ts, "volatile 10k add loops");

    for (i = 0 ; i < 10000 ; i++) {
        time_stats_start (&ts);

        srand(1);
    
        for (j = 0 ; j < 10000+(rand()%10000) ; j++);

        double t = time_stats_stop (&ts);
        //printf ("%.6f ", t);
    }
    printf("\n\n");

    time_stats_print(&ts);

    //run one more and print again, with tail latencies
    time_stats_enable_tail_latencies(&ts);

    time_stats_start (&ts);
    for (j = 0 ; j < 10000 ; j++);
    time_stats_stop (&ts);

    printf ("Enabling tail latencies, adding one run:\n");
    time_stats_print (&ts);

    time_stats_destroy (&ts);

    return 0;
}