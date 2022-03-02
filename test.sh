#!/bin/bash
# make -C philo_bonus && clear
# exe=./philo_bonus/philo_bonus
make -C philo && clear
exe=./philo/philo

tests=10

x=1
time=0.1
echo -e "\e[41;30m 2 100 200 200 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 2 100 200 200 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 2 150 360 100 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 2 150 360 100 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 2 150 200 100 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 2 150 200 100 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 1 400 100 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 1 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m 4 210 100 100 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 4 210 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 1 800 200 200 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 1 800 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m 5 800 200 200 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 5 800 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 4 310 200 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 4 310 200 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m 5 400 100 100 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 5 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 5 200 100 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 5 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m 3 400 100 100 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 3 400 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 3 200 100 100 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 3 200 100 100 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[42;30m 4 410 200 200 7 not die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;32mTest: $x\e[0m"
	$exe 4 410 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

x=1
time=0.1
echo -e "\e[41;30m 4 399 200 200 7 should die\e[0m"
while [ $x -le $tests ]
do
	echo -e "\e[1;31mTest: $x\e[0m"
	$exe 4 399 200 200 7 | grep die
	sleep $time
	x=$(( $x + 1 ))
done

echo

make -C ./philo fclean
make -C ./philo_bonus fclean
