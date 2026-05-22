/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_handle_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_handle_ack(aps_header_t *aps_hdr,zmsg_t *msg)

{
  aps_retrans_ent_t *unaff_s0;
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  byte bVar3;
  uint uVar4;
  byte in_a4;
  uint uVar5;
  
  uVar5 = (aps_hdr->fcf & 3) - 2;
  if (uVar5 == 0) {
    iVar2 = core_globals_get();
    unaff_s0 = aps_retrans_find((aps_tx_context_t *)(iVar2 + 0x38),(aps_hdr->addr_info).src_addr,
                                aps_hdr->aps_cntr);
    if (unaff_s0 == (aps_retrans_ent_t *)0x0) goto _L0;
    in_a4 = (unaff_s0->w).slot_done;
    uVar5 = ~(uint)in_a4 & 0xff;
    if ((char)aps_hdr->fcf < '\0') goto _L0;
_L0:
    uVar4._0_1_ = unaff_s0->retry_cntr;
    uVar4._1_1_ = unaff_s0->blk_sz;
    uVar4._2_1_ = (unaff_s0->w).blk_nr;
    uVar4._3_1_ = (unaff_s0->w).blk_start;
    if ((uVar4 & 0xffff0000) == 0x10000) {
      uVar5 = uVar5 & 1;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x10d,
                  "aps_retrans_handle_ack","aps_fcf_get_frame_type(aps_hdr->fcf) == APS_FRAME_ACK");
_L0:
    bVar3 = (aps_hdr->ext_hdr).ext_fcf & 3;
    if ((bVar3 != 1) && (bVar3 != 2)) goto _L0;
    if ((unaff_s0->w).blk_start == (aps_hdr->ext_hdr).block_nr) {
      uVar5 = uVar5 & (aps_hdr->ext_hdr).ack_bits;
    }
  }
  if (uVar5 != 0) {
    (unaff_s0->w).slot_done = in_a4 | (byte)uVar5;
    unaff_s0->retry_cntr = '\x01';
    if ((unaff_s0->w).slot_i == '\0') {
      milli_timer_stop(&unaff_s0->tm);
      milli_timer_start(&unaff_s0->tm,0x640);
    }
  }
  if ((unaff_s0->w).slot_done == 0xff) {
    milli_timer_stop(&unaff_s0->tm);
    _Var1 = aps_tx_window_move_next(&unaff_s0->w);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      aps_retrans_send_confirm(unaff_s0,0);
    }
    else {
      unaff_s0->retry_cntr = '\0';
      aps_retrans_send(unaff_s0);
    }
  }
_L0:
  zmsg_free(msg);
  return;
}

