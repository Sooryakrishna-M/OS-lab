echo -n "Enter the value for A :"
read a
echo -n "Enter the value for B :"
read b
t=$a a=$b b=$t
echo "Value after swapping"
echo "A value is $a"
echo "B value is $b";