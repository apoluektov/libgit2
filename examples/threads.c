#include <pthread.h>

#include "common.h"

void *run(void *data)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        git_libgit2_init();
        git_libgit2_shutdown();
    }
    return data;
}

int main(int argc, char *argv[])
{
    pthread_t threads[10];
    unsigned i;

    for (i = 0; i < sizeof(threads) / sizeof(*threads); i++)
    {
        pthread_create(&threads[i], NULL, run, NULL);
    }

    for (i = 0; i < sizeof(threads) / sizeof(*threads); i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
