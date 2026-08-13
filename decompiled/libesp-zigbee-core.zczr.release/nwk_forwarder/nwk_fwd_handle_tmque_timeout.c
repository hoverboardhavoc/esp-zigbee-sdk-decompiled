/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_tmque_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_tmque_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uStack_13;
  undefined2 auStack_12 [3];
  
  zmsg_read_u8_isra_0(7,&uStack_13);
  zmsg_read_le16_isra_0(param_1,4,auStack_12);
  iVar2 = nwk_btt_find(auStack_12[0],uStack_13);
  if (iVar2 != 0) {
    uVar1 = *(undefined4 *)(iVar2 + 4);
    uVar3 = nwk_neighbor_table_get_capacity();
    uVar4 = bitmap_find_first_bit(uVar1,uVar3);
    uVar5 = nwk_neighbor_table_get_capacity();
    if (uVar5 <= uVar4) {
      nwk_fwd_finish_tx(param_1,0);
      return;
    }
  }
  nwk_fwd_do_send_msg(param_1);
  return;
}

