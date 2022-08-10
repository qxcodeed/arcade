#!/bin/bash
. common_script.sh
check_program g++
get_source_files cpp
eval g++ -Wall $SOURCE_FILES -o vpl_execution