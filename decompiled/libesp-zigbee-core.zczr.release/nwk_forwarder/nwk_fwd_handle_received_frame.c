/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_received_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_received_frame(uint8_t iface_id,mac_frame_t *rx_frame)

{
  ushort fcf;
  ushort uVar1;
  ezb_shortaddr_t eVar2;
  uint uVar3;
  zmsg_t *pzVar4;
  uint8_t uVar5;
  _Bool _Var6;
  uint16_t offset;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  uint uVar7;
  int iVar8;
  zmsg_t *msg;
  int iVar9;
  undefined3 extraout_var_00;
  uint *puVar10;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  zmsg_t *msg_00;
  nwk_fwd_s *pnVar11;
  nwk_fwd_s *pnVar12;
  nwk_fwd_s *pnVar13;
  ushort *puVar14;
  uint uVar15;
  uint uVar16;
  byte bStack_57;
  undefined2 uStack_56;
  uint8_t uStack_54;
  uint8_t cmd_id;
  uint8_t seq_num;
  ezb_shortaddr_t eStack_4c;
  ushort uStack_4a;
  nwk_rx_info_t rx_info;
  
  puVar14 = (ushort *)(rx_frame->mpl).buf;
  if (puVar14 == (ushort *)0x0) {
    return;
  }
  uVar16 = (uint)(rx_frame->mpl).len;
  if (uVar16 < 3) {
    return;
  }
  fcf = *puVar14;
  uVar3 = (uint)fcf;
  if ((uVar3 & 0x3c) != 8) {
    return;
  }
  if ((uVar3 & 3) == 3) {
    memcpy(&eStack_4c,&rx_frame->mhr,10);
    memcpy(&rx_info.nwk_src_addr,&(rx_frame->mhr).src_addr,10);
    iVar8 = zmsg_alloc(9);
    if (iVar8 == 0) {
      return;
    }
    iVar9 = zmsg_append_bytes((rx_frame->mpl).len,(rx_frame->mpl).buf);
    if (iVar9 != 0) {
      return;
    }
    *(ushort *)(iVar8 + 0x16) = *(ushort *)(iVar8 + 0x16) | 8;
    nwk_handle_received_intrp_msg(iVar8,&eStack_4c);
    return;
  }
  if ((rx_frame->mhr).dst_addr.addr_mode != '\x02') {
    return;
  }
  if ((rx_frame->mhr).src_addr.addr_mode != '\x02') {
    return;
  }
  uVar1 = (rx_frame->mhr).src_addr.u.short_addr;
  if (0xfff7 < uVar1) {
    return;
  }
  uVar5 = nwk_fcf_get_hdr_size(fcf);
  uVar7 = CONCAT31(extraout_var,uVar5);
  if ((fcf & 0x400) != 0) {
    uVar7 = uVar7 + (*(byte *)((int)puVar14 + uVar7) + 1) * 2 & 0xff;
  }
  if ((fcf & 0x200) != 0) {
    uVar7 = uVar7 + 0xe & 0xff;
  }
  if (uVar16 <= uVar7) {
    return;
  }
  eStack_4c = (rx_frame->mhr).dst_addr.u.short_addr;
  rx_info.mac_dst_addr = puVar14[1];
  rx_info.mac_src_addr = puVar14[2];
  rx_info.nwk_dst_addr._1_1_ = (rx_frame->from->info).tx.max_csma_backoffs;
  rx_info.nwk_src_addr._0_1_ = (rx_frame->from->info).tx.max_frame_retries;
  if (0xfff7 < rx_info.mac_src_addr) {
    return;
  }
  if ((char)puVar14[3] == '\0') {
    return;
  }
  uStack_4a = uVar1;
  rx_info.nwk_dst_addr._0_1_ = iface_id;
  iVar8 = nwk_neighbor_table_get_by_short(uVar1);
  if (((int)(uVar3 << 0x12) < 0) && ((iVar8 == 0 || ((*(uint *)(iVar8 + 0xc) & 3) != 2)))) {
    iVar8 = nwk_is_device_zczr();
    if (iVar8 == 0) {
      return;
    }
    nwk_send_direct_leave((uint8_t)rx_info.nwk_dst_addr,uStack_4a);
    return;
  }
  msg = (zmsg_t *)zmsg_alloc(9);
  if (msg == (zmsg_t *)0x0) {
    return;
  }
  iVar9 = zmsg_append_bytes((rx_frame->mpl).len,(rx_frame->mpl).buf);
  if (iVar9 != 0) goto _L0;
  msg->flags = msg->flags | 8;
  iVar9 = nwk_process_receive_security(CONCAT31(in_register_00002029,iface_id),msg);
  if (iVar9 != 0) goto _L0;
  bStack_57 = 0;
  if ((uVar3 & 3) == 1) {
    offset = zmsg_get_offset(msg);
    zmsg_read_u8(msg,offset,&bStack_57);
  }
  eVar2 = rx_info.mac_dst_addr;
  if (rx_info.mac_dst_addr < 0xfff8) {
    iVar9 = core_globals_get();
    if (*(ezb_shortaddr_t *)(iVar9 + 0x9e2) != eVar2) {
      if (iVar8 == 0) goto _L0;
      uVar16 = *(uint *)(iVar8 + 0xc) & 0x3c0;
      if (((uVar16 == 0x80) || (uVar16 == 0x240)) && (*(char *)(iVar8 + 0x1d) != -1)) {
        *(char *)(iVar8 + 0x1d) = *(char *)(iVar8 + 0x1d) + '\x01';
      }
      uVar16 = 1;
      goto _L0;
    }
    uVar16 = 0;
    uVar3 = 1;
  }
  else {
    core_globals_get();
    uVar3 = nwk_is_device_in_bcast_group(rx_info.mac_dst_addr);
    eVar2 = rx_info.mac_src_addr;
    if ((uVar3 != 0) && (iVar9 = core_globals_get(), *(ezb_shortaddr_t *)(iVar9 + 0x9e2) != eVar2))
    {
      zmsg_read_u8(msg,7,&stack0xffffffac);
      pnVar13 = &s_nwk_fwd;
      pnVar11 = (nwk_fwd_s *)0x0;
      do {
        pnVar12 = pnVar13;
        if (((*(char *)((int)&(pnVar13->send_queue).list.next + 3) != '\0') &&
            (pnVar12 = pnVar11, *(ezb_shortaddr_t *)&(pnVar13->send_queue).list.next == eVar2)) &&
           ((uint)*(byte *)((int)&(pnVar13->send_queue).list.next + 2) == (_uStack_54 & 0xff)))
        goto _L0;
        pnVar13 = (nwk_fwd_s *)&(pnVar13->send_queue).list.prev;
        pnVar11 = pnVar12;
      } while (pnVar13 != &s_nwk_fwd);
      if (pnVar12 != (nwk_fwd_s *)0x0) {
        *(ezb_shortaddr_t *)&(pnVar12->send_queue).list.next = eVar2;
        *(uint8_t *)((int)&(pnVar12->send_queue).list.next + 2) = uStack_54;
        *(undefined1 *)((int)&(pnVar12->send_queue).list.next + 3) = 9;
        time_ticker_register_receiver(0);
        uVar16 = uVar3;
        goto _L0;
      }
    }
_L0:
    uVar16 = 0;
_L0:
    uVar3 = 0;
  }
_L0:
  uVar7 = (uint)bStack_57;
  if (uVar7 == 5) {
    uVar16 = 0;
    uVar3 = 1;
  }
  else {
    if (uVar7 < 6) {
      if (uVar7 == 1) {
        uVar16 = 0;
        uVar3 = 1;
        goto _L0;
      }
      iVar9 = uVar7 - 2;
    }
    else {
      iVar9 = uVar7 - 8;
    }
    uVar16 = uVar16 & iVar9 != 0;
  }
_L0:
  _Var6 = nwk_is_router_started();
  uVar7 = CONCAT31(extraout_var_00,_Var6);
  if (uVar7 != 0) {
    uVar7 = uVar16 & 1 < (byte)puVar14[3];
  }
  iVar9 = nwk_frame_get_src_extaddr(msg,&stack0xffffffac);
  if (iVar9 == 0) {
    uStack_56 = 0;
    iVar9 = nwk_address_update(&stack0xffffffac,rx_info.mac_src_addr,&uStack_56);
    if (iVar9 == 8) {
      nwk_raise_address_conflict(rx_info.mac_src_addr);
    }
  }
  iVar9 = nwk_is_device_zczr();
  if (((iVar9 != 0) &&
      (uVar15 = (uint)rx_info.mac_dst_addr, uVar16 = nwk_get_short_address(), uVar15 == uVar16)) &&
     (iVar9 = nwk_frame_get_dst_extaddr(msg,&stack0xffffffac), iVar9 == 0)) {
    puVar10 = (uint *)nwk_get_extended_address();
    if ((_uStack_54 != *puVar10) || (_seq_num != puVar10[1])) {
      nwk_raise_address_conflict(rx_info.mac_dst_addr);
    }
  }
  if (iVar8 != 0) {
    nwk_neighbor_update_lqa
              (iVar8,rx_info.nwk_dst_addr._1_1_,(int)(char)(uint8_t)rx_info.nwk_src_addr);
    _Var6 = nwk_is_router_started();
    if (CONCAT31(extraout_var_01,_Var6) != 0) {
      iVar9 = nwk_neighbor_table_get_by_short(rx_info.mac_src_addr);
      if (((iVar9 != 0) && ((*(uint *)(iVar8 + 0xc) & 3) == 2)) &&
         ((uStack_4a != rx_info.mac_src_addr && ((rx_info.mac_dst_addr < 0xfff8 || (uVar3 != 0))))))
      {
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xfffffc3f | 0x1c0;
      }
      if (((*(uint *)(iVar8 + 0xc) & 0x3c0) == 0x140) && ((msg->flags & 2) != 0)) {
        nwk_neighbor_set_auth(iVar8);
      }
      if (((((fcf & 0x400) != 0) &&
           (_Var6 = nwk_fwd_is_addr_in_realm(rx_info.mac_dst_addr),
           CONCAT31(extraout_var_02,_Var6) != 0)) &&
          (iVar8 = nwk_route_table_find(rx_info.mac_src_addr), iVar8 != 0)) &&
         (((*(ushort *)(iVar8 + 0xe) & 0x10) != 0 && (-1 < *(int *)(iVar8 + 0xc) << 0xc)))) {
        *(ushort *)(iVar8 + 0xe) = *(ushort *)(iVar8 + 0xe) & 0xffdf;
      }
    }
  }
  if (uVar7 == 0) {
    if (uVar3 != 0) goto _L0;
  }
  else {
    if (uVar3 == 0) {
      pzVar4 = (zmsg_t *)0x0;
      msg_00 = msg;
    }
    else {
      msg_00 = (zmsg_t *)zmsg_clone();
      pzVar4 = msg;
      if (msg_00 == (zmsg_t *)0x0) goto _L0;
    }
    _uStack_54 = CONCAT31(_cmd_id,(char)puVar14[3] + -1);
    zmsg_write_bytes(6,1,&stack0xffffffac);
    nwk_fwd_send_msg(msg_00);
    msg = pzVar4;
    if (uVar3 != 0) {
_L0:
      nwk_handle_received_msg(msg,&eStack_4c);
      return;
    }
    if (pzVar4 == (zmsg_t *)0x0) {
      return;
    }
  }
_L0:
  zmsg_free(msg);
  return;
}

