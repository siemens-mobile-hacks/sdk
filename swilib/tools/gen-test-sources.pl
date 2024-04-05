#!/usr/bin/env perl
use warnings;
use strict;
use File::Basename;

my $root = dirname(__FILE__)."/../";

mkdir "$root/swilib-smoke-test" if !-d "$root/swilib-smoke-test";

for my $h (glob("$root/include/swilib/*.h")) {
	$h = basename($h);
	open F, ">$root/swilib-smoke-test/$h.c" or die ("open($root/swilib-smoke-test/$h.c): $!");
	print F "#include <swilib/$h>\n";
	close F;
}
