#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_PERF_EVENT_ARRAY);
} events SEC(".maps");

// Trace write syscalls
SEC("tracepoint/syscalls/sys_enter_write")
int handle_write(struct trace_event_raw_sys_enter *ctx) {
    bpf_printk("PulseGuard: write syscall detected!\n");
    return 0;
}

char LICENSE[] SEC("license") = "GPL";
