/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_get_src_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_get_src_panid(undefined4 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined2 *)*param_1;
  uVar1 = *puVar2;
  iVar3 = mac_fcf_has_src_panid(uVar1);
  if (iVar3 == 0) {
    uVar4 = 0x10;
  }
  else {
    iVar3 = mac_fcf_skip_dstaddr_index(uVar1);
    uVar4 = 0;
    *param_2 = *(undefined2 *)((int)puVar2 + iVar3);
  }
  return uVar4;
}

