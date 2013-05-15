#!/bin/sh

if [ $# -ne 1 ]; then
	exit 1;
fi

tProg='testProgram'

pull=$1

a=0

./$tProg 1 0 0 0 < $pull > "${pull}_a" &
ap=$!

wait $ap

ar=`cat "${pull}_a"`

rm -f "${pull}_a" 2> /dev/null

echo ""
echo "$ap\tPulled:\t$ar"

at() {
	echo `expr substr $1 $2 1`
}

res=0

for i in `seq 1 $j`
do
	ac=$(at $ar $i)

	res=`expr $res + $ac`
done

if [ $res -eq 0 ]; then
	echo "\nTEST PASSED\n"
else
	echo "\nTEST FAILED\n"
fi
