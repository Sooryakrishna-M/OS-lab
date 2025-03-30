echo -n "Enter the Fahrenheit: "
read f
c=`expr \( $f - 32 \) \* 5 / 9`
echo "Centigrade is: $c"
