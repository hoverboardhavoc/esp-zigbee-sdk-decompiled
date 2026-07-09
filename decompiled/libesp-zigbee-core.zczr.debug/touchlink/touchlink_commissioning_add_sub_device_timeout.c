/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_add_sub_device_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_add_sub_device_timeout(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)touchlink_commissioning_get();
  if (*pcVar1 == '\x02') {
    if (param_1 != 0) {
      iVar2 = touchlink_commissioning_get_next_device_info(param_1);
      if (iVar2 == 0) {
        return;
      }
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink.c",0x14c,
                  "touchlink_commissioning_add_sub_device_timeout",
                  "(*touchlink_commissioning_get()).task == TL_COMM_TASK_ADD_SUB_DEVICE");
  }
  iVar2 = 2;
_L0:
  touchlink_reset_intrp_channel();
  if (iVar2 == 5) {
    touchlink_commissioning_task_result(0);
  }
  else {
    touchlink_reset_sub_devices();
    touchlink_commissioning_task_result(1);
  }
  return;
}

