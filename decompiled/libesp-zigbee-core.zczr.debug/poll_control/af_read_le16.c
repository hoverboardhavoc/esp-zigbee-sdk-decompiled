/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> af_read_le16
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_read_le16(short *param_1,undefined4 param_2)

{
  int iVar1;
  short sVar2;
  
  iVar1 = zmsg_read_bytes(*param_1,2,param_2);
  if (iVar1 == 0) {
    sVar2 = -1;
  }
  else {
    sVar2 = *param_1 + (short)iVar1;
  }
  *param_1 = sVar2;
  return;
}

