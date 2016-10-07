#!/bin/bash

for filename in data/*.tsp; do

    bin/InsercionMinima "$filename" > solutions/InsercionMinima/"${filename#data/}"

done 
