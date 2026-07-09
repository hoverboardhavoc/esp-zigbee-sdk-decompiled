/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> mac_add_visible_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_add_visible_device(undefined4 *param_1)

{
  int iVar1;
  
  mac_filter_set_mode(1);
  iVar1 = mac_filter_add_address(param_1);
  if (iVar1 != 0) {
    log_write(1,"test_utils.c","Failed to add 0x%016llx to MAC filter allow list",*param_1,
              param_1[1]);
    return;
  }
  return;
}

