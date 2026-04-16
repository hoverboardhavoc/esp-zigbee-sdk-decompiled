/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  byte bVar3;
  undefined1 uVar4;
  ezb_shortaddr_t eVar5;
  dlist_node_s *__s;
  uint uVar6;
  uint uVar7;
  dlist_node_s *pdVar8;
  int iVar9;
  _Bool _Var10;
  ushort uVar11;
  short sVar12;
  int iVar13;
  uint uVar14;
  undefined3 extraout_var;
  undefined4 *puVar15;
  undefined3 extraout_var_00;
  undefined4 uVar16;
  uint uVar17;
  int iVar18;
  zmsg_t *extraout_a1;
  uint uVar19;
  dlist_node_s *pdVar20;
  ushort uVar21;
  aps_trx_window_t *w;
  int iVar22;
  int iVar23;
  byte bStack_32;
  byte abStack_31 [3];
  uint8_t blk_idx;
  uint8_t frag_blk;
  
  uVar21 = (ushort)aps_hdr->fcf;
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
      if ((uVar21 & 3) != 0) goto _L0;
      iVar13 = core_globals_get();
      eVar5 = (aps_hdr->addr_info).src_addr;
      uVar1 = aps_hdr->aps_cntr;
      uVar19 = 0;
      while( true ) {
        uVar19 = bitmap_find_next_bit(iVar13 + 0x958,0x20,uVar19);
        uVar19 = uVar19 & 0xff;
        if (0x1f < uVar19) break;
        iVar22 = iVar13 + uVar19 * 0x28;
        if ((*(uint8_t *)(iVar22 + 0x466) == uVar1) &&
           (*(ezb_shortaddr_t *)(iVar22 + 0x464) == eVar5)) {
          __s = (dlist_node_s *)(iVar13 + uVar19 * 0x28 + 0x458);
          goto _L0;
        }
        uVar19 = uVar19 + 1 & 0xff;
      }
      iVar13 = core_globals_get();
      iVar22 = iVar13 + 0x458;
      uVar14 = bitmap_find_first_zero_bit(iVar13 + 0x958,0x20);
      uVar19 = uVar14 & 0xff;
      if (0x1f < uVar19) goto _L0;
      uVar14 = 1 << (uVar14 & 7) & 0xff;
      uVar17 = __atomic_fetch_or_1((uVar19 >> 3) + iVar13 + 0x958,uVar14,5);
      uVar21 = 0;
    } while ((uVar14 & uVar17) != 0);
    iVar9 = uVar19 * 0x28;
    __s = (dlist_node_s *)(iVar22 + iVar9);
    memset(__s,0,0x28);
    iVar18 = core_globals_get();
    iVar23 = iVar9 + 0x10 + iVar22;
    uVar4 = *(undefined1 *)(iVar18 + 2);
    milli_timer_init(iVar23,aps_reasm_ent_handle_timeout,__s);
    iVar13 = iVar13 + iVar9;
    zmsg_queue_init(__s);
    *(undefined1 *)(iVar13 + 0x47c) = uVar4;
    aps_retrans_start_fast_poll();
    uVar1 = *(uint8_t *)(iVar13 + 0x47c);
    *(ezb_shortaddr_t *)(iVar13 + 0x464) = (aps_hdr->addr_info).src_addr;
    *(uint8_t *)(iVar13 + 0x466) = aps_hdr->aps_cntr;
  } while (7 < (byte)(uVar1 - 1));
  *(undefined1 *)((int)&__s[4].next + 1) = 0xff;
  *(undefined1 *)((int)&__s[4].next + 2) = 0;
  aps_tx_window_reset_slots((aps_trx_window_t *)(iVar22 + iVar9 + 0x21),uVar1);
  milli_timer_start(iVar23,0x640);
