#!/bin/bash

# So this is a string
STR="Hello World!"
echo $STR   # printing the string

# beginning of web address
webb="http://geodesy.unr.edu/gps_timeseries/tenv3/IGS08/"
# ending part of web address
webe=".IGS08.tenv3"

web="$webb $webe"
echo $web
