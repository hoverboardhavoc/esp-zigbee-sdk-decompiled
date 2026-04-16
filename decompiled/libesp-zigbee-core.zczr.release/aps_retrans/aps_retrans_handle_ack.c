/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_handle_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_handle_ack(aps_header_t *aps_hdr,zmsg_t *msg)

{
  uint8_t uVar1;
  byte bVar2;
  ezb_shortaddr_t eVar3;
  aps_retrans_ent_t *retrans;
  _Bool _Var4;
  int iVar5;
  undefined3 extraout_var;
  zmsg_t *extraout_a1;
  uint uVar6;
  int iVar7;
  byte bVar8;
  
  if ((aps_hdr->fcf & 3) != 2) {
    aps_hdr = (aps_header_t *)__assert_func(0,0,0,0);
    msg = extraout_a1;
  }
  iVar5 = core_globals_get();
  eVar3 = (aps_hdr->addr_info).src_addr;
  uVar1 = aps_hdr->aps_cntr;
  uVar6 = 0;
  do {
    uVar6 = bitmap_find_next_bit(iVar5 + 0x454,0x20,uVar6);
    uVar6 = uVar6 & 0xff;
    if (0x1f < uVar6) {
_L0:
      zmsg_free(msg);
      return;
    }
    iVar7 = iVar5 + uVar6 * 0x20;
    if ((*(uint8_t *)(iVar7 + 0x5a) == uVar1) && (*(ezb_shortaddr_t *)(iVar7 + 0x58) == eVar3)) {
      retrans = (aps_retrans_ent_t *)(iVar5 + uVar6 * 0x20 + 0x54);
      bVar2 = (retrans->w).slot_done;
      bVar8 = ~bVar2;
      if (((char)aps_hdr->fcf < '\0') && ((byte)(((aps_hdr->ext_hdr).ext_fcf & 3) - 1) < 2)) {
        if ((retrans->w).blk_start == (aps_hdr->ext_hdr).block_nr) {
          bVar8 = bVar8 & (aps_hdr->ext_hdr).ack_bits;
        }
      }
      else {
        uVar6._0_1_ = retrans->retry_cntr;
        uVar6._1_1_ = retrans->blk_sz;
        uVar6._2_1_ = (retrans->w).blk_nr;
        uVar6._3_1_ = (retrans->w).blk_start;
        if ((uVar6 & 0xffff0000) == 0x10000) {
          bVar8 = bVar8 & 1;
        }
      }
      if (bVar8 != 0) {
        retrans->retry_cntr = '\x01';
        (retrans->w).slot_done = bVar2 | bVar8;
        if ((retrans->w).slot_i == '\0') {
          milli_timer_stop();
          milli_timer_start(&retrans->tm,0x640);
        }
      }
      if ((retrans->w).slot_done == 0xff) {
        milli_timer_stop(&retrans->tm);
        _Var4 = aps_tx_window_move_next(&retrans->w);
        if (CONCAT31(extraout_var,_Var4) == 0) {
          aps_retrans_send_confirm(retrans,0);
        }
        else {
          retrans->retry_cntr = '\0';
          aps_retrans_send(retrans);
        }
      }
      goto _L0;
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while( true );
}

