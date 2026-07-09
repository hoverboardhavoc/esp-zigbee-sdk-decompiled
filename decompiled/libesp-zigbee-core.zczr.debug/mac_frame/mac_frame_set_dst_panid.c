/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_frame_set_dst_panid(undefined4 *param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *extraout_a1;
  
  puVar1 = (undefined2 *)*param_1;
  iVar2 = mac_fcf_find_dst_panid_index(*puVar1);
  if (iVar2 != 0xff) {
    *(undefined2 *)((int)puVar1 + iVar2) = param_2;
    return iVar2;
  }
  puVar3 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x153,
                         "mac_frame_set_dst_panid","index != 0xff");
  puVar1 = (undefined2 *)*puVar3;
  iVar2 = mac_fcf_find_src_panid_index(*puVar1);
  if (iVar2 == 0xff) {
    iVar2 = 0x10;
  }
  else {
    *extraout_a1 = *(undefined2 *)((int)puVar1 + iVar2);
    iVar2 = 0;
  }
  return iVar2;
}

