/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_master_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_get_master_key(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (void *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = touchlink_device_info_get();
    memcpy(param_1,(void *)(iVar1 + 6),0x10);
    uVar2 = 0;
  }
  return uVar2;
}

