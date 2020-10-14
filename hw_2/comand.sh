#!/bin/bash
echo "Organize FOR loop printing even number. From 100 to 1000."
for((i=100;i<=1000;i+=2)); do
    echo "$i"
done

echo "Organaize FOR loop printing the elemens of array."
arr=(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
for val in ${arr[@]}; do
    echo "$val"
done

echo "Compute 100 + 0.5 in bash."
echo "100+0.5" | bc -q

echo "Check exist directory Linux"
if [[ ! -e "Linux" ]]; then
   echo "very easy"
   mkdir "Linux"
else
   echo "course"
   rm -rf "Linux"
fi
