#include <sys/sdt.h>
#include "dtrace_probe_simple.h"

static VALUE
rb_do_probe_simple (VALUE mod, VALUE arg0) {
  if(FIXNUM_P(arg0)) {
    DTRACE_PROBE1(ruby-probe, ruby, NUM2LONG(arg0));
  } else {
    DTRACE_PROBE1(ruby-probe, ruby, StringValuePtr(arg0));
  }
  return arg0;
}

void
Init_dtrace_probe_simple(void)
{
  VALUE rb_mDtraceProbeSimple;

  rb_mDtraceProbeSimple = rb_define_module("DTraceProbeSimple");
  rb_define_module_function(rb_mDtraceProbeSimple, "probe", rb_do_probe_simple, 1);
}
