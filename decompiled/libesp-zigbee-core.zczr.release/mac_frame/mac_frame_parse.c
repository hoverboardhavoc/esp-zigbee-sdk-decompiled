/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_parse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_frame_parse(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  byte abStack_11 [5];
  
  if (param_1 != (int *)0x0) {
    iVar2 = 2;
    if ((param_2 != (int *)0x0) &&
       (iVar2 = mac_frame_parse_header(param_2 + 1,abStack_11), iVar2 == 0)) {
      if ((abStack_11[0] - 3 & 0xff) < 0x7c) {
        param_2[9] = *param_1 + (uint)abStack_11[0];
        iVar1 = param_1[1];
        *param_2 = (int)param_1;
        *(byte *)(param_2 + 8) = (-2 - abStack_11[0]) + (char)iVar1;
      }
      else {
        iVar2 = 0x10;
      }
    }
    return iVar2;
  }
  return 2;
}

