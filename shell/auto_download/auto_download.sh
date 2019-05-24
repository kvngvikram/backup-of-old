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

# help source
# https://www.cyberciti.biz/faq/unix-howto-read-line-by-line-from-file/

input="station.csv"
while IFS= read -r station
do
  echo "$station"
  echo "$webb$station$webe"
done < "$input"
