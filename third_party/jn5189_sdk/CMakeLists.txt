#
#  Copyright (c) 2021, The OpenThread Authors.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. Neither the name of the copyright holder nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#

if (SDK_RELEASE)
    SET_SOURCE_FILES_PROPERTIES($ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/mcuxpresso/startup_jn5189.c PROPERTIES LANGUAGE CXX)
    
    add_library(nxp-jn5189-driver
        $ENV{NXP_JN5189_SDK_ROOT}/boards/jn5189dk6/wireless_examples/openthread/enablement/board.c
        $ENV{NXP_JN5189_SDK_ROOT}/boards/jn5189dk6/wireless_examples/openthread/enablement/board_utility.c
        $ENV{NXP_JN5189_SDK_ROOT}/boards/jn5189dk6/wireless_examples/openthread/enablement/clock_config.c
        $ENV{NXP_JN5189_SDK_ROOT}/boards/jn5189dk6/wireless_examples/openthread/enablement/pin_mux.c
        $ENV{NXP_JN5189_SDK_ROOT}/components/serial_manager/serial_manager.c
        $ENV{NXP_JN5189_SDK_ROOT}/components/serial_manager/serial_port_uart.c
        $ENV{NXP_JN5189_SDK_ROOT}/components/uart/usart_adapter.c 
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/mcuxpresso/startup_jn5189.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/system_JN5189.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_aes.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_clock.c 
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_common.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_ctimer.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_flash.c   
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_flexcomm.c 
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_gpio.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_power.c      
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_reset.c 
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_rng.c
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_sha.c    
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_usart.c  
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers/fsl_wtimer.c 
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/utilities/debug_console/fsl_debug_console.c 
        $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/utilities/str/fsl_str.c              
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Common/MicroInt_arm_sdk2.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Flash/Internal/Flash_Adapter.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/FunctionLib/FunctionLib.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Lists/GenericList.c 
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/MemManager/Source/MemManager.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Panic/Source/Panic.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/PDM/pdm_port.c  
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Reset/Reset.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/SerialManager/Source/SerialManager.c
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/SerialManager/Source/UART_Serial_Adapter.c      
        $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/TimersManager/Source/TMR_Adapter.c
    )
    else()
    SET_SOURCE_FILES_PROPERTIES( $ENV{NXP_JN5189_SDK_ROOT}/path_from_repo/TODO.c PROPERTIES LANGUAGE CXX)
    
    add_library(nxp-jn5189-driver
        $ENV{NXP_JN5189_SDK_ROOT}/path_from_repo/TODO.c
    )
endif()

target_compile_definitions(nxp-jn5189-driver
    PUBLIC
        ${OT_PLATFORM_DEFINES}
        -DCPU_K32W061HN
        -DCPU_JN518X
        -DCPU_JN518X_REV=2
        -DJENNIC_CHIP_FAMILY_JN518x
        -DJENNIC_CHIP_FAMILY_NAME=_JN518x
        -DgPWR_LDOMEM_0_9V_PD=0
        -DNO_SYSCORECLK_UPD=0
        -DENABLE_RAM_VECTOR_TABLE=1
)

target_compile_options(nxp-jn5189-driver
    PRIVATE
        ${OT_CFLAGS}
        -Wno-unknown-pragmas
        -Wno-sign-compare
        -Wno-unused-function
        -Wno-unused-parameter
        -Wno-empty-body                                                                                                   
        -Wno-missing-field-initializers                                                                                    
        -Wno-clobbered                                                                                                     
        -fno-strict-aliasing
        -imacros "${PROJECT_SOURCE_DIR}/src/k32w/jn5189/jn5189-sdk-config.h"
)

if (SDK_RELEASE)
    target_include_directories(nxp-jn5189-driver
        PUBLIC
            $ENV{NXP_JN5189_SDK_ROOT}/boards/jn5189dk6/wireless_examples/openthread/enablement
            $ENV{NXP_JN5189_SDK_ROOT}/components/serial_manager  
            $ENV{NXP_JN5189_SDK_ROOT}/CMSIS/Include  
            $ENV{NXP_JN5189_SDK_ROOT}/components/uart
            $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189
            $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/drivers 
            $ENV{NXP_JN5189_SDK_ROOT}/devices/JN5189/utilities/str 
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/mbedtls/port/ksdk       
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/ieee-802.15.4/uMac/Include
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Common/
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/FunctionLib/
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Flash/Internal
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Lists
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/MemManager/Interface
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/OSAbstraction/Interface     
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/Panic/Interface/ 
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/PDM/Include 
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/SerialManager/Interface   
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/SerialManager/Source
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/TimersManager/Interface
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/TimersManager/Source         
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/XCVR/DK6/Build/Include    
            $ENV{NXP_JN5189_SDK_ROOT}/middleware/wireless/framework/XCVR/DK6
    )
    else()
    target_include_directories(nxp-jn5189-driver
        PUBLIC
            $ENV{NXP_JN5189_SDK_ROOT}/path_from_repo/TODO.c
    )
endif()

target_link_libraries(nxp-jn5189-driver PRIVATE ot-config)
