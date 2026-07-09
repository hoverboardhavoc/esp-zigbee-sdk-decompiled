/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> log_writev
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void log_writev(undefined4 param_1,char *param_2,__gnuc_va_list param_3)

{
  int iVar1;
  char acStack_a0 [127];
  undefined1 uStack_21;
  
  memset(acStack_a0,0,0x80);
  iVar1 = snprintf(acStack_a0,0x80,"[%s] ");
  vsnprintf(acStack_a0 + iVar1,0x80 - iVar1,param_2,param_3);
  uStack_21 = 0;
  ezb_plat_log(param_1,&_LC3,acStack_a0);
  return;
}

