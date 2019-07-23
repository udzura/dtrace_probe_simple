#include "dtrace_probe_simple.h"

VALUE rb_mDtraceProbeSimple;

void
Init_dtrace_probe_simple(void)
{
  rb_mDtraceProbeSimple = rb_define_module("DtraceProbeSimple");
}
