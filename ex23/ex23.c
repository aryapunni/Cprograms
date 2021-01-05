#include <string.h>
#include "dbg.h"
#include <stdio.h>
#include <time.h>

int normal_copy(char *from, char *to, int count)
{
    int i = 0;
    for(i = 0; i < count; i++)
    {
        to[i] = from[i];
    }
    return i;
}

int duffs_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;
        int mod = count % 8;

        switch (count % 8)
        {
            case 0:

                do
                {
                    *to++ = *from++;
                    case 7:
                        *to++ = *from++;
                    case 6:
                        *to++ = *from++;
                    case 5:
                        *to++ = *from++;
                    case 4:
                        *to++ = *from++;
                    case 3:
                        *to++ = *from++;
                    case 2:
                        *to++ = *from++;
                    case 1:
                        *to++ = *from++;
                } while(--n > 0);
        }

    }   
    return count;
}

int zeds_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;

        switch (count % 8)
        {
            case 0:
again:         *to++ = *from++;
            case 7:
                *to++ = *from++;
            case 6:
                *to++ = *from++;
            case 5:
                *to++ = *from++;
            case 4:
                *to++ = *from++;
            case 3:
                *to++ = *from++;
            case 2:
                *to++ = *from++;
            case 1:
                *to++ = *from++;
                if(--n > 0)
                    goto again;
        }

    }
    return count;
}


int valid_copy(char *data, int count, char expects)
{
    int i = 0;
    for(i = 0; i < count; i++)
    {
        if(data[i] != expects)
        {
            log_err("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }
}
int main(int argc, char * argv[])
{
    char from[1000] = {'a'};
    char to[1000] = {'c'};
    int rc = 0;
    clock_t t;
    clock_t t1;
    clock_t t2;
    clock_t t3;


    //set up the from to have some stuff
    memset(from, 'x', 1000);
    //set it to a failiure mode
    memset(to, 'y', 1000);
    check(valid_copy(to, 1000, 'y'), "Not initialised right");

    //use normal copy to
    t = clock();
    rc = normal_copy(from, to, 1000);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    log_info("time taken: %f", time_taken);
    check(rc == 1000, "Normal copy failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Normal copy failed");

    //reset
    memset(to, 'y', 1000);

    //duffs version
    t1 = clock();
    rc = duffs_device(from, to, 1000);
    t1 = clock() - t1;
    time_taken = ((double)t1)/CLOCKS_PER_SEC;
    log_info("time taken: %f", time_taken);
    check(rc == 1000, "Duff's device failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Duff's device failed copy.");

    //reset
    memset(to, 'y', 1000);

    //duffs version

    t2 = clock();
    rc = zeds_device(from, to, 1000);
    t2 = clock() - t2;
    time_taken = ((double)t2)/CLOCKS_PER_SEC;
    log_info("time taken: %f", time_taken);
    check(rc == 1000, "Zed's device failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");

    //reset
    memset(to, 'y', 1000);

    t3 = clock();
 //   memcpy(to, from, 1000);
    strncpy(to, from, 1000);
    t3 = clock() - t3;
    time_taken = ((double)t3)/CLOCKS_PER_SEC;
    log_info("time taken: %f", time_taken);

    check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");
    return 0;
error:
    return 1;

}
