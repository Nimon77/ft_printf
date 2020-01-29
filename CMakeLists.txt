cmake_minimum_required(VERSION 3.10)

project(ft_printf C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-Wextra -Wall -Werror")

include_directories(includes)
include_directories(libft)

file(GLOB LIBFT "libft/*.c")
file(GLOB SRCS "srcs/*.c")

add_executable(ft_printf ${SRCS} ${LIBFT})
