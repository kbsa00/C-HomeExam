cmake_minimum_required(VERSION 3.8)
project(EksamensOppgave)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c header.h functions.c)
add_executable(EksamensOppgave ${SOURCE_FILES})