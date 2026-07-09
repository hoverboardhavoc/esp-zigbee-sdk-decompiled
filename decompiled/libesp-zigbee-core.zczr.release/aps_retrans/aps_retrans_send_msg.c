/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_send_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_retrans_send_msg(undefined2 param_1,undefined1 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_23;
  undefined2 auStack_22 [7];
  
  uStack_23 = param_2;
  auStack_22[0] = param_1;
  iVar1 = core_globals_get();
  uVar3 = *param_3;
  iVar2 = zmsg_add_footer(uVar3,&uStack_23,1);
  if ((iVar2 == 0) && (iVar2 = zmsg_add_footer(uVar3,auStack_22,2), iVar2 == 0)) {
    zmsg_queue_enqueue(iVar1 + 0x48,uVar3);
    tasklet_post(iVar1 + 0x38);
  }
  return iVar2;
}

