#!/bin/bash


for((I=30; I<150; I=I+30))
do
	./practica2dyv $I >> DyV.dat 
done

