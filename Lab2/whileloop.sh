#! /bin/bash

echo "without relational sign : "
i=1
while [ $i -lt 10 ]
do
echo $i
((i++))
done

echo "using relational sign: "
p=1
while (($p <= 10 ))  
do
echo $p
((p++))
done
