/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void aps_retrans_send(aps_retrans_ent_t *retrans)

{
  uint8_t uVar1;
  uint uVar2;
  _Bool _Var3;
  byte bVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  zmsg_t *pzVar10;
  bitmap_t *pbVar11;
  uint uVar12;
  int iStack_3c;
  aps_apsde_data_req_t req;
  
  if (retrans != (aps_retrans_ent_t *)0x0) goto _L0;
  while( true ) {
    retrans = (aps_retrans_ent_t *)__assert_func(0,0,0,0);
_L0:
    iVar7 = 0x3a7;
    if (3 < retrans->retry_cntr) goto _L0;
    iVar5 = zmsg_alloc(0x2f);
    if (iVar5 == 0) break;
    pbVar11 = &(retrans->w).slot_done;
    bVar4 = bitmap_find_next_zero_bit(pbVar11,(retrans->w).slot_nr,(retrans->w).slot_i);
    (retrans->w).slot_i = bVar4;
    if ((retrans->w).slot_nr <= bVar4) goto _L0;
    uVar2 = (uint)(byte)(bVar4 + (retrans->w).blk_start);
    iVar7 = aps_frame_find_payload_offset(retrans->tx_msg);
    bVar4 = retrans->blk_sz;
    uVar9 = bVar4 * uVar2 + iVar7 & 0xffff;
    iVar6 = zmsg_get_length(retrans->tx_msg);
    if ((int)(uint)bVar4 < (int)(iVar6 - uVar9)) {
      uVar12 = (uint)retrans->blk_sz;
    }
    else {
      iVar6 = zmsg_get_length(retrans->tx_msg);
      uVar12 = iVar6 - uVar9 & 0xffff;
    }
    iVar7 = zmsg_append_bytes_from_msg(iVar5,retrans->tx_msg,0,iVar7);
    if ((iVar7 == 0) &&
       (iVar7 = zmsg_append_bytes_from_msg(iVar5,retrans->tx_msg,uVar9,uVar12), iVar7 == 0)) {
      if (1 < (retrans->w).blk_nr) {
        aps_frame_write_ext_hdr(iVar5,uVar2);
      }
      zmsg_get_footer(retrans->tx_msg,&iStack_3c,0x1c);
      iStack_3c = iVar5;
      iVar7 = aps_send_frame(retrans->dst_addr,&iStack_3c);
      if (iVar7 == 0) {
        (retrans->w).slot_i = (retrans->w).slot_i + '\x01';
_L0:
        bVar4 = bitmap_find_next_zero_bit(pbVar11,(retrans->w).slot_nr);
        (retrans->w).slot_i = bVar4;
        uVar8 = 0;
        if ((retrans->w).slot_nr <= bVar4) {
          uVar1 = retrans->retry_cntr;
          (retrans->w).slot_i = '\0';
          uVar8 = 0x640;
          retrans->retry_cntr = uVar1 + '\x01';
        }
        milli_timer_start(&retrans->tm,uVar8);
        return;
      }
      zmsg_free(iVar5);
_L0:
      pzVar10 = retrans->tx_msg;
      retrans->tx_msg = (zmsg_t *)0x0;
      iVar5 = core_globals_get();
      milli_timer_stop(&retrans->tm);
      uVar2 = (int)retrans - (iVar5 + 0x54);
      if (retrans->tx_msg == (zmsg_t *)0x0) goto _L6;
      do {
        __assert_func(0,0,0,0);
_L6:
        uVar2 = (int)uVar2 >> 5;
      } while ((0x1f < (uVar2 & 0xff)) ||
              (_Var3 = test_and_clr_bitmap(uVar2 & 0xff,(bitmap_t *)(iVar5 + 0x454)),
              CONCAT31(extraout_var,_Var3) == 0));
      nwk_pim_stop_fast_poll();
      aps_send_confirm(pzVar10,iVar7);
      iVar7 = core_globals_get();
      tasklet_post(iVar7 + 0x38);
      return;
    }
  }
  iVar7 = 1;
  goto _L0;
}

