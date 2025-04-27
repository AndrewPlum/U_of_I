# Andrew Plum
# Professor Bolden
# CS 270
# 10/29/22

	# ***Assignment #2 - change_file_name_script.sh*** 

#!/bin/bash

	# Declare variables

	FILENAME="USER INPUT"
	FILENAME_COPY="DEFAULT"
	                    
	# Get user input
	                        
	read -p "Enter file name whose name you want action changed: " FILENAME
	FILENAME_COPY=$FILENAME

	# Change name of file chosen
	
	FILENAME=$(echo "$FILENAME" | tr 'A-Z' 'a-z')
	FILENAME=$(echo "$FILENAME" | tr -d '_')
	mv $FILENAME_COPY $FILENAME
	echo "Changed the file named $FILENAME_COPY to ${FILENAME}."
