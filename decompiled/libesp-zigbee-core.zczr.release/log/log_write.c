/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> log.o -> log_write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void log_write(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char acStack_c0 [127];
  undefined1 uStack_41;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = param_3;
  uStack_10 = param_4;
  uStack_c = param_5;
  uStack_8 = param_6;
  uStack_4 = param_7;
  memset(acStack_c0,0,0x80);
  iVar1 = snprintf(acStack_c0,0x80,"[%s] ");
  vsnprintf(acStack_c0 + iVar1,0x80 - iVar1,param_2,&uStack_14);
  uStack_41 = 0;
  ezb_plat_log(param_1,&_LC1,acStack_c0);
  return;
}

