cmake_minimum_required(VERSION 3.10)

project(ft_printf C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_FLAGS "-Wextra -Wall")

include_directories(include)
include_directories(libft)
#add_subdirectory(libft)

file(GLOB LIBFT "libft/*.c")
file(GLOB SRCS "srcs/*.c")
#set(SRCS
#        main.c
#        ft_printf.c
#        ft_printf_simple.c
#        ft_printf_uint.c)

#set(HEADERS
#        libftprintf.h
#        )


add_executable(ft_printf ${SRCS} ${LIBFT})
#set_target_properties(ft_printf PROPERTIES LINKER_LANGUAGE C)
#target_link_libraries(ft_printf ft)