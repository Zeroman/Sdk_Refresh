CHIP		?= best2000

DEBUG		?= 1

FPGA		?= 0

MBED		?= 1

RTOS		?= 1

WATCHER_DOG ?= 1

ifeq ($(CURRENT_TEST),1)
DEBUG_PORT	?= 2
else
DEBUG_PORT	?= 1
endif
# 0: usb
# 1: uart0
# 2: uart1

FLASH_CHIP	?= GD25Q80C GD25Q32C GD25LQ32C EN25S80B P25Q32L P25Q80H
# GD25Q80C
# GD25Q32C
# P25Q32L
# P25Q80H
# ALL

AUDIO_OUTPUT_MONO ?= 0

AUDIO_OUTPUT_DIFF ?= 1

HW_FIR_EQ_PROCESS ?= 0

SW_IIR_EQ_PROCESS ?= 0

HW_DAC_IIR_EQ_PROCESS ?= 0
AUDIO_RESAMPLE ?= 0
export RESAMPLE_ANY_SAMPLE_RATE ?= 1
OSC_26M_X4_AUD2BB ?= 1
AUDIO_OUTPUT_VOLUME_DEFAULT ?= 16
# range:1~16

AUDIO_INPUT_CAPLESSMODE ?= 0

AUDIO_INPUT_LARGEGAIN ?= 0

AUDIO_CODEC_ASYNC_CLOSE ?= 1

AUDIO_SCO_BTPCM_CHANNEL ?= 1

AUDIO_EQ_PROCESS ?= 0

SPEECH_TX_AEC ?= 1

SPEECH_TX_AEC2 ?= 0

SPEECH_TX_AEC2FLOAT ?= 0

SPEECH_TX_NS ?= 0

SPEECH_TX_NS2 ?= 0

SPEECH_TX_NS2FLOAT ?= 1

SPEECH_TX_2MIC_NS2 ?= 0

SPEECH_TX_AGC ?= 0

SPEECH_TX_EQ ?= 1

SPEECH_RX_PLC ?= 1

SPEECH_RX_NS ?= 0

SPEECH_RX_NS2 ?= 0

SPEECH_RX_NS2FLOAT ?= 0

SPEECH_RX_AGC ?= 0

SPEECH_RX_EQ ?= 1

LARGE_RAM ?= 1

HSP_ENABLE ?= 0
HFP_1_6_ENABLE ?= 1

MSBC_PLC_ENABLE ?= 1

MSBC_16K_SAMPLE_RATE ?= 1

SBC_FUNC_IN_ROM ?= 0

APP_LINEIN_A2DP_SOURCE ?= 0

APP_I2S_A2DP_SOURCE ?= 0

VOICE_DETECT ?= 0

VOICE_PROMPT ?= 1

VOICE_RECOGNITION ?= 0

BLE ?= 1

DMA_VOICE ?= 1

export OPUS_CODEC ?= 1

BTADDR_GEN ?= 1

BT_ONE_BRING_TWO ?= 0

A2DP_AAC_ON ?= 1

A2DP_SCALABLE_ON ?= 0

FACTORY_MODE ?= 1

ENGINEER_MODE ?= 1

ULTRA_LOW_POWER	?= 0

DAC_CLASSG_ENABLE ?= 1

NO_SLEEP ?= 1

MEDIA_PLAYER_RBCODEC ?= 0

ASSERT_SHOW_FILE_FUNC ?= 0

export POWER_MODE	?= DIG_DCDC

ifeq ($(CURRENT_TEST),1)
export VCODEC_VOLT ?= 1.5V

export VCORE_LDO_OFF ?= 1
else
export VCODEC_VOLT ?= 1.6V
endif

ifneq ($(SW_PLAYBACK_RESAMPLE),1)
export APP_MUSIC_26M ?= 0
endif

export BT_XTAL_SYNC ?= 1

export FLASH_UNIQUE_ID ?= 1

