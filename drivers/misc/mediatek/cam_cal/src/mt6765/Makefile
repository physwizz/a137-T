#
# Copyright (C) 2022 MediaTek Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
MTK_CUSTOM_PATH := $(srctree)/drivers/misc/mediatek
MTK_PLATFORM := $(subst ",,$(CONFIG_MTK_PLATFORM))
CAM_CAL_SRC_PATH := $(MTK_CUSTOM_PATH)/cam_cal/src
CAM_CAL_PLATFORM_SRC_PATH := $(CAM_CAL_SRC_PATH)/$(MTK_PLATFORM)
ARCH_MTK_PROJECT := $(subst ",,$(CONFIG_ARCH_MTK_PROJECT))
COMMON_VERSION := v1

subdir-ccflags-y += -I$(MTK_CUSTOM_PATH)/imgsensor/inc \
                    -I$(MTK_CUSTOM_PATH)/imgsensor/src/$(CONFIG_MTK_PLATFORM)/camera_hw \
                    -I$(MTK_CUSTOM_PATH)/imgsensor/src/common/sysfs \
                    -I$(MTK_CUSTOM_PATH)/cam_cal/inc \
                    -I$(MTK_CUSTOM_PATH)/lens \
                    -I$(CAM_CAL_PLATFORM_SRC_PATH) \
                    -I$(CAM_CAL_SRC_PATH)/common/$(COMMON_VERSION)
subdir-ccflags-y += -I$(srctree)/drivers/i2c/busses/

# Common code
obj-y += ../common/$(COMMON_VERSION)/eeprom_driver.o
obj-y += ../common/$(COMMON_VERSION)/eeprom_i2c_common_driver.o

# Platform code
obj-y += eeprom_i2c_custom_driver.o

# Project specific cam_cal_list & eeprom_i2c_dev files
ifdef CONFIG_CAMERA_SAMSUNG_MODEL_NAME
CAM_CAL_MODEL_FOLDER := camera_project/$(subst ",,$(CONFIG_CAMERA_SAMSUNG_MODEL_NAME))/
ifneq ($(wildcard $(CAM_CAL_PLATFORM_SRC_PATH)/$(CAM_CAL_MODEL_FOLDER)),)
obj-y                += $(CAM_CAL_MODEL_FOLDER)
subdir-ccflags-y     += -I$(CAM_CAL_SRC_PATH)/$(MTK_PLATFORM)/$(CAM_CAL_MODEL_FOLDER)
else
obj-y                += cam_cal_list.o
obj-y                += eeprom_i2c_dev.o
endif
else
obj-y                += cam_cal_list.o
obj-y                += eeprom_i2c_dev.o
endif

define INC_CUSTOM_SRC
ifeq ($(wildcard $(CAM_CAL_PLATFORM_SRC_PATH)/camera_project/$(ARCH_MTK_PROJECT)/$(1).c),)
obj-y += $(1).o
else
obj-y += camera_project/$(ARCH_MTK_PROJECT)/$(1).o
endif
endef

# Project or platform code
$(foreach src,$(CUSTOM_SRC_LIST),$(eval $(call INC_CUSTOM_SRC,$(src))))