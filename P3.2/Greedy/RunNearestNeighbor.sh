#!/bin/bash

for filename in data/*.tsp; do

    bin/VecinoMasCercano "$filename" > solutions/VecinoMasCercano/"${filename#data/}"

done 
