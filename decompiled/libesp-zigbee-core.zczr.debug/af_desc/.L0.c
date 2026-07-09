/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> .L0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 _L0(ushort *param_1,uint param_2,byte param_3)

{
  while( true ) {
    if (param_1 == (ushort *)0x0) {
      return 1;
    }
    if ((*param_1 == param_2) && (((byte)param_1[1] & param_3) != 0)) break;
    param_1 = *(ushort **)(param_1 + 8);
  }
  return 0;
}

