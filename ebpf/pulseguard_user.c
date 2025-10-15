#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    printf("PulseGuard User-Space App Started!\n");

    int event_count = 0;
    srand(time(NULL));

    while (1) {
        int event = rand() % 2;  // simulate event
        if (event) {
            event_count++;
            printf("Pulse event detected! Total events: %d\n", event_count);
        }
        sleep(2);
    }

    return 0;
}
