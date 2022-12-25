#! /bin/bash
echo Burst Time
while read line
do
    arr=("${arr[@]}" $line)
done

for ((i=0;i<=${#arr[@]}-1;i++))
do
echo ${arr[$i]}
done

echo ${arr[@]:0}
a=${arr[1]:0}
echo $a
