#!/bin/bash

## PATH VARS
BIN_PATH=./bin/philo
MAKEFILE_PATH=./
## UNCOMMENT BONUS TESTS IF NEEDED
# BONUS_BIN_PATH=./philo_bonus/philo_bonus
# BONUS_MAKEFILE_PATH=./

## TEST PARAMETERS - CHANGE AS NEEDED
NB_OF_TESTS=10
RESULTS_FOLDER='test_results'

## TEST FUNCTION DEFINITION
run_test_case() {
	CASE_NO=$1
	CASE=$2
	EXPECTED_OUTCOME=$3
	FONT_COLOUR_BG=''
	FONT_COLOUR=''

	i=1
	time=0.1

	if [[ $EXPECTED_OUTCOME == "should die" ]]
	then
		COLOUR_BG="\e[1;31mTest:"
		FONT_COLOUR_BG="\e[41m"
	else
		COLOUR_BG="\e[1;32mTest:"
		FONT_COLOUR_BG="\e[42m"
	fi
	
	mkdir -p "$RESULTS_FOLDER/$CASE_NO"
	echo -e "$FONT_COLOUR_BG $CASE $EXPECTED_OUTCOME\e[0m"
	while [ $i -le $NB_OF_TESTS ]
	do
		echo -e "$COLOUR_BG $i\e[0m"
		$BIN_PATH $CASE > "$RESULTS_FOLDER/$CASE_NO/test$i"
		cat "$RESULTS_FOLDER/$CASE_NO/test$i" | grep 'die'
		sleep $time
		i=$(( $i + 1 ))
	done
	echo
}

## RUN SCRIPT
make -C $MAKEFILE_PATH && clear
mkdir -p $RESULTS_FOLDER
run_test_case "case_00" "1 400 100 100 7" "should die"
run_test_case "case_01" "4 210 100 100 7" "should not die"
run_test_case "case_02" "1 800 200 200 7" "should die"
run_test_case "case_03" "5 800 200 200 7" "should not die"
run_test_case "case_04" "4 310 200 100 7" "should die"
run_test_case "case_05" "5 400 100 100 7" "should not die"
run_test_case "case_06" "5 200 100 100 7" "should die"
run_test_case "case_07" "3 400 100 100 7" "should not die"
run_test_case "case_08" "3 200 100 100 7" "should die"
run_test_case "case_09" "4 410 200 200 7" "should not die"
run_test_case "case_10" "4 399 200 200 7" "should die"
make -C $MAKEFILE_PATH fclean

## UNCOMMENT BONUS TESTS IF NEEDED
# make -C $BONUS_MAKEFILE_PATH && clear
# mkdir -p "bonus_$RESULTS_FOLDER"
# run_test_case "bonus_case_00" "1 400 100 100 7" "should die"
# run_test_case "bonus_case_01" "4 210 100 100 7" "should not die"
# run_test_case "bonus_case_02" "1 800 200 200 7" "should die"
# run_test_case "bonus_case_03" "5 800 200 200 7" "should not die"
# run_test_case "bonus_case_04" "4 310 200 100 7" "should die"
# run_test_case "bonus_case_05" "5 400 100 100 7" "should not die"
# run_test_case "bonus_case_06" "5 200 100 100 7" "should die"
# run_test_case "bonus_case_07" "3 400 100 100 7" "should not die"
# run_test_case "bonus_case_08" "3 200 100 100 7" "should die"
# run_test_case "bonus_case_09" "4 410 200 200 7" "should not die"
# run_test_case "bonus_case_10" "4 399 200 200 7" "should die"
# make -C $BONUS_MAKEFILE_PATH fclean
