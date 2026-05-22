/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_tmque_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_tmque_timeout(zmsg_t *msg)

{
  nwk_bt_record_t *pnVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  nwk_fwd_s *pnVar6;
  int iVar7;
  uint8_t uStack_13;
  ezb_shortaddr_t local_12;
  uint8_t seq_num;
  ezb_shortaddr_t src_addr;
  
  zmsg_read_u8(msg,7,&uStack_13);
  zmsg_read_le16(msg,4,&local_12);
  pnVar6 = &s_nwk_fwd;
  iVar7 = 0;
  while ((pnVar6->btt[0].src_addr != local_12 || (pnVar6->btt[0].seq_num != uStack_13))) {
    iVar7 = iVar7 + 1;
    pnVar6 = (nwk_fwd_s *)&(pnVar6->send_queue).length;
    if (iVar7 == 0x5a) {
_L0:
      nwk_fwd_do_send_msg(msg);
      return;
    }
  }
  pnVar1 = s_nwk_fwd.btt + iVar7 + -7;
  uVar2._0_2_ = pnVar1->src_addr;
  uVar2._2_1_ = pnVar1->seq_num;
  uVar2._3_1_ = pnVar1->expire_time;
  uVar3 = nwk_neighbor_table_get_capacity();
  uVar4 = bitmap_find_first_bit(uVar2,uVar3);
  uVar5 = nwk_neighbor_table_get_capacity();
  if (uVar5 <= uVar4) {
    nwk_fwd_finish_tx(msg,0);
    return;
  }
  goto _L0;
}

