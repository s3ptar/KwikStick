################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/SLCD.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/ProcessorExpert.c \
../Sources/SLCD.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/SLCD_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/ProcessorExpert_c.obj" \
"./Sources/SLCD_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/ProcessorExpert_c.d \
./Sources/SLCD_c.d \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/ProcessorExpert_c.d" \
"./Sources/SLCD_c.d" \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/SLCD_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Events.args" -o "Sources/Events_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/ProcessorExpert.args" -o "Sources/ProcessorExpert_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SLCD_c.obj: ../Sources/SLCD.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/SLCD.args" -o "Sources/SLCD_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


