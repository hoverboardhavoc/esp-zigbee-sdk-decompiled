/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_ent_set_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_ent_set_msg(aps_retrans_ent_t *ent,zmsg_t *msg)

{
  uint8_t uVar1;
  int iVar2;
  int iVar3;
  
  ent->tx_msg = msg;
  uVar1 = aps_frame_get_aps_cntr(msg);
  ent->aps_cntr = uVar1;
  zmsg_get_footer(ent->tx_msg,&ent->dst_addr,2);
  zmsg_remove_footer(ent->tx_msg,2);
  zmsg_get_footer(ent->tx_msg,&ent->blk_sz,1);
  zmsg_remove_footer(ent->tx_msg,1);
  iVar2 = zmsg_get_length(ent->tx_msg);
  iVar3 = zmsg_get_offset(ent->tx_msg);
  aps_tx_window_init(&ent->w,(uint8_t)((int)((iVar2 - iVar3) + (uint)ent->blk_sz + -1) /
                                      (int)(uint)ent->blk_sz),(ent->w).slot_nr);
  return;
}

