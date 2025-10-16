#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    printf("=== PulseGuard User-Space App Started ===\n");

    int event_count = 0;
    int alert_threshold = 5;   // alert if >5 events in interval
    int interval = 30;         // seconds
    time_t start_time = time(NULL);

    srand(time(NULL));

    while (1) {
        // Simulate a pulse event randomly
        int event = rand() % 2;  // 0 = no event, 1 = event occurs
        if (event) {
            event_count++;
            printf("[Event] Pulse event detected! Total events: %d\n", event_count);
        }

        // Check if interval has passed
        time_t current_time = time(NULL);
        if (difftime(current_time, start_time) >= interval) {
            printf("\n=== Summary (last %d seconds) ===\n", interval);
            printf("Total events: %d\n", event_count);
            if (event_count > alert_threshold) {
                printf("!!! ALERT: High number of events detected !!!\n");
            }
            printf("===============================\n\n");

            // Reset for next interval
            event_count = 0;
            start_time = current_time;
        }

        sleep(2); // check every 2 seconds
    }

    return 0;
}
