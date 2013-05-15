#!/bin/sh

# There is no data pushed into server
# One process try to pull some data, timeout always occur
#
# Test is passed if prorcess result output is built of 0 only 

sh testZeroOneNone.sh data/5_pullUnreach

