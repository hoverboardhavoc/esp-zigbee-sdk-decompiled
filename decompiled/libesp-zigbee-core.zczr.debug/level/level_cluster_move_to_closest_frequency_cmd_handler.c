/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_move_to_closest_frequency_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void level_cluster_move_to_closest_frequency_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined2 uStack_14;
  ushort auStack_12 [3];
  
  auStack_12[0] = 0;
  uStack_14 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x213,
                  "level_cluster_move_to_closest_frequency_cmd_handler","packet && rsp");
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_12,&uStack_14);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (auStack_12[0] <= uVar1) {
      uVar2 = 0x81;
      goto _L0;
    }
  }
  uVar2 = 0x80;
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

