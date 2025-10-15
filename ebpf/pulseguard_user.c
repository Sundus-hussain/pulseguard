#include <bpf/libbpf.h>
#include <bpf/bpf.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("PulseGuard user-space app started...\n");

    // Load BPF object file
    struct bpf_object *obj;
    int err = bpf_object__open_file("pulseguard_kern.o", NULL, &obj);
    if (err) {
        fprintf(stderr, "Failed to open BPF object file\n");
        return 1;
    }

    // Load BPF program into kernel
    if (bpf_object__load(obj)) {
        fprintf(stderr, "Failed to load BPF program\n");
        return 1;
    }

    printf("BPF program loaded successfully!\n");
    printf("Monitoring syscalls... press Ctrl+C to exit.\n");

    // For simplicity, just sleep to keep program running
    while (1) {
        sleep(5);
    }

    bpf_object__close(obj);
    return 0;
}
