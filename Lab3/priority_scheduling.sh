#! /bin/bash
echo Priority Scheduling
read -p "Enter number of processes : " n
for ((i=1;i<=$n;i++))
do
    read -p "Burst Time and priority of p$i : " bt[$i-1] pr[$i-1]
done


for ((i=1;i<=$n;i++))
do
    echo "p$i bt:${bt[$i-1]} pr:${pr[$i-1]}"
done


for ((i = 0; i<$n; i++))
do
    for((j = 0; j<$n-i-1; j++))
    do
        if [ ${pr[j]} -gt ${pr[$((j+1))]} ]
        then
            temp=${pr[j]}
            pr[$j]=${pr[$((j+1))]}
            pr[$((j+1))]=$temp

            t=${bt[j]}
            bt[$j]=${bt[$((j+1))]}
            bt[$((j+1))]=$t
        fi
    done
done

for ((i=1;i<$n-1;i++))
do
    bt[$i]=$((${bt[$((i-1))]}+${bt[$i]}))

done


wt=0
for ((i=0;i<$n-1;i++))
do
    wt=$(($wt+${bt[$i]}))
done

awt=$(bc -l <<< "scale=3;$wt/$n")
echo AWT  $awt
