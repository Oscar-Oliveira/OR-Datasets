#!/bin/bash

echo "-----------------------------ALNS 50-------------------------------------------------------">> experimentosALNS.txt 
for instancia in $(find Instances/ -name "*50.txt" | sort -t '/' -k2.5)
do
	bin/ALNS50 $instancia 10 0.65 260 19 10 18 0.9 0.9 0.4 50 1329 >> experimentosALNS.txt
done

echo "-----------------------------ALNS 100-------------------------------------------------------">> experimentosALNS.txt 
for instancia in $(find Instances/ -name "*100.txt" | sort -t '/' -k2.5)
do
	bin/ALNS100 $instancia 10 0.65 260 19 10 18 0.9 0.9 0.4 50 5913 >> experimentosALNS.txt
done