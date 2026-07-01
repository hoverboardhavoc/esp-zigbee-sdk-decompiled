/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_reasm_handle_frag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reasm_handle_frag(aps_header_t *aps_hdr,zmsg_t *msg)

{
  uint8_t uVar1;
  byte bVar2;
  undefined1 uVar3;
  ezb_shortaddr_t eVar4;
  dlist_node_s *__s;
  uint uVar5;
  uint uVar6;
  dlist_node_s *pdVar7;
  int iVar8;
  _Bool _Var9;
  short sVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  undefined3 extraout_var;
  undefined4 *puVar14;
  undefined3 extraout_var_00;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  zmsg_t *extraout_a1;
  uint uVar18;
  dlist_node_s *pdVar19;
  byte bVar20;
  aps_trx_window_t *w;
  int iVar21;
  int iVar22;
  byte bStack_32;
  byte abStack_31 [3];
  uint8_t blk_idx;
  uint8_t frag_blk;
  
  w = (aps_trx_window_t *)(uint)aps_hdr->fcf;
  if ((char)aps_hdr->fcf < '\0') goto _L0;
_L0:
  do {
    do {
      aps_hdr = (aps_header_t *)__assert_func(0,0,0,0);
      msg = extraout_a1;
_L0:
      uVar1 = (aps_hdr->ext_hdr).block_nr;
      if (uVar1 == '\0') {
_L0:
        if (msg == (zmsg_t *)0x0) {
          return;
        }
        zmsg_free(msg);
        return;
      }
      if ((((aps_hdr->ext_hdr).ext_fcf & 3) != 2) && (uVar1 == '\x01')) {
        aps_handle_datagram();
        return;
      }
      if (((uint)w & 3) != 0) goto _L0;
      iVar12 = core_globals_get();
      eVar4 = (aps_hdr->addr_info).src_addr;
      uVar1 = aps_hdr->aps_cntr;
      uVar18 = 0;
      while( true ) {
        uVar18 = bitmap_find_next_bit(iVar12 + 0x958,0x20,uVar18);
        uVar18 = uVar18 & 0xff;
        if (0x1f < uVar18) break;
        iVar21 = iVar12 + uVar18 * 0x28;
        if ((*(uint8_t *)(iVar21 + 0x466) == uVar1) &&
           (*(ezb_shortaddr_t *)(iVar21 + 0x464) == eVar4)) {
          __s = (dlist_node_s *)(iVar12 + uVar18 * 0x28 + 0x458);
          goto _L0;
        }
        uVar18 = uVar18 + 1 & 0xff;
      }
      iVar12 = core_globals_get();
      iVar21 = iVar12 + 0x458;
      uVar13 = bitmap_find_first_zero_bit(iVar12 + 0x958,0x20);
      uVar18 = uVar13 & 0xff;
      if (0x1f < uVar18) goto _L0;
      uVar13 = 1 << (uVar13 & 7) & 0xff;
      uVar16 = __atomic_fetch_or_1((uVar18 >> 3) + iVar12 + 0x958,uVar13,5);
      w = (aps_trx_window_t *)0x0;
    } while ((uVar13 & uVar16) != 0);
    iVar8 = uVar18 * 0x28;
    __s = (dlist_node_s *)(iVar21 + iVar8);
    memset(__s,0,0x28);
    iVar17 = core_globals_get();
    iVar22 = iVar8 + 0x10 + iVar21;
    uVar3 = *(undefined1 *)(iVar17 + 2);
    milli_timer_init(iVar22,aps_reasm_ent_handle_timeout,__s);
    iVar12 = iVar12 + iVar8;
    zmsg_queue_init(__s);
    *(undefined1 *)(iVar12 + 0x47c) = uVar3;
    aps_retrans_start_fast_poll();
    uVar1 = *(uint8_t *)(iVar12 + 0x47c);
    *(ezb_shortaddr_t *)(iVar12 + 0x464) = (aps_hdr->addr_info).src_addr;
    *(uint8_t *)(iVar12 + 0x466) = aps_hdr->aps_cntr;
  } while (7 < (byte)(uVar1 - 1));
  *(undefined1 *)((int)&__s[4].next + 1) = 0xff;
  *(undefined1 *)((int)&__s[4].next + 2) = 0;
  aps_tx_window_reset_slots((aps_trx_window_t *)(iVar21 + iVar8 + 0x21),uVar1);
  milli_timer_start(iVar22,0x640);
_L0:
  uVar18 = 0;
  if (((aps_hdr->ext_hdr).ext_fcf & 3) != 1) {
    uVar18 = (uint)(aps_hdr->ext_hdr).block_nr;
  }
  uVar13 = (uint)*(byte *)((int)&__s[4].next + 2);
  bStack_32 = (byte)uVar18;
  if (uVar18 < uVar13) goto _L0;
  uVar16 = (uint)*(byte *)&__s[4].prev;
  if (uVar13 + uVar16 <= uVar18) {
    if ((*(char *)((int)&__s[4].prev + 1) != -1) ||
       (_Var9 = aps_tx_window_move_next((aps_trx_window_t *)((int)&__s[4].next + 1)),
       CONCAT31(extraout_var,_Var9) == 0)) goto _L0;
    *(undefined1 *)&__s[4].next = 0;
    milli_timer_start(__s + 2,0x640);
    uVar13 = (uint)*(byte *)((int)&__s[4].next + 2);
    uVar16 = (uint)*(byte *)&__s[4].prev;
    uVar18 = (uint)bStack_32;
    if (uVar18 < uVar13 + uVar16) goto _L0;
  }
  uVar5 = uVar18 - uVar13;
  uVar6 = uVar5 & 0x1f;
  if (((uVar5 & 0xff) == uVar16 - 1) ||
     (uVar18 = (1 << ((uVar16 + uVar13) - uVar18 & 0x1f)) + -1 << (uVar5 & 0x1f),
     uVar18 == (*(byte *)((int)&__s[4].prev + 1) & uVar18))) {
    aps_send_ack(aps_hdr,msg,(uint)*(byte *)((int)&__s[4].prev + 1) | 1 << uVar6 & 0xffU);
  }
  bVar20 = *(byte *)((int)&__s[4].prev + 1);
  if (((int)(uint)bVar20 >> uVar6 & 1U) != 0) {
_L0:
    if (msg == (zmsg_t *)0x0) {
      return;
    }
    zmsg_free(msg);
    return;
  }
  bVar20 = bVar20 | (byte)(1 << uVar6);
  *(byte *)((int)&__s[4].prev + 1) = bVar20;
  w = (aps_trx_window_t *)((int)&__s[4].next + 1);
  if (bStack_32 == 0) {
    if (*(char *)((int)&__s[4].next + 2) != '\0') goto _L0;
    uVar1 = *(uint8_t *)&__s[4].prev;
    *(uint8_t *)((int)&__s[4].next + 1) = (aps_hdr->ext_hdr).block_nr;
    aps_tx_window_reset_slots(w,uVar1);
    bVar2 = *(byte *)((int)&__s[4].prev + 1);
    *(undefined1 *)((int)&__s[4].next + 3) = 1;
    *(byte *)((int)&__s[4].prev + 1) = bVar20 | bVar2;
  }
  for (pdVar7 = __s->next; __s != pdVar7; pdVar7 = pdVar7->next) {
    abStack_31[0] = 0;
    zmsg_get_footer(pdVar7,abStack_31,1);
    if (bStack_32 < abStack_31[0]) break;
  }
  zmsg_add_footer(msg,&bStack_32,1);
  pdVar19 = pdVar7->prev;
  pdVar7->prev = &msg->node;
  (msg->node).next = pdVar7;
  (msg->node).prev = pdVar19;
  pdVar19->next = &msg->node;
  *(short *)&__s[1].next = *(short *)&__s[1].next + 1;
  puVar14 = (undefined4 *)zmsg_queue_get_head(__s);
  while (pdVar7 = (dlist_node_s *)*puVar14, __s != pdVar7) {
    abStack_31[0] = 0;
    bVar20 = *(char *)((int)&__s[4].next + 2) + *(char *)((int)&__s[4].next + 3);
    zmsg_get_footer(pdVar7,abStack_31,1);
    if (bVar20 != abStack_31[0]) {
      if (abStack_31[0] <= bVar20) goto _L0;
      break;
    }
    *(char *)((int)&__s[4].next + 3) = *(char *)((int)&__s[4].next + 3) + '\x01';
    zmsg_queue_dequeue(__s,pdVar7);
    uVar15 = zmsg_get_offset(pdVar7);
    sVar10 = zmsg_get_length(pdVar7);
    sVar11 = zmsg_get_offset(pdVar7);
    iVar12 = zmsg_append_bytes_from_msg(puVar14,pdVar7,uVar15,sVar10 - sVar11);
    if (iVar12 != 0) {
      log_write(1,"aps_retrans.c","Failed to merge frag queue: %d",iVar12);
    }
    zmsg_free(pdVar7);
  }
  if (*(char *)((int)&__s[4].prev + 1) != -1) {
    return;
  }
  _Var9 = aps_tx_window_move_next(w);
  if (CONCAT31(extraout_var_00,_Var9) != 0) {
    return;
  }
  if (*(short *)&__s[1].next == 1) {
    uVar15 = zmsg_queue_get_head(__s);
    zmsg_queue_dequeue(__s,uVar15);
    *(undefined1 *)&__s[4].next = 3;
    milli_timer_start(__s + 2,0x640);
    aps_handle_data(aps_hdr,uVar15);
    return;
  }
  goto _L0;
}

