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
 * This file implements an example OpenThread CLI application.
 *
 * This file is just for example, but not for production.
 *
 */

/* TODO: add required SDK files + CMakes rules */
//#include <freertos/FreeRTOS.h>
//#include <freertos/task.h>

#include <assert.h>
#include <openthread/cli.h>
#include <openthread/tasklet.h>
#include <openthread/platform/toolchain.h>

#include "platform-rt1060.h"

static void run_cli(void *aContext)
{
    OT_UNUSED_VARIABLE(aContext);

pseudo_reset:

    otSysInit(0, NULL);

    otSysApiLock();

    size_t instanceSize = 0;

    // Get the instance size.
    otInstanceInit(NULL, &instanceSize);
    void *instanceBuffer = malloc(instanceSize);

    otInstance *instance = otInstanceInit(instanceBuffer, &instanceSize);

    assert(instance != NULL);

    otCliUartInit(instance);
    otSysApiUnlock();

    while (!otSysPseudoResetWasRequested())
    {
        otSysMainloopContext mainloop;

        otSysMainloopInit(&mainloop);

        otSysApiLock();
        otTaskletsProcess(instance);
        otSysMainloopUpdate(instance, &mainloop);
        otSysApiUnlock();

        if (otSysMainloopPoll(&mainloop) >= 0)
        {
            otSysApiLock();
            otSysMainloopProcess(instance, &mainloop);
            otSysApiUnlock();
        }
        else
        {
            abort();
        }
    }

    otInstanceFinalize(instance);
    otSysDeinit();

    goto pseudo_reset;

    /* TODO */
    // vTaskDelete(NULL);
}

int main(int argc, char *argv[])
{
    /* TODO: add required SDK files + CMakes rules */
    // xTaskCreate(run_cli, "cli", 10 * 1024, NULL, 5, NULL);

    /* add this call just for linking check */
    run_cli(NULL);
}
