/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_pan_coord
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_set_pan_coord(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 2);
    uVar1 = *param_1;
    uVar2 = param_1[1];
    *(char *)(param_1 + 4) = (char)*(undefined3 *)param_1;
    *(char *)((int)param_1 + 0x11) = (char)((uint)uVar1 >> 8);
    *(char *)((int)param_1 + 0x12) = (char)((uint)uVar1 >> 0x10);
    *(char *)((int)param_1 + 0x13) = (char)((uint)uVar1 >> 0x18);
    *(char *)(param_1 + 5) = (char)*(undefined3 *)(param_1 + 1);
    *(char *)((int)param_1 + 0x15) = (char)((uint)uVar2 >> 8);
    *(char *)((int)param_1 + 0x16) = (char)((uint)uVar2 >> 0x10);
    *(char *)((int)param_1 + 0x17) = (char)((uint)uVar2 >> 0x18);
    return;
  }
  *(undefined2 *)((int)param_1 + 0xe) = 0xffff;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  return;
}

