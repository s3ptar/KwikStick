################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ADC2.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/GPIO1.c" \
"../Generated_Code/PDB1.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SegLCD1.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/eDMA1.c" \

C_SRCS += \
../Generated_Code/ADC2.c \
../Generated_Code/Cpu.c \
../Generated_Code/GPIO1.c \
../Generated_Code/PDB1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SegLCD1.c \
../Generated_Code/Vectors.c \
../Generated_Code/eDMA1.c \

OBJS += \
./Generated_Code/ADC2_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/GPIO1_c.obj \
./Generated_Code/PDB1_c.obj \
./Generated_Code/PE_LDD_c.obj \
./Generated_Code/SegLCD1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/eDMA1_c.obj \

OBJS_QUOTED += \
"./Generated_Code/ADC2_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/GPIO1_c.obj" \
"./Generated_Code/PDB1_c.obj" \
"./Generated_Code/PE_LDD_c.obj" \
"./Generated_Code/SegLCD1_c.obj" \
"./Generated_Code/Vectors_c.obj" \
"./Generated_Code/eDMA1_c.obj" \

C_DEPS += \
./Generated_Code/ADC2_c.d \
./Generated_Code/Cpu_c.d \
./Generated_Code/GPIO1_c.d \
./Generated_Code/PDB1_c.d \
./Generated_Code/PE_LDD_c.d \
./Generated_Code/SegLCD1_c.d \
./Generated_Code/Vectors_c.d \
./Generated_Code/eDMA1_c.d \

C_DEPS_QUOTED += \
"./Generated_Code/ADC2_c.d" \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/GPIO1_c.d" \
"./Generated_Code/PDB1_c.d" \
"./Generated_Code/PE_LDD_c.d" \
"./Generated_Code/SegLCD1_c.d" \
"./Generated_Code/Vectors_c.d" \
"./Generated_Code/eDMA1_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ADC2_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/GPIO1_c.obj \
./Generated_Code/PDB1_c.obj \
./Generated_Code/PE_LDD_c.obj \
./Generated_Code/SegLCD1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/eDMA1_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ADC2_c.obj: ../Generated_Code/ADC2.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/ADC2.args" -o "Generated_Code/ADC2_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/Cpu.args" -o "Generated_Code/Cpu_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/GPIO1_c.obj: ../Generated_Code/GPIO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/GPIO1.args" -o "Generated_Code/GPIO1_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PDB1_c.obj: ../Generated_Code/PDB1.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/PDB1.args" -o "Generated_Code/PDB1_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD_c.obj: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/PE_LDD.args" -o "Generated_Code/PE_LDD_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SegLCD1_c.obj: ../Generated_Code/SegLCD1.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/SegLCD1.args" -o "Generated_Code/SegLCD1_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/Vectors.args" -o "Generated_Code/Vectors_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/eDMA1_c.obj: ../Generated_Code/eDMA1.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Generated_Code/eDMA1.args" -o "Generated_Code/eDMA1_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


