/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_set_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_frame_set_dst_panid(undefined4 *param_1,undefined2 param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = (ushort *)*param_1;
  uVar1 = *puVar2;
  iVar3 = mac_fcf_has_dst_panid(uVar1);
  if (iVar3 == 0) {
    __assert_func(0,0,0);
  }
  *(undefined2 *)((int)puVar2 + ((uVar1 & 0x100) == 0) + 2) = param_2;
  return;
}

