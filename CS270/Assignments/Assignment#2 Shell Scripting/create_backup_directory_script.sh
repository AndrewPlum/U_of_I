# Andrew Plum
# Professor Bolden
# CS 270
# 10/29/22

    # ***Assignment #2 - create_backup_directory_script.sh*** 

#!/bin/bash

    # Create variables
    
    source="DEFAULT"
    dest="DEFAULT"

    # Create backup folder if needed
    
    if [ -f "backup.backup" ] ; then
        echo "backup.backup already exists."
    else
        echo "backup.backup does not exist."
        mkdir backup.backup
        echo "backup.backup has been created."    
    fi
    
    # Set source and destination variable paths

    source=$(pwd) # source is set to directory above backup directory
    cd backup.backup # change working directory to backup directory
    dest=$(pwd) # destination is set to backup directory
    cd ../ # leave backup directory for directory above

    # File copying code

    for file in $(find $source -printf "%P\n") ; do
        if [ "backup.backup" = $file ] ; then # if file is not the backup file, then do nothing
	        echo ""
        else #else do the copy file code
            if [ $source/$file -nt $dest/$file ] ; then 
                if [ $source/$file -nt $dest/$file ] ; then
                    echo "Newer file $file detected and is being copied."
                    cp -a -r $source/$file $dest/$file
                else
                    echo "File $file exists already in backup."
                fi
            else
                echo "$file is being copied over to $dest"
                cp -a -r $source/$file $dest/$file
            fi
        fi
    done
    
    # Message script done executing
    
    echo ""
    echo "Script done executing."
    echo ""
