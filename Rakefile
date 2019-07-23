require "bundler/gem_tasks"
require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("dtrace_probe_simple") do |ext|
  ext.lib_dir = "lib/dtrace_probe_simple"
end

task :default => [:clobber, :compile, :spec]
