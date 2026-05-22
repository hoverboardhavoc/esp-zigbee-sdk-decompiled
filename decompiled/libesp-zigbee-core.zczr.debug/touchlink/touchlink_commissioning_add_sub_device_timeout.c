/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink.c",0x14c,
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

