# Andrew Plum
# Professor Bolden
# CS 270
# 10/29/22

	# ***Assignment #2 - number_line_script.sh*** 

#!/bin/bash
	
	# Declare variables
	
	FILENAME="USER INPUT"
	CHOICE="USER INPUT"
	THROW="DEFAULT"
	DESIRED="DEFAULT"
	IFS=$'\n'
	i=0
	
	# Get user input
	
	read -p "Enter file name that you want action performed on: " FILENAME
	read -p "Enter 1 if you want to add line numbers or 2 if you want to remove line numbers: " CHOICE
	
	# Add line numbers if chosen
	
	if [ $CHOICE -eq 1 ] ; then 
	    while read line
	    do
	        ((i++)) 
	        echo "$i ${line}" >> temp.txt
	    done < $FILENAME
		rm $FILENAME
		mv temp.txt $FILENAME
		echo "Added line numbers to ${FILENAME}." 
	
	# Remove line numbers if chosen
	
	elif [ $CHOICE -eq 2 ] ; then 
		while read line
		do
			IFS=' ' read -r THROW DESIRED <<< "$line"
		    echo "$DESIRED"
	    done < $FILENAME >> temp.txt 
		#cat $FILENAME | awk -F " " '{$1="";print}' | awk 'sub(/^.{1}/,"")' >> temp.txt # Different working implementation
		#cat $FILENAME | awk '{for(i = 2; i <= NF; i++) printf FS$i;}' > temp.txt # Different attempted implementation
		#cat temp.txt | awk '{print substr($0,2)}' > temp.txt # Different attempted implementation
		#cat $FILENAME | awk -F " " '{$1=""; print}' > temp.txt	#Different attempted implementation
		rm $FILENAME
		mv temp.txt $FILENAME
		echo "Removed line numbers from ${FILENAME}." 
	
	# Inform user if no valid choice made
	
	else
		echo "No action performed to ${FILENAME} because no valid choice made." 
	fi
