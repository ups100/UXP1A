#!/bin/sh

if [ $# -ne 1 ]; then
	exit 1;
fi

tProg='testProgram'

push=$1

a=0

./$tProg 1 0 0 0 < $push > "${push}_a" &
ap=$!

wait $ap

ar=`cat "${push}_a"`

rm -f "${push}_a" 2> /dev/null

echo ""
echo "$ap\tResult:\t$ar"

at() {
	echo `expr substr $1 $2 1`
}

j=`expr length $ar`
res=0

for i in `seq 1 $j`
do
	ac=$(at $ar $i)

	res=`expr $res + $ac`
done

echo ""
echo "Result Length:\t$j"
echo "Success amount:\t$res"

if [ "$res" -eq "$j" ]; then
	echo "\nTEST PASSED\n"
else
	echo "\nTEST FAILED\n"
fi
