cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER_WORKS 1)

# TO-DO update this with your path to arm-none-eabi-gcc based on installation
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(LINKER_SCRIPT "../linker.ld")
project(getting-started LANGUAGES C ASM)


set(CPU_OPTIONS -mthumb -mcpu=cortex-m4)

# optimizations (-O0 -O1 -O2 -O3 -Os -Ofast -Og -flto)
set(CMAKE_C_FLAGS_DEBUG "-O0 -DDEBUG -ffreestanding -ggdb")
add_compile_options(
    ${CPU_OPTIONS}
    -g
    -fstrict-volatile-bitfields
    -ffunction-sections
)


# Source directory
set(SRCDIR src)

# TO-DO change target name as per convinience
# Target
set(TARGET main.elf)

# generic include directories
include_directories(
    ${SRCDIR}
)

# Find C source files recursively
file(GLOB_RECURSE SOURCE_FILES ${SRCDIR}/*.c ${SRCDIR}/*.s)

add_executable(${TARGET} ${SOURCE_FILES})

# link command for each lab
target_link_libraries(${TARGET}
  ${CPU_OPTIONS}
  -nostartfiles
  -T${LINKER_SCRIPT}
  -Wl,-Map=lab.map

  # -nostdlib
)
