#!/bin/bash

# Function to generate random numbers and count instructions
test() {
    local count=$1
    numbers=$(python -c "import random; print(' '.join(map(str, random.sample(range(-999999, 999999), $count))))")
    instruction_count=$(./push_swap $numbers | wc -l)
    echo $instruction_count
}

# ANSI escape codes for text colors
DEF_COLOR='\033[0;39m'
BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
MAGENTA='\033[0;35m'

echo -e "${YELLOW}"
echo "
______              _                                   
| ___ \            | |                                  
| |_/ / _   _  ___ | |__    ___ __      __  __ _  _ __  
|  __/ | | | |/ __|| '_ \  / __|\ \ /\ / / / _  ||  _ \ 
| |    | |_| |\__ \| | | | \__ \ \ V  V / | (_| || |_) |
\_|     \__,_||___/|_| |_| |___/  \_/\_/   \__ _||  __/ 
                                                 | |    
                                                 |_|    
"

echo -e "${DEF_COLOR}"

echo -e "${BLUE}------------------------------------------------------\n"
echo -e "${MAGENTA}\t\t Created by youchen\n${DEF_COLOR}"
echo -e "${BLUE}------------------------------------------------------\n"

while true; do
    read -p "$(echo -e "${BLUE}Enter the number of elements (e.g., 500):${DEF_COLOR} ")" element_count
    element_count="${element_count// /}"
    if [[ -n $element_count && $element_count =~ ^[0-9]+$ ]]; then
        break
    else
        echo "Invalid input. Please enter a valid number."
    fi
done

instruction_count=$(test $element_count)

while ((instruction_count <= 5500))
do
    echo -e "${GREEN}Success: The program sorted the numbers in $instruction_count instructions.${DEF_COLOR}"
    instruction_count=$(test $element_count)
done

echo -e "${RED}Failure: The program used $instruction_count instructions, which is too many.${DEF_COLOR}"