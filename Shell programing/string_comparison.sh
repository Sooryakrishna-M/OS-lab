echo Enter the first string
read s1
echo Enter the second string
read s2
if [ "$s1" = "$s2" ]
then 
echo Strings are equal
else
echo Strings are not equal
fi