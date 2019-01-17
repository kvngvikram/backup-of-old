#! /bin/bash
echo "Hello world"

# this is a comment 
echo "hello again " # this is also a comment

echo 
echo

# System variables start with a Capital letter
# User definced variables can be anything 

# Printing a system variable
echo $BASH # This gives the location of bash directory

echo Our bash version is $BASH_VERSION

echo $HOME # Location of home directory
echo $PWD # location of working directory


# user definced variables : 

# this is a user defined variable, and there should not be a space between naime and =, variable name is Vikram
name=Vikram

echo 
echo 
echo The user definced variable is $name

# taking input from user
echo "Enter names please : "
read name1 
echo entered name is $name1

# -p flag for typing in same line
# -ps flag to not show what is being typed like password
# -a if array is being entered
read -p 'enter two more names here : ' name2 myname3 
echo entered names are $name2 and $myname3 


# number variable try, these are not int or float, these are like commands
somenumber=1 
echo the number is $somenumber

newnumber=34
echo newnumber is $newnumber
 
firstaurgument=$1
echo \n first aurgument is $firstaurgument
