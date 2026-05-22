/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: blk */
/* WARNING: Unknown calling convention */

void aps_reasm_ent_input(aps_reasm_ent_t *ent,aps_header_t *aps_hdr,zmsg_t *frag_msg)

{
  aps_reasm_ent_t *paVar1;
  _Bool _Var2;
  short sVar3;
  short sVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar5;
  undefined3 extraout_var_01;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  dlist_node_s *pdVar10;
  byte bVar11;
  aps_trx_window_t *w;
  byte bStack_22;
  byte abStack_21 [3];
  uint8_t blk;
  uint8_t blk_idx;
  
  if (((aps_hdr->ext_hdr).ext_fcf & 3) == 1) {
    uVar8 = 0;
  }
  else {
    uVar8 = (uint)(aps_hdr->ext_hdr).block_nr;
  }
  abStack_21[0] = (byte)uVar8;
  uVar9 = (uint)(ent->w).blk_start;
  if (uVar8 < uVar9) goto _L0;
  if (uVar9 + (ent->w).slot_nr <= uVar8) {
    if (((ent->w).slot_done != 0xff) ||
       (_Var2 = aps_tx_window_move_next(&ent->w), CONCAT31(extraout_var,_Var2) == 0)) goto _L0;
    ent->retry_cntr = '\0';
    milli_timer_start(&ent->tm,0x640);
    if ((uint)abStack_21[0] < (uint)(ent->w).blk_start + (uint)(ent->w).slot_nr) goto _L0;
  }
  uVar9 = (uint)(ent->w).blk_start;
  uVar8 = abStack_21[0] - uVar9;
  w = &ent->w;
  _Var2 = aps_rx_window_should_ack(w,abStack_21[0]);
  if (CONCAT31(extraout_var_00,_Var2) != 0) {
    aps_send_ack(aps_hdr,uVar9,(uint)(ent->w).slot_done | 1 << (uVar8 & 0x1f) & 0xffU);
  }
  bVar11 = (ent->w).slot_done;
  uVar8 = uVar8 & 0x1f;
  if (((int)(uint)bVar11 >> uVar8 & 1U) == 0) {
    (ent->w).slot_done = bVar11 | (byte)(1 << uVar8);
    if (abStack_21[0] == 0) {
      aps_rx_window_set_blk_nr(w,(aps_hdr->ext_hdr).block_nr);
      (ent->w).slot_i = '\x01';
    }
    for (paVar1 = (aps_reasm_ent_t *)(ent->frag_q).list.next; paVar1 != ent;
        paVar1 = (aps_reasm_ent_t *)(paVar1->frag_q).list.next) {
      bStack_22 = 0;
      zmsg_get_footer(paVar1,&bStack_22,1);
      if (abStack_21[0] < bStack_22) break;
    }
    zmsg_add_footer(frag_msg,abStack_21,1);
    pdVar10 = (paVar1->frag_q).list.prev;
    (paVar1->frag_q).list.prev = &frag_msg->node;
    (frag_msg->node).next = (dlist_node_s *)paVar1;
    (frag_msg->node).prev = pdVar10;
    pdVar10->next = &frag_msg->node;
    (ent->frag_q).length = (ent->frag_q).length + 1;
    piVar5 = (int *)zmsg_queue_get_head(ent);
    while (paVar1 = (aps_reasm_ent_t *)*piVar5, ent != paVar1) {
      bStack_22 = 0;
      bVar11 = (ent->w).blk_start + (ent->w).slot_i;
      zmsg_get_footer(paVar1,&bStack_22,1);
      if (bStack_22 == bVar11) {
        (ent->w).slot_i = (ent->w).slot_i + '\x01';
        zmsg_queue_dequeue(ent,paVar1);
        uVar6 = zmsg_get_offset(paVar1);
        sVar3 = zmsg_get_length(paVar1);
        sVar4 = zmsg_get_offset(paVar1);
        iVar7 = zmsg_append_bytes_from_msg(piVar5,paVar1,uVar6,sVar3 - sVar4);
        if (iVar7 != 0) {
          log_write(1,"aps_retrans.c","Failed to merge frag queue: %d",iVar7);
        }
      }
      else {
        if (bVar11 < bStack_22) break;
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x22f,
                      "aps_reasm_ent_input","frag_blk > next_blk");
      }
      zmsg_free(paVar1);
    }
    if ((ent->w).slot_done != 0xff) {
      return;
    }
    _Var2 = aps_tx_window_move_next(w);
    if (CONCAT31(extraout_var_01,_Var2) != 0) {
      return;
    }
    if ((ent->frag_q).length == 1) {
      uVar6 = zmsg_queue_get_head(ent);
      zmsg_queue_dequeue(ent,uVar6);
      ent->retry_cntr = '\x03';
      milli_timer_start(&ent->tm,0x640);
      aps_handle_data(aps_hdr,uVar6);
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x247,
                  "aps_reasm_ent_input","ent->frag_q.length == 1");
    uVar8 = nwk_pim_get_fast_poll_interval();
    nwk_pim_start_fast_poll(0x1900 / uVar8);
    return;
  }
_L0:
  if (frag_msg != (zmsg_t *)0x0) {
    zmsg_free(frag_msg);
  }
  return;
}

