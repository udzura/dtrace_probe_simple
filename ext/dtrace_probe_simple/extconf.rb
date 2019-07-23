require "mkmf"

abort "missing <sys/sdt.h>. Please install systemtap-sdt-dev or something like that" unless have_header("sys/sdt.h")

create_makefile("dtrace_probe_simple/dtrace_probe_simple")
