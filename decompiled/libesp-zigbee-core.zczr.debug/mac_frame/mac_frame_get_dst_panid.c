/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_get_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_get_dst_panid(undefined4 *param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined2 *)*param_1;
  iVar2 = mac_fcf_find_dst_panid_index(*puVar1);
  if (iVar2 == 0xff) {
    uVar3 = 0x10;
  }
  else {
    *param_2 = *(undefined2 *)((int)puVar1 + iVar2);
    uVar3 = 0;
  }
  return uVar3;
}

