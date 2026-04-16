/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_add_sub_device_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_add_sub_device_timeout(void *arg)

{
  touchlink_commissioning_t *ptVar1;
  int iVar2;
  
  ptVar1 = touchlink_commissioning_get();
  if (ptVar1->task == '\x02') {
    if (arg != (void *)0x0) {
      iVar2 = touchlink_commissioning_get_next_device_info((touchlink_disc_dev_info_t *)arg);
      if (iVar2 == 0) {
        return;
      }
      goto _L0;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/touchlink/touchlink.c",0x14c,
                  "touchlink_commissioning_add_sub_device_timeout",
                  "(*touchlink_commissioning_get()).task == TL_COMM_TASK_ADD_SUB_DEVICE");
  }
  iVar2 = 2;
_L0:
  touchlink_reset_intrp_channel();
  if (iVar2 == 5) {
    touchlink_commissioning_task_result('\0');
  }
  else {
    touchlink_reset_sub_devices();
    touchlink_commissioning_task_result('\x01');
  }
  return;
}

