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
list(APPEND OT_PLATFORM_DEFINES
    "OPENTHREAD_CORE_CONFIG_PLATFORM_CHECK_FILE=\"openthread-core-jn5189-config-check.h\""
)
    
list(APPEND OT_PUBLIC_DEFINES
    -imacros "${PROJECT_SOURCE_DIR}/src/k32w/jn5189/jn5189-sdk-config.h"
    -I${PROJECT_SOURCE_DIR}/src/k32w/jn5189/
)

set(OT_PLATFORM_DEFINES ${OT_PLATFORM_DEFINES} PARENT_SCOPE)

target_compile_definitions(ot-config INTERFACE
    "MBEDTLS_USER_CONFIG_FILE=\"jn5189-mbedtls-config.h\""
    "MBEDTLS_CONFIG_FILE=\"mbedtls-config.h\"" 
)

set(OT_PUBLIC_INCLUDES ${OT_PUBLIC_INCLUDES} PARENT_SCOPE)

set(COMM_FLAGS
    -I${PROJECT_SOURCE_DIR}/examples/platforms/k32w/jn5189/
    -Wno-unused-parameter
    -Wno-expansion-to-defined
)
if(OT_CFLAGS MATCHES "-pedantic-errors")
    string(REPLACE "-pedantic-errors" "" OT_CFLAGS "${OT_CFLAGS}")
endif()

if(OT_CFLAGS MATCHES "-Wcast-align")
    string(REPLACE "-Wcast-align" "" OT_CFLAGS "${OT_CFLAGS}")
endif()

add_library(openthread-jn5189
    ${K32W_COMM_SOURCES}
    $<TARGET_OBJECTS:openthread-platform-utils>
)

set_target_properties(openthread-jn5189
    PROPERTIES
        C_STANDARD 99
        CXX_STANDARD 11
)

target_link_libraries(openthread-jn5189
    PUBLIC
        ${OT_MBEDTLS}                         
        ${K32W_LIBS}
        -T${PROJECT_SOURCE_DIR}/src/k32w/jn5189/jn5189.ld
        -Wl,--gc-sections
        -Wl,-Map=$<TARGET_PROPERTY:NAME>.map
    PRIVATE
        nxp-jn5189-driver
        ot-config
)

target_compile_definitions(openthread-jn5189
    PUBLIC
        ${OT_PLATFORM_DEFINES}
)

target_compile_options(openthread-jn5189
    PUBLIC
        ${OT_CFLAGS}
        ${COMM_FLAGS}
)

target_include_directories(openthread-jn5189
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/jn5189
        ${K32W_INCLUDES}
        ${OT_PUBLIC_INCLUDES}
)

target_include_directories(ot-config INTERFACE ${OT_PUBLIC_INCLUDES})
target_compile_definitions(ot-config INTERFACE ${OT_PLATFORM_DEFINES})
