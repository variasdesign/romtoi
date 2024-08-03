while IFS="" read -r line || [ -n "$line" ]
do
	echo "$line -" $(./a.out "$line")
done < test_roman.txt
