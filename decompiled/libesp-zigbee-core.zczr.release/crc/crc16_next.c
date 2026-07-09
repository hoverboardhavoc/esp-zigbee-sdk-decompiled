/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> crc.o -> crc16_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint crc16_next(uint param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  
  if (param_2 == 0) {
    param_3 = 0;
    param_1 = __assert_func(0);
    do {
      iVar1 = 8;
      param_1 = param_1 ^ *(byte *)(param_2 + param_4);
      do {
        iVar1 = iVar1 + -1;
        param_1 = (-(param_1 & 1) & param_5 ^ param_1 >> 1) & 0xffff;
      } while (iVar1 != 0);
      param_4 = param_4 + 1;
_L0:
    } while (param_4 != param_3);
    return param_1;
  }
  param_4 = 0;
  param_5 = 0xffff8408;
  goto _L0;
}

