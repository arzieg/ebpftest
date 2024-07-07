#!/usr/bin/env python

from bcc import BPF

program = r"""
BPF_PROG_ARRAY(syscall, 300);

int hello(struct bpf_raw_tracepoint_args *ctx) {
  int opcode = ctx->args[1];
  syscall.call(ctx, opcode);
  bpf_trace_printk("Another syscall: %d", opcode);
  return 0;
}

int hello_execve(void *ctx) {
  bpf_trace_printk("Executing a program");
  return 0;
}

int hello_timer(struct bpf_raw_tracepoint_args *ctx){
  if (ctx->args[1] == 222 {
      bpf_trace_printk("Creating a timer");
  } else if (ctx->args[1] == 226) {
      bpf_trace_printk("Deleting a time");
  } else {
      bpf_trace_printk("Some other timer operation");
  }
  return 0;

}

int ignore_opcode(void *ctx) {
  return 0;
}
"""

b = BPF(text=program)
syscall = b.get_syscall_fnname("execve")
b.attach_kprobe(event=syscall, fn_name="hello")


def print_event(cpu, data, size):
    data = b["output"].event(data)
    print(f"{data.pid} {data.uid} {data.command.decode()} " +
          f"{data.message.decode()}")


b["output"].open_perf_buffer(print_event)
while True:
    b.perf_buffer_poll()
