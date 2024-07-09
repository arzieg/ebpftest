#include <bpf/bpf_helpers.h>
#include <linux/bpf.h>

int counter = 0;

SEC("xdp")

int hello(void *ctx) {
  bpf_printk("Hello World %d", counter);
  counter++;
  return XDP_PASS;
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";