_L0:
  uVar19 = 0;
  if (((aps_hdr->ext_hdr).ext_fcf & 3) != 1) {
    uVar19 = (uint)(aps_hdr->ext_hdr).block_nr;
  }
  uVar14 = (uint)*(byte *)((int)&__s[4].next + 2);
  bStack_32 = (byte)uVar19;
  if (uVar19 < uVar14) goto _L0;
  uVar17 = (uint)*(byte *)&__s[4].prev;
  if (uVar14 + uVar17 <= uVar19) {
    if ((*(char *)((int)&__s[4].prev + 1) != -1) ||
       (_Var10 = aps_tx_window_move_next((aps_trx_window_t *)((int)&__s[4].next + 1)),
       CONCAT31(extraout_var,_Var10) == 0)) goto _L0;
    *(undefined1 *)&__s[4].next = 0;
    milli_timer_start(__s + 2,0x640);
    uVar14 = (uint)*(byte *)((int)&__s[4].next + 2);
    uVar17 = (uint)*(byte *)&__s[4].prev;
    uVar19 = (uint)bStack_32;
    if (uVar19 < uVar14 + uVar17) goto _L0;
  }
  uVar6 = uVar19 - uVar14;
  uVar7 = uVar6 & 0x1f;
  if (((uVar6 & 0xff) == uVar17 - 1) ||
     (uVar19 = (1 << ((uVar17 + uVar14) - uVar19 & 0x1f)) + -1 << (uVar6 & 0x1f),
     uVar19 == (*(byte *)((int)&__s[4].prev + 1) & uVar19))) {
    aps_send_ack(aps_hdr,(uint)*(byte *)((int)&__s[4].prev + 1) | 1 << uVar7 & 0xffU);
  }
  bVar2 = *(byte *)((int)&__s[4].prev + 1);
  if (((int)(uint)bVar2 >> uVar7 & 1U) != 0) {
_L0:
    if (msg == (zmsg_t *)0x0) {
      return;
    }
    zmsg_free(msg);
    return;
  }
  uVar11 = 1;
  bVar2 = bVar2 | (byte)(1 << uVar7);
  *(byte *)((int)&__s[4].prev + 1) = bVar2;
  w = (aps_trx_window_t *)((int)&__s[4].next + 1);
  if (bStack_32 == 0) {
    uVar21 = 1;
    if (*(char *)((int)&__s[4].next + 2) != '\0') goto _L0;
    uVar1 = *(uint8_t *)&__s[4].prev;
    *(uint8_t *)((int)&__s[4].next + 1) = (aps_hdr->ext_hdr).block_nr;
    aps_tx_window_reset_slots(w,uVar1);
    bVar3 = *(byte *)((int)&__s[4].prev + 1);
    *(undefined1 *)((int)&__s[4].next + 3) = 1;
    *(byte *)((int)&__s[4].prev + 1) = bVar2 | bVar3;
  }
  for (pdVar8 = __s->next; __s != pdVar8; pdVar8 = pdVar8->next) {
    abStack_31[0] = 0;
    zmsg_get_footer(pdVar8,abStack_31,1);
    if (bStack_32 < abStack_31[0]) break;
  }
  zmsg_add_footer(msg,&bStack_32,1);
  pdVar20 = pdVar8->prev;
  pdVar8->prev = &msg->node;
  (msg->node).next = pdVar8;
  (msg->node).prev = pdVar20;
  pdVar20->next = &msg->node;
  *(short *)&__s[1].next = *(short *)&__s[1].next + 1;
  puVar15 = (undefined4 *)zmsg_queue_get_head(__s);
  while (pdVar8 = (dlist_node_s *)*puVar15, __s != pdVar8) {
    abStack_31[0] = 0;
    bVar2 = *(byte *)((int)&__s[4].next + 3);
    bVar3 = *(byte *)((int)&__s[4].next + 2);
    zmsg_get_footer(pdVar8,abStack_31,1);
    uVar11 = (ushort)bVar3 + (ushort)bVar2 & 0xff;
    if (uVar11 != abStack_31[0]) {
      uVar21 = uVar11;
      if (abStack_31[0] <= uVar11) goto _L0;
      break;
    }
    *(char *)((int)&__s[4].next + 3) = *(char *)((int)&__s[4].next + 3) + '\x01';
    zmsg_queue_dequeue(__s,pdVar8);
    uVar16 = zmsg_get_offset(pdVar8);
    uVar11 = zmsg_get_length(pdVar8);
    sVar12 = zmsg_get_offset(pdVar8);
    iVar13 = zmsg_append_bytes_from_msg(puVar15,pdVar8,uVar16,uVar11 - sVar12);
    if (iVar13 != 0) {
      log_write(1,"aps_retrans.c","Failed to merge frag queue: %d",iVar13);
    }
    zmsg_free(pdVar8);
  }
  if (*(char *)((int)&__s[4].prev + 1) != -1) {
    return;
  }
  _Var10 = aps_tx_window_move_next(w);
  if (CONCAT31(extraout_var_00,_Var10) != 0) {
    return;
  }
  uVar21 = uVar11;
  if (*(short *)&__s[1].next == 1) {
    uVar16 = zmsg_queue_get_head(__s);
    zmsg_queue_dequeue(__s,uVar16);
    *(undefined1 *)&__s[4].next = 3;
    milli_timer_start(__s + 2,0x640);
    aps_handle_data(aps_hdr,uVar16);
    return;
  }
  goto _L0;
}