ifeq ($(MEDIA_PLAYER_RBCODEC),1)
export RB_CODEC := 1
export EQ_PROCESS := 1
export AUDIO_EQ_PROCESS := 1
KBUILD_CPPFLAGS += -DMEDIA_PLAYER_RBCODEC
KBUILD_CPPFLAGS += -DRB_CODEC
KBUILD_CFLAGS += -DCODEC
KBUILD_CFLAGS += -DROCKBOX_LITTLE_ENDIAN
KBUILD_CFLAGS += -DROCKBOX
KBUILD_CFLAGS += -D__PCTOOL__
KBUILD_CFLAGS += -DEQ_PROCESS
CONFIG_CODEC=SWCODEC
endif

init-y		:=
core-y		:= platform/ services/ apps/ utils/cqueue/ utils/list/ services/multimedia/ utils/intersyshci/
KBUILD_CPPFLAGS += -Iplatform/cmsis/inc -Iservices/audioflinger -Iplatform/hal -Iservices/fs/ -Iservices/fs/sd -Iservices/fs/fat  -Iservices/fs/fat/ChaN

KBUILD_CPPFLAGS += \
    -D_BEST1000_QUAL_DCDC_ \
    -D__APP_KEY_FN_STYLE_A__ \
	-D__BES__ \
	-DMCU_HIGH_PERFORMANCE_MODE \
	-DRECORD_LONELY
    
#    -D__PC_CMD_UART__

ifeq ($(CURRENT_TEST),1)
KBUILD_CPPFLAGS += \
    -D__3M_PACK__
endif

KBUILD_CPPFLAGS += -D__EDIFIER_W285A__
KBUILD_CPPFLAGS += -D__EARPHONE_STAY_BOTH_SCAN__
KBUILD_CPPFLAGS += -DBAIDU_DATA_SN_LEN=16
KBUILD_CPPFLAGS += -DFLOW_CONTROL_ON_UPLEVEL=1
KBUILD_CPPFLAGS += -DASSAM_PKT_ON_UPLEVEL=1
KBUILD_CPPFLAGS += -DNVREC_BAIDU_DATA_SECTION=1
KBUILD_CPPFLAGS += -DBAIDU_DATA_RAND_LEN=8
KBUILD_CPPFLAGS += -DCLOSE_BLE_ADV_WHEN_VOICE_CALL=1
KBUILD_CPPFLAGS += -DCLOSE_BLE_ADV_WHEN_SPP_CONNECTED=1
KBUILD_CPPFLAGS += -DBAIDU_RFCOMM_DIRECT_CONN=1
KBUILD_CPPFLAGS += -DBYPASS_SLOW_ADV_MODE=1
#-D_AUTO_SWITCH_POWER_MODE__
#-D_BEST1000_QUAL_DCDC_
#-D__APP_KEY_FN_STYLE_A__
#-D__APP_KEY_FN_STYLE_B__
#-D__BT_ONE_BRING_TWO__
#-D__EARPHONE_STAY_BOTH_SCAN__
#-D__POWERKEY_CTRL_ONOFF_ONLY__
#-DAUDIO_LINEIN

LDS_FILE	:= best1000.lds

KBUILD_CPPFLAGS += -DFLASH_REGION_BASE=FLASH_BASE+0x20000

KBUILD_CPPFLAGS += -DSECURE_BOOT=1
KBUILD_CPPFLAGS += -D__EARPHONE_STAY_BOTH_SCAN__
# KBUILD_CPPFLAGS += -DBYPASS_BATTERY_OPS
KBUILD_CPPFLAGS += -DSW_PLAYBACK_RESAMPLE_441TO48K

KBUILD_CFLAGS +=

LIB_LDFLAGS += -lstdc++ -lsupc++

#CFLAGS_IMAGE += -u _printf_float -u _scanf_float

#LDFLAGS_IMAGE += --wrap main

