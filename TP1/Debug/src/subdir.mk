################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP1\ 2022v2.c \
../src/calculos.c \
../src/funciones.c \
../src/informes.c \
../src/menu.c \
../src/utn.c 

C_DEPS += \
./src/TP1\ 2022v2.d \
./src/calculos.d \
./src/funciones.d \
./src/informes.d \
./src/menu.d \
./src/utn.d 

OBJS += \
./src/TP1\ 2022v2.o \
./src/calculos.o \
./src/funciones.o \
./src/informes.o \
./src/menu.o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/TP1\ 2022v2.o: ../src/TP1\ 2022v2.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TP1 2022v2.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TP1\ 2022v2.d ./src/TP1\ 2022v2.o ./src/calculos.d ./src/calculos.o ./src/funciones.d ./src/funciones.o ./src/informes.d ./src/informes.o ./src/menu.d ./src/menu.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

