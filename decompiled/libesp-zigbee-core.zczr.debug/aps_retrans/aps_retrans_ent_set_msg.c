/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_ent_set_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_ent_set_msg(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = param_2;
  uVar1 = aps_frame_get_aps_cntr(param_2);
  *(undefined1 *)((int)param_1 + 6) = uVar1;
  zmsg_get_footer(*param_1,param_1 + 1,2);
  zmsg_remove_footer(*param_1,2);
  zmsg_get_footer(*param_1,(int)param_1 + 0x19,1);
  zmsg_remove_footer(*param_1,1);
  iVar2 = zmsg_get_length(*param_1);
  iVar3 = zmsg_get_offset(*param_1);
  aps_tx_window_init((int)param_1 + 0x1a,
                     (int)((iVar2 - iVar3) + (uint)*(byte *)((int)param_1 + 0x19) + -1) /
                     (int)(uint)*(byte *)((int)param_1 + 0x19) & 0xff,
                     *(undefined1 *)((int)param_1 + 0x1d));
  return;
}

