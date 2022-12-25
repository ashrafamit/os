#! /bin/bash
echo Shortest Job First
while read line
do
    sjf=("${sjf[@]}" $line)
done

l=${#sjf[@]}

for ((i = 0; i<$l; i++))
do
    for((j = 0; j<$l-i-1; j++))
    do
        if [ ${sjf[j]} -gt ${sjf[$((j+1))]} ]
        then
            temp=${sjf[j]}
            sjf[$j]=${sjf[$((j+1))]}
            sjf[$((j+1))]=$temp
        fi
    done
done

for ((i=1;i<${#sjf[@]}-1;i++))
do
sjf[$i]=$((${sjf[$((i-1))]}+${sjf[$i]}))

done
wt=0
for ((i=0;i<${#sjf[@]}-1;i++))
do
wt=$(($wt+${sjf[$i]}))
done

awt=$(bc -l <<< "scale=3;$wt/${#sjf[@]}")
echo AWT  $awt
