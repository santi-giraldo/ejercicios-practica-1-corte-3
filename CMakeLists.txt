cmake_minimum_required(VERSION 3.10)
project(Asignacion_Corte3)

# Usar el estándar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ejecutable para el Problema 1396 (Underground System)
add_executable(underground_system underground_system.cpp)

# Ejecutable para el Problema 2241 (ATM Machine)
add_executable(atm_machine atm_machine.cpp)

# Ejecutable para el Problema 3815 (Auction System)
add_executable(auction_system auction_system.cpp)

# Ejecutable para el Problema 4 (Meetup Calendar)
add_executable(meetup_calendar meetup_calendar.cpp)

# Ejecutable para el Problema 5 (Clock System)
add_executable(clock_system clock_system.cpp)
