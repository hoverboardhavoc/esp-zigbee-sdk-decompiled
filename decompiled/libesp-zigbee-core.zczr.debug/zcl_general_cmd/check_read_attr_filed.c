/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_read_attr_filed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte check_read_attr_filed(int param_1)

{
  byte bVar1;
  
  if (param_1 == 0) {
    return 0x86;
  }
  bVar1 = *(byte *)(param_1 + 3);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 0x40) == 0) {
      return bVar1 & 0x40;
    }
    return 0x7e;
  }
  return 0x7e;
}

