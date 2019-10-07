#!/bin/sh

printf "\x1b[33mShould be done in 12 operations (okay for 8)\x1b[0m\n"
ARG=`ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG

printf "\x1b[33mShould be OK (-50..50)\x1b[0m\n"
ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

printf "\x1b[33mShould be OK (-10..10)\x1b[0m\n"
ARG=`ruby -e "puts (-10..10).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

printf "\x1b[33mShould be OK (-5..9)\x1b[0m\n"
ARG=`ruby -e "puts (-5..9).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

printf "\x1b[33mShould be OK (-3..1)\x1b[0m\n"
ARG=`ruby -e "puts (-3..1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

printf "\x1b[33mShould return Error for ./checker\x1b[0m\n"
./checker
./checker 1 1
./checker sdf fd d

printf "\x1b[33mShould return 0 (or nothing)\x1b[0m\n"
./push_swap 4 5 12 25 89

printf "\x1b[33mShould be done in 2 operations (okay for 3)\x1b[0m\n"
./push_swap 3 2 1

printf "\x1b[33mShould be done in only one swap\x1b[0m\n"
./push_swap 2 1 3

printf "\x1b[33mShould be done in less than 8 operations (5 is good)\x1b[0m\n"
./push_swap 4 6 10 12 19 25 36 29

printf "\x1b[33mShould be done between 5 and 20 operations\x1b[0m\n"
./push_swap 100 1000 10 100000 10000

printf "\x1b[33mShould be done between 5 and 20 operations too\x1b[0m\n"
./push_swap 12 25 5 154 89

printf "\x1b[33m0 9 1 8 2\x1b[0m\n"
ARG="pb\nra\npb\nra\nsa\nra\npa\npa\n"; ARG2="0 9 1 8 2"; echo $ARG | ./checker $ARG2

printf "\x1b[33m0 9 1 8 2 7 3 6 4 5\x1b[0m\n"
ARG="sa\npb\nrrr\n"; ARG2="0 9 1 8 2 7 3 6 4 5"; echo $ARG | ./checker $ARG2

printf "\x1b[33mShould return nothing (or empty line, it's okay)\x1b[0m\n"
./push_swap

printf "\x1b[33mShould return Error (non digit arguments)\x1b[0m\n"
./push_swap 56 76 sig 67 62
./push_swap 56 76 sig 67 62
./push_swap sig 56 121 45 5
./push_swap s

printf "\x1b[33mShould return Error (double)\x1b[0m\n"
./push_swap 15 15
./push_swap 45 12 57 52 33 33
./push_swap 45 12 57 52 33 45

printf "\x1b[33mShould return Error (bigger than integer)\x1b[0m\n"
./push_swap 2147483648
./push_swap 29999999999
./push_swap -2147483649
./push_swap -29999999999

printf "\x1b[33mShould return no operations\x1b[0m\n"
./push_swap 2

printf "\x1b[33mCheck by yourself if the operations solve this : 5 6 2 9 1 3\x1b[0m\n"
./push_swap 5 6 2 9 1 3

printf "\x1b[33mTests with negatives and positives\x1b[0m\n"
./push_swap 2 -5 26 -7888 -998 564 12

printf "\x1b[33mTests with only negatives\x1b[0m\n"
./push_swap -2 -5 -26 -7888 -998 -564 -12

printf "\x1b[33mpush_swap 42\x1b[0m\n"
./push_swap 42

printf "\x1b[33mpush_swap 0 1 2 3 (shuld 0 instructions)\x1b[0m\n"
./push_swap 0 1 2 3

printf "\x1b[33mpush_swap 0 1 2 3 4 5 6 7 8 9(shuld 0 instructions)\x1b[0m\n"
./push_swap 0 1 2 3 4 5 6 7 8 9

printf "\x1b[33mShould be done in 2 operations (okay for 3)\x1b[0m\n"
ARG="2 1 0";./push_swap $ARG

printf "\x1b[33mShould be done in 12 operations (okay for 8)\x1b[0m\n"
ARG="1 5 2 4 3";./push_swap $ARG

printf "\x1b[33mShould be OK (0..99)\x1b[0m\n"
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

printf "\x1b[33mShould be OK (-499..0)\x1b[0m\n"
ARG=`ruby -e "puts (-499..0).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
