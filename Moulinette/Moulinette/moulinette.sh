#!/bin/bash
bmain="0"
bexit='0'
logexit=''
exoname=''
exonumber=''
git clone $1 Rendu
while read r; do
	exoname=$(grep name $r |cut -d"'" -f2)
	exonumber=$(grep number $r |cut -d"'" -f2)
	echo "$exonumber - $exoname"
	while read line; do
		if [ "$line" = "int	main(void)" ]
			then
			bmain="1"
		fi
		if [[ "$line" == *"stdio.h"* ]]
			then
			bexit='1'
			logexit='use <stdio.h>' 
			break
			fi
		done < $1.c
	if [ "$bexit" = "0" ]
		then
		if  [ "$bmain" = "0" ]
			then
			gcc Rendu/$number/$exoname.c Exos/header.h Exos/test_$exoname.c -o ex
		else 
			gcc Rendu/$number/$exoname.c -o ex
		fi
		chmod 755 ex
		while read line; do
			echo "test : $line"
 			./ex $line | ./mouliflutes $exoname $line
		done < "../Traces/trace_$1.txt"
	else
		echo " -42, $logexit"
	fi
done < "InfosDays/Day"$2.txt
