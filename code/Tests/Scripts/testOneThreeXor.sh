#!/bin/sh

if [ $# -ne 2 ]; then
	exit 1;
fi

tProg='testProgram'

push=$1
pull=$2

./$tProg 1 0 0 0 < $push > "${push}_a" &
ap=$!
./$tProg 1 0 0 1000 < $pull > "${pull}_b" &
bp=$!
./$tProg 1 0 0 1000 < $pull > "${pull}_c" &
cp=$!
./$tProg 1 0 0 1000 < $pull > "${pull}_d" &
dp=$!

wait $ap
wait $bp
wait $cp
wait $dp

ar=`cat "${push}_a"`
br=`cat "${pull}_b"`
cr=`cat "${pull}_c"`
dr=`cat "${pull}_d"`

rm -f "${push}_a" 2> /dev/null
rm -f "${pull}_b" 2> /dev/null
rm -f "${pull}_c" 2> /dev/null
rm -f "${pull}_d" 2> /dev/null

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
aj=0

for i in `seq 1 $j`
do
	ac=$(at $ar $i)
	bc=$(at $br $i)
	cc=$(at $cr $i)
	dc=$(at $dr $i)

	aj=`expr $aj + $ac`

	x="$bc"
	x=$(xor $x $cc)
	x=$(xor $x $dc)

	res="$res$x"
done

echo "\tXor:\t$res"

if [ "$res" -eq "$ar" ] && [ "$aj" -eq "$j" ]; then
	echo "\nTEST PASSED\n"
else
	echo "\nTEST FAILED\n"
fi
