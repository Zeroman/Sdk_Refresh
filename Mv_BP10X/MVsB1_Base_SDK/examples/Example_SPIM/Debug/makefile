################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

ifndef ANDESIGHT_ROOT
ANDESIGHT_ROOT=/cygdrive/C/Andestech/AndeSight300RDS
endif

ifndef CROSS_COMPILE
CROSS_COMPILE=nds32le-elf-
endif

ifndef SECONDARY_OUTPUT_PATH
SECONDARY_OUTPUT_PATH=output
endif

$(shell mkdir -p $(SECONDARY_OUTPUT_PATH))

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include driver/driver_api/src/subdir.mk
-include src/subdir.mk
-include startup/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
BUILD_ARTIFACT_FILE_BASE_NAME = Example_SPIM

LINKER_OUTPUTS = Example_SPIM.adx

GCOV_OUT += \
$(foreach subdir,$(SUBDIRS),$(wildcard $(subdir)/*.gcda) $(wildcard $(subdir)/*.gcno)) \

GPROF_OUT += \
../gmon.sum ../gmon.out \

SYMBOL_OUTPUTS += \
$(SECONDARY_OUTPUT_PATH)/symbol.txt \

READELF_OUTPUTS += \
$(SECONDARY_OUTPUT_PATH)/readelf.txt \

OBJCOPY_OUTPUTS += \
$(SECONDARY_OUTPUT_PATH)/$(BUILD_ARTIFACT_FILE_BASE_NAME).bin \

SIZE_OUTPUTS += \
$(SECONDARY_OUTPUT_PATH)/.PHONY.size \


# ����Ŀ��
all: Example_SPIM.adx secondary-outputs

# ���ߵ���
Example_SPIM.adx: $(OBJS) $(USER_OBJS)
	@echo '���ڹ���Ŀ�꣺ $@'
	@echo '���ڵ��ã� Andes C Linker'
	$(CROSS_COMPILE)gcc -Og -nostartfiles -static -L"/cygdrive/F/Soft_sdk/Mv_BP10X/MVsB1_Base_SDK/driver/driver" -mcmodel=medium -ldsp -mext-dsp -T"../nds32-ae210p.ld" -Wl,--gc-sections -mvh -o "Example_SPIM.adx" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo '�ѽ�������Ŀ�꣺ $@'
	@echo ' '

$(foreach subdir,$(SUBDIRS),$(wildcard $(subdir)/*.gcda) $(wildcard $(subdir)/*.gcno)): Example_SPIM.adx $(OBJS) $(USER_OBJS)
../gmon.sum ../gmon.out: Example_SPIM.adx $(OBJS) $(USER_OBJS)

$(SECONDARY_OUTPUT_PATH)/symbol.txt: $(LINKER_OUTPUTS)
	@echo '���ڵ��ã� NM (symbol listing)'
	$(CROSS_COMPILE)nm -n -l -C "Example_SPIM.adx" > $(SECONDARY_OUTPUT_PATH)/symbol.txt
	@echo '�ѽ��������� $@'
	@echo ' '

$(SECONDARY_OUTPUT_PATH)/readelf.txt: $(LINKER_OUTPUTS)
	@echo '���ڵ��ã� Readelf (ELF info listing)'
	$(CROSS_COMPILE)readelf -a "Example_SPIM.adx" > $(SECONDARY_OUTPUT_PATH)/readelf.txt
	@echo '�ѽ��������� $@'
	@echo ' '

: $(LINKER_OUTPUTS)
	@echo '���ڵ��ã� Objdump (disassembly)'
	$(CROSS_COMPILE)objdump -x -d -C "Example_SPIM.adx" >
	@echo '�ѽ��������� $@'
	@echo ' '

$(SECONDARY_OUTPUT_PATH)/$(BUILD_ARTIFACT_FILE_BASE_NAME).bin: $(LINKER_OUTPUTS)
	@echo '���ڵ��ã� Objcopy (object content copy)'
	$(CROSS_COMPILE)objcopy -S -O binary "Example_SPIM.adx" $(SECONDARY_OUTPUT_PATH)/$(BUILD_ARTIFACT_FILE_BASE_NAME).bin
	@echo '�ѽ��������� $@'
	@echo ' '

$(SECONDARY_OUTPUT_PATH)/.PHONY.size: $(LINKER_OUTPUTS)
	@echo '���ڵ��ã� Size (section size listing)'
	$(CROSS_COMPILE)size  "Example_SPIM.adx" | tee $(SECONDARY_OUTPUT_PATH)/.PHONY.size
	@echo '�ѽ��������� $@'
	@echo ' '

# ����Ŀ��
clean:
	-$(RM) $(OBJCOPY_OUTPUTS)$(OBJS)$(C_DEPS)$(GCOV_OUT)$(SYMBOL_OUTPUTS)$(READELF_OUTPUTS)$(GPROF_OUT)$(SIZE_OUTPUTS)$(EXECUTABLES)$(S_UPPER_DEPS) Example_SPIM.adx
	-@echo ' '

secondary-outputs: $(SYMBOL_OUTPUTS) $(READELF_OUTPUTS) $(OBJCOPY_OUTPUTS) $(SIZE_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:
.NOTPARALLEL: pre-build

-include ../makefile.targets