#!/bin/bash

CURR_PATH="`dirname \"$0\"`" 

if [[ ! -d $NXP_K32W061_SDK_ROOT ]]; then
    echo "NXP_K32W061_SDK_ROOT is not set"
    exit 1
fi

cp $CURR_PATH/board_utility.c "$NXP_K32W061_SDK_ROOT"/boards/k32w061dk6/wireless_examples/openthread/enablement
cp $CURR_PATH/board_utility.h "$NXP_K32W061_SDK_ROOT"/boards/k32w061dk6/wireless_examples/openthread/enablement

echo "K32W061 SDK Master Release 2 was patched!"
exit 0
