################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include U8GLIB/u8glib/subdir.mk
-include U8GLIB/fntsrc/subdir.mk
-include U8GLIB/Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := OCTOS_Controle_VISION_v9
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
OCTOS_Controle_VISION_v9.elf \

MAP_FILES += \
OCTOS_Controle_VISION_v9.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
OCTOS_Controle_VISION_v9.list \


# All Target
all: main-build

# Main-build Target
main-build: OCTOS_Controle_VISION_v9.elf secondary-outputs

# Tool invocations
OCTOS_Controle_VISION_v9.elf OCTOS_Controle_VISION_v9.map: $(OBJS) $(USER_OBJS) C:\Users\LucasLaurindo\Documents\ENGENHARIA\PRESSOR\Workspace_current\OCTOS_Controle_VISION_v9\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "OCTOS_Controle_VISION_v9.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\LucasLaurindo\Documents\ENGENHARIA\PRESSOR\Workspace_current\OCTOS_Controle_VISION_v9\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="OCTOS_Controle_VISION_v9.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

OCTOS_Controle_VISION_v9.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "OCTOS_Controle_VISION_v9.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) OCTOS_Controle_VISION_v9.elf OCTOS_Controle_VISION_v9.list OCTOS_Controle_VISION_v9.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
