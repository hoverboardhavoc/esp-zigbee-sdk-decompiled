/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_get_next_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_commissioning_get_next_device_info(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 5;
  while (param_1 = (undefined4 *)touchlink_get_next_disc_device(param_1),
        param_1 != (undefined4 *)0x0) {
    if (1 < *(byte *)((int)param_1 + 0x26)) {
      touchlink_set_intrp_channel(*(undefined1 *)((int)param_1 + 0x21));
      touchlink_set_transaction_id(*param_1);
      uVar1 = touchlink_send_device_info_req(0,(int)param_1 + 0xf,param_1);
    }
  }
  return uVar1;
}

