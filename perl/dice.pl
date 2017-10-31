#!/usr/bin/perl

use strict;
use warnings;

use BSD::arc4random qw/arc4random_uniform/;

my ($number, $limit, $total);

sub error {
        print "Usage: dice.pl <number of dice> <sides in dice>\n";
        exit 1;
}

if ($#ARGV != 1) {
        error();
}

# Make sure that our arguments are integers; take advantage of lazy
# evaluation of boolean expressions
if ($ARGV[0] !~ /\d*/ || $ARGV[0] < 1) { 
        error();
}

$number = $ARGV[0];

if ($ARGV[1] !~ /\d*/ || $ARGV[1] < 1) { 
        error();
}

$limit = $ARGV[1];

for my $i (1..$number) {
        my $res = arc4random_uniform($limit) + 1;
        print "Dice roll $i: $res\n";
        $total += $res;
}

print "Total: $total\n";

