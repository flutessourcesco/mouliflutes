#!/bin/bash
bmain="0"
bexit='0'
logexit=''
exoname=""
exonumber=""
readname="0"
rm -rf Rendu
git clone $1 Rendu
while read r; do
	if [ "$readname" = "0" ]
		then
		exonumber="$r"
		readname="1";
	else
		readname="0";
		exoname="$r"
		while read line; do
			if [ "$line" = "int	main(void)" ]
				then
				bmain="1"
			fi
			if [[ "$line" == *"stdio.h"* ]]
				then
				bexit="1"
				logexit="use <stdio.h>"
				break
			fi
		done < "Rendu/ex$exonumber/$exoname.c"
		if [ "$bexit" = "0" ]
			then
			if  [ "$bmain" = "0" ]
				then
				gcc Rendu/ex$exonumber/$exoname.c Exos/header.h Exos/test_$exoname.c -o ex
			else 
				gcc Rendu/ex$exonumber/$exoname.c -o ex
			fi
			chmod 755 ex
			while read line; do
				echo "$exoname"
				echo "test : $line"
 				./ex $line | ./mouliflutes $exoname $line
			done < "../Traces/trace_$exoname.txt"
		else
			echo " -42, $logexit"
		fi
	fi
done < "InfosDays/Day$2.txt"
