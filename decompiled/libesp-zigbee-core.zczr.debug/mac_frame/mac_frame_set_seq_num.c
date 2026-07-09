/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_seq_num
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * mac_frame_set_seq_num(undefined4 *param_1,undefined1 param_2)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 *extraout_a1;
  
  if ((*(ushort *)*param_1 >> 8 & 1) == 0) {
    *(undefined1 *)((ushort *)*param_1 + 1) = param_2;
    return param_1;
  }
  puVar2 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x138,
                         "mac_frame_set_seq_num","mac_fcf_has_seq_num(fcf)");
  puVar1 = (undefined2 *)*puVar2;
  iVar3 = mac_fcf_find_dst_panid_index(*puVar1);
  if (iVar3 == 0xff) {
    puVar2 = (undefined4 *)0x10;
  }
  else {
    *extraout_a1 = *(undefined2 *)((int)puVar1 + iVar3);
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

