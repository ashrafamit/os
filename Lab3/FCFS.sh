#! /bin/bash
echo Burst Time
while read line
do
    arr=("${arr[@]}" $line)
done

wt=0

for ((i=1;i<${#arr[@]}-1;i++))
do
arr[$i]=$((${arr[$i]}+${arr[$((i-1))]}))
done

for ((i=0;i<${#arr[@]}-1;i++))
do
wt=$(($wt+${arr[$i]}))
done

echo AWT :
awt=$(bc -l <<< "scale=3;$wt/${#arr[@]}")
echo $awt
