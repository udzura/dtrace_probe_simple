# DTraceProbeSimple

A PoC to include `DTRACE_PROBE*` in Ruby.

## Installation

This is only available in Linux for now. Please install `systemtap-sdt-dev` (or alternatives) first.

Add this line to your application's Gemfile:

```ruby
gem 'dtrace_probe_simple'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install dtrace_probe_simple

## Usage

```ruby
puts $$
require "dtrace_probe_simple"
self.extend DtraceProbeSimple

loop do
  probe(Object.new.inspect)
  print "."
  sleep 1
end
```

```console
$ ruby probe.rb
9806
.....
```

Now that USDT<ruby::ruby-probe> is available. You can get data from eBPF/BCC tools such as [mruby-bcc](https://github.com/udzura/mruby-bcc).

```console
$ sudo ./mruby/bin/mruby usdt_str.rb 9806
TIME(s)            COMM             PID    ruby-probe
10423.001144000    ruby             9806   #<Object:0x000056054df498b0>
10424.006953000    ruby             9806   #<Object:0x000056054df497e8>
10425.006879000    ruby             9806   #<Object:0x000056054df49720>
10426.007019000    ruby             9806   #<Object:0x000056054df49608>
10427.006803000    ruby             9806   #<Object:0x000056054df494f0>
10428.007604000    ruby             9806   #<Object:0x000056054df49428>
10429.016610000    ruby             9806   #<Object:0x000056054df49360>
10430.017376000    ruby             9806   #<Object:0x000056054df49298>
10431.017446000    ruby             9806   #<Object:0x000056054df491d0>
10432.017105000    ruby             9806   #<Object:0x000056054df490b8>
10433.017682000    ruby             9806   #<Object:0x000056054df48ff0>
10434.017423000    ruby             9806   #<Object:0x000056054df48f28>
10435.019250000    ruby             9806   #<Object:0x000056054df48e38>
```

## Development

After checking out the repo, run `bin/setup` to install dependencies. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/udzura/dtrace_probe_simple.
