cmake_minimum_required(VERSION 3.12)
project(Filler C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ipthreads")
set(SOURCE_FILES
        src/filler.c
        src/search_place.c
        src/set_token_coord.c)

include_directories(inc)
link_directories(libft)
add_executable(Filler ${SOURCE_FILES})
target_link_libraries(Filler -lft) # linkage