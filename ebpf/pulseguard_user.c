#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    printf("PulseGuard User-Space App Started!\n");

    int event_count = 0;
    srand(time(NULL));

    while (1) {
        // Simulate a pulse event randomly
        int event = rand() % 2;  // 0 or 1
        if (event) {
            event_count++;
            printf("Pulse event detected! Total events: %d\n", event_count);
        }
        sleep(2); // Check every 2 seconds
    }

    return 0;
}
