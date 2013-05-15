#!/bin/sh

# First process has defined specific data which push into server
# Each process has it's own data file
# First gets	1. 4. 7.
# Second gets	2. 5. 8.
# Third gets	3. 6. 9.
# Last tuple can be received by any process, so it's 'determined' by random timeouts
#
# Test is passed if xor of tests outputs are xored only 111..11 

sh testOneThreeXorSpecific.sh data/4_push data/4_firstPull data/4_secondPull data/4_thirdPull

