/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_stop_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void level_cluster_stop_cmd_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_28;
  undefined2 auStack_22 [5];
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  uVar2 = *(undefined1 *)(param_1 + 0x20);
  auStack_22[0] = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x1ff,
                  "level_cluster_stop_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_28 + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_28 + 3);
    iVar3 = level_check_options_is_exec(uVar1,uVar2,uStack_28 >> 0x10 & 0xff,uStack_28 >> 0x18);
    if (iVar3 == 0) {
      uVar4 = 0;
      goto _L0;
    }
  }
  uVar4 = stop_cvc_handler(uVar1);
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar4);
  return;
}

