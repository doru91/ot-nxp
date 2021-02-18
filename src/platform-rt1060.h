/*
 *  Copyright (c) 2021, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file includes the platform-specific initializers.
 *
 */

#ifndef PLATFORM_RT_H_
#define PLATFORM_RT_H_

#include <openthread-core-config.h>
#include <openthread/config.h>

#include <stdint.h>

#include <openthread/instance.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This structure represents a context for the main loop
 *
 */
typedef struct otSysMainloopContext
{
    /* TODO */
} otSysMainloopContext;

/**
 * This function initializes the alarm service used by OpenThread.
 *
 */
void rt1060AlarmInit(void);

/**
 * This function performs alarm driver processing.
 *
 * @param[in]  aInstance  The OpenThread instance structure.
 *
 */
void rt1060AlarmProcess(otInstance *aInstance);

/**
 * This function updates alarm driver processing.
 *
 * @param[in]  aInstance  The OpenThread instance structure.
 *
 */
void rt1060AlarmUpdate(otSysMainloopContext *aMainloop);

/**
 * This function initializes the radio service used by OpenThread.
 *
 */
void rt1060RadioInit(void);

/**
 * This function initializes the radio service used by OpenThread.
 *
 */
void rt1060RadioDeinit(void);

/**
 * This function performs radio driver processing.
 *
 * @param[in]  aInstance  The OpenThread instance structure.
 *
 */
void rt1060RadioProcess(otInstance *aInstance);

/**
 * This function performs radio driver update.
 *
 * @param[in]  aInstance  The OpenThread instance structure.
 *
 */
void rt1060RadioUpdate(otSysMainloopContext *aMainloop);

/**
 * This function initializes the random number service used by OpenThread.
 *
 */
void rt1060RandomInit(void);

/**
 * This function performs UART driver init.
 *
 */
void rt1060UartInit(void);

/**
 * This function performs UART driver deinit.
 *
 */
void rt1060UartDeinit(void);

/**
 * This function performs UART driver processing.
 *
 */
void rt1060UartProcess(void);

/**
 * This function performs UART driver update.
 *
 */
void rt1060UartUpdate(otSysMainloopContext *aMainloop);

/**
 * This function initializes the API lock.
 *
 */
void rt1060ApiLockInit(void);

/**
 * This function deinitialize the API lock.
 *
 */
void rt1060ApiLockDeinit(void);

#ifdef __cplusplus
} // end of extern "C"
#endif

#endif // PLATFORM_RT_H_
