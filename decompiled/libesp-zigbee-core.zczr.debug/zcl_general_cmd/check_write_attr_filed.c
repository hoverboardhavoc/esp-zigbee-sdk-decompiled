/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_write_attr_filed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte check_write_attr_filed(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_2 == 0) {
    return 0x86;
  }
  if (*(char *)(param_2 + 2) != *(char *)(param_1 + 2)) {
    return 0x8d;
  }
  bVar1 = *(byte *)(param_2 + 3);
  if (bVar1 == 1) {
    return 0x88;
  }
  if ((bVar1 & 2) != 0) {
    if ((bVar1 & 0x40) == 0) {
      return bVar1 & 0x40;
    }
    return 0x86;
  }
  return 0x88;
}

