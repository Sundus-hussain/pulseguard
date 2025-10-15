from bcc import BPF

# Simple eBPF program: count python processes
bpf_program = """
int kprobe__sys_clone(void *ctx) {
    bpf_trace_printk("Process cloned\\n");
    return 0;
}
"""

b = BPF(text=bpf_program)
print("Tracing process creation... Press Ctrl+C to exit.")
b.trace_print()
