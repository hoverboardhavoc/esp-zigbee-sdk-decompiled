/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crc.o -> crc16_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crc16_next(uint param_1,int param_2,char *param_3,uint param_4)

{
  int extraout_a1;
  char *pcVar1;
  
  if (param_2 != 0) {
    for (pcVar1 = (char *)0x0; pcVar1 < param_3; pcVar1 = pcVar1 + 1) {
      param_1 = param_1 ^ (byte)pcVar1[param_2];
      for (param_4 = 0; param_4 < 8; param_4 = param_4 + 1) {
        if ((param_1 & 1) == 0) {
_L0:
          param_1 = param_1 >> 1;
        }
        else {
          param_1 = (param_1 >> 1 ^ 0xffff8408) & 0xffff;
        }
      }
    }
    return;
  }
  pcVar1 = "p != ((void *)0)";
  param_3 = "crc16_next";
  param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/crc.c",0x3b);
  param_2 = extraout_a1;
  goto _L0;
}

