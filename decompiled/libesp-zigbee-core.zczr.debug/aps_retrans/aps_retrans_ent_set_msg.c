/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_ent_set_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_ent_set_msg(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  
  *param_1 = param_2;
  uVar1 = aps_frame_get_aps_cntr(param_2);
  *(undefined1 *)((int)param_1 + 6) = uVar1;
  zmsg_get_footer(*param_1,param_1 + 1,2);
  zmsg_remove_footer(*param_1,2);
  zmsg_get_footer(*param_1,(int)param_1 + 0x19,1);
  zmsg_remove_footer(*param_1,1);
  sVar2 = zmsg_get_length(*param_1);
  sVar3 = zmsg_get_offset(*param_1);
  if ((ushort)(sVar2 - sVar3) == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = (int)((uint)(ushort)(sVar2 - sVar3) + (uint)*(byte *)((int)param_1 + 0x19) + -1) /
            (int)(uint)*(byte *)((int)param_1 + 0x19) & 0xff;
  }
  aps_tx_window_init((int)param_1 + 0x1a,uVar4,*(undefined1 *)((int)param_1 + 0x1d));
  return;
}

