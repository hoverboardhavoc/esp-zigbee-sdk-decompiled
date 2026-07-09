/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_parse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_frame_parse(int param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_11 [5];
  
  if (param_1 == 0) {
    iVar1 = 2;
  }
  else if (param_2 == (int *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar1 = mac_frame_parse_header(param_2 + 1,auStack_11);
    if ((iVar1 == 0) &&
       (iVar1 = mac_frame_parse_payload(param_1,auStack_11[0],param_2 + 8), iVar1 == 0)) {
      *param_2 = param_1;
    }
  }
  return iVar1;
}

