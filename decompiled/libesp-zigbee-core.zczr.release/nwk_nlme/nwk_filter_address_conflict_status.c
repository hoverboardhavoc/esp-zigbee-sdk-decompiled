/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_filter_address_conflict_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_filter_address_conflict_status(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  char local_11 [5];
  
  local_11[0] = '\0';
  uVar2 = zmsg_get_offset();
  zmsg_read_bytes(param_1,uVar2,1,local_11);
  uVar2 = 0;
  if (local_11[0] == '\x03') {
    sVar1 = zmsg_get_offset(param_1);
    uVar2 = zmsg_compare_bytes(param_1,sVar1 + 1,param_2,3);
  }
  return uVar2;
}

