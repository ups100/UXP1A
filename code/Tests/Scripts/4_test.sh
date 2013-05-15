#!/bin/sh

# There are some simple int data pushed in proper order without any delay
# Each process try to get any of them
#
# Test is passed if length of pushed tuples equals successful pulled tuples

sh testOneThreeSum.sh data/1_simpleIntPush data/2_simpleAnyIntPull

