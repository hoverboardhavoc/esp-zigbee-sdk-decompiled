/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crc.o -> crc32_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint crc32_next(uint param_1,int param_2,char *param_3,uint param_4,char *param_5)

{
  int extraout_a1;
  uint uVar1;
  
  if (param_2 != 0) {
    param_1 = ~param_1;
    for (param_5 = (char *)0x0; param_5 < param_3; param_5 = param_5 + 1) {
      param_1 = param_1 ^ (byte)param_5[param_2];
      for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
        param_4 = param_1 & 1;
        if (param_4 != 0) {
          param_4 = 0xffffffff;
        }
_L0:
        param_1 = param_1 >> 1 ^ param_4 & 0xedb88320;
      }
    }
    return ~param_1;
  }
  uVar1 = 0x10000;
  param_3 = "crc32_next";
  param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/crc.c",0x5b);
  param_2 = extraout_a1;
  goto _L0;
}

