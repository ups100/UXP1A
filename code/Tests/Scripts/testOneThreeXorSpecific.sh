#!/bin/sh

if [ $# -ne 4 ]; then
	exit 1;
fi

tProg='testProgram'

push=$1
pull1=$2
pull2=$3
pull3=$4

./$tProg 1 0 0 0 < $push > "${push}_a" &
ap=$!
./$tProg 1 100 500 1000 < $pull1 > "${pull1}_b" &
bp=$!
./$tProg 1 100 500 1000 < $pull2 > "${pull2}_c" &
cp=$!
./$tProg 1 100 500 1000 < $pull3 > "${pull3}_d" &
dp=$!

wait $ap
wait $bp
wait $cp
wait $dp

ar=`cat "${push}_a"`
br=`cat "${pull1}_b"`
cr=`cat "${pull2}_c"`
dr=`cat "${pull3}_d"`

rm -f "${push}_a" 2> /dev/null
rm -f "${pull1}_b" 2> /dev/null
rm -f "${pull2}_c" 2> /dev/null
rm -f "${pull3}_d" 2> /dev/null

echo ""
echo "$ap\tPushed:\t$ar"
echo "$bp\tPulled:\t$br"
echo "$cp\tPulled:\t$cr"
echo "$dp\tPulled:\t$dr"

at() {
	echo `expr substr $1 $2 1`
}

xor() {
	if [ $1 -eq $2 ]; then
		echo 0
		return
	fi

	echo 1
	return
}

j=`expr length $ar`
res=''

for i in `seq 1 $j`
do
	ac=$(at $ar $i)
	bc=$(at $br $i)
	cc=$(at $cr $i)
	dc=$(at $dr $i)

	x="$bc"
	x=$(xor $x $cc)
	x=$(xor $x $dc)

	res="$res$x"
done

echo "\tXor:\t$res"

if [ "$res" -eq "$ar" ]; then
	echo "\nTEST PASSED\n"
else
	echo "\nTEST FAILED\n"
fi
