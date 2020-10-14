#!/bin/bash
msg="Homework №2. Bash scripts from lecture."
echo "$msg"
msg="Organize FOLR loop printing even number. From 100 to 1000."
for((i=100;i<=1000;i+=2)); do
    echo "$i"
done
msg="Organaize FOR loop printing the elemens of array."
echo "$msg"
my_array=(apple, banan, "fruit backet", orange)
for val in ${my_array[@]}; do
    echo "Array value: $val"
done
msg="Floating point calculations."
echo "$msg"
echo "Compute using python:"
python3 -c "print(f'10 + 0.5 = {10+0.5}')"
python3 -c "print(f'10 / 0.5 + 2.6 = {10/0.5 + 2.6}')"
echo "Compute using bc:"
echo "scale=4; 1.2+8.2" | bc -q
msg="Check exist directory Linux"
echo "$msg"
if [[ ! -e "Linux" ]]; then
   echo "very easy"
   mkdir "Linux"
else
   echo "course"
   rm -rf "Linux"
fi
