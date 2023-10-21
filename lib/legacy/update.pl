#!/usr/bin/perl
use warnings;
use strict;
use File::Basename;

my @libs = (glob('../*.so'), glob('../NSG/*.so'), glob('../SG/*.so'), glob('../ELKA/*.so'));
for my $lib (@libs) {
	$lib = basename($lib);
	if ($lib =~ /^(lib[a-z0-9_+]+)-/i) {
		my $name = $1;
		print "$name.so -> $lib\n";
		
		open F, ">$name.so";
		print F $lib;
		close F;
	}
}
