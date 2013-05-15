#!/bin/sh

# There are some simple int data pushed in proper order without any delay
# Second process wait for first push and preview each pushed tuple
# After that happens, ... as 1_test ...
# Each process try to get them in the same proper order
# After each successful pull, process wait random ms: from 0 to 1000
# Each process has specific simple timeout to wait for tuple : 500 defined in data file
#
# Test is passed if xor of tests outputs are xored only 111..11 

sh testOneThreePreviewXor.sh data/1_simpleIntPush data/1_simpleIntPull data/3_simpleIntPreview

