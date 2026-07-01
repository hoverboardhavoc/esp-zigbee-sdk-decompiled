/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_nwk_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_fwd_handle_nwk_frame(uint8_t iface_id,mac_frame_t *rx_frame)

{
  byte bVar1;
  ushort uVar2;
  ushort fcf;
  ezb_shortaddr_t eVar3;
  uint8_t uVar4;
  _Bool _Var5;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  int iVar6;
  zmsg_t *msg;
  int iVar7;
  int iVar8;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined4 uVar9;
  int iVar10;
  undefined3 extraout_var_03;
  ezb_err_t eVar11;
  uint uVar12;
  int *piVar13;
  undefined3 extraout_var_04;
  zmsg_t *msg_00;
  ushort *msdu;
  int iVar14;
  uint uVar15;
  int iStack_4c;
  ezb_extaddr_t extaddr;
  undefined1 auStack_40 [3];
  uint8_t cmd_id;
  nwk_rx_info_t rx_info;
  
  msdu = (ushort *)(rx_frame->mpl).buf;
  fcf = *msdu;
  if ((rx_frame->mhr).dst_addr.addr_mode != '\x02') {
    return 0x10;
  }
  if ((rx_frame->mhr).src_addr.addr_mode != '\x02') {
    return 0x10;
  }
  uVar2 = (rx_frame->mhr).src_addr.u.short_addr;
  if (0xfff7 < uVar2) {
    return 0x10;
  }
  bVar1 = (rx_frame->mpl).len;
  uVar4 = nwk_frame_find_payload_index(fcf,(uint8_t *)msdu);
  if ((uint)bVar1 <= CONCAT31(extraout_var,uVar4)) {
    return 0x10;
  }
  auStack_40._0_2_ = (rx_frame->mhr).dst_addr.u.short_addr;
  rx_info.mac_dst_addr = msdu[1];
  rx_info.mac_src_addr = msdu[2];
  rx_info.nwk_dst_addr._1_1_ = (rx_frame->from->info).tx.max_csma_backoffs;
  rx_info.nwk_src_addr._0_1_ = (rx_frame->from->info).tx.max_frame_retries;
  if (0xfff7 < rx_info.mac_src_addr) {
    return 0x12;
  }
  if ((char)msdu[3] == '\0') {
    return 0x12;
  }
  unique0x10000153 = uVar2;
  rx_info.nwk_dst_addr._0_1_ = iface_id;
  iVar6 = nwk_neighbor_table_get_by_short(uVar2);
  if (((fcf & 0x2000) != 0) && ((iVar6 == 0 || ((*(uint *)(iVar6 + 0xc) & 3) != 2)))) {
    iVar6 = nwk_is_device_zczr();
    if (iVar6 != 0) {
      nwk_send_direct_leave((uint8_t)rx_info.nwk_dst_addr,stack0xffffffc2);
    }
    return 0x12;
  }
  msg = (zmsg_t *)zmsg_alloc(9);
  if (msg == (zmsg_t *)0x0) {
    return 1;
  }
  iVar7 = zmsg_append_bytes((rx_frame->mpl).len,(rx_frame->mpl).buf);
  if (iVar7 != 0) goto _L0;
  msg->flags = msg->flags | 8;
  iVar7 = nwk_process_receive_security(CONCAT31(in_register_00002029,iface_id),msg);
  if (iVar7 != 0) goto _L0;
  extaddr.field_0.u8[7] = '\0';
  if ((fcf & 3) == 1) {
    uVar9 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,uVar9,1,(undefined1 *)((int)&extaddr.field_0 + 7));
  }
  iVar8 = nwk_secur_get_seclevel();
  eVar3 = rx_info.mac_dst_addr;
  if ((iVar8 == 0) || ((msg->flags & 2) != 0)) {
_L0:
    eVar3 = rx_info.mac_dst_addr;
    if (rx_info.mac_dst_addr < 0xfff8) {
      iVar8 = core_globals_get();
      if (eVar3 == *(ezb_shortaddr_t *)(iVar8 + 0x9e2)) {
        iVar8 = 0;
        iVar14 = 1;
      }
      else {
        if (iVar6 == 0) {
          iVar7 = 0x12;
          goto _L0;
        }
        uVar12 = *(uint *)(iVar6 + 0xc) & 0x3c0;
        if ((uVar12 == 0x80) || (uVar12 == 0x240)) {
          if (*(char *)(iVar6 + 0x19) == -1) {
            iVar8 = 1;
            iVar14 = 0;
          }
          else {
            *(char *)(iVar6 + 0x19) = *(char *)(iVar6 + 0x19) + '\x01';
            iVar8 = 1;
            iVar14 = 0;
          }
        }
        else {
          iVar8 = 1;
          iVar14 = 0;
        }
      }
    }
    else {
      _Var5 = nwk_fwd_handle_bcast((nwk_rx_info_t *)auStack_40,msg);
      iVar14 = CONCAT31(extraout_var_01,_Var5);
      iVar8 = iVar14;
    }
    if (extaddr.field_0.u8[7] == '\x05') {
      iVar8 = 0;
      iVar14 = 1;
    }
    else if ((byte)extaddr.field_0._7_1_ < 6) {
      if (extaddr.field_0.u8[7] == '\x01') {
        iVar8 = 0;
        iVar14 = 1;
      }
      else if (extaddr.field_0.u8[7] == '\x02') {
        iVar8 = 0;
      }
    }
    else if (extaddr.field_0.u8[7] == '\b') {
      iVar8 = 0;
    }
    _Var5 = nwk_is_router_started();
    if (CONCAT31(extraout_var_02,_Var5) == 0) {
      iVar8 = 0;
    }
    else if ((byte)msdu[3] < 2) {
      iVar8 = 0;
    }
    iVar10 = nwk_frame_get_src_extaddr(msg,&iStack_4c);
    if (iVar10 == 0) {
      rx_info.rssi = '\0';
      rx_info._11_1_ = 0;
      iVar10 = nwk_address_update(&iStack_4c,rx_info.mac_src_addr,&rx_info.rssi);
      if (iVar10 != 0xd) goto _L0;
      nwk_raise_address_conflict(rx_info.mac_src_addr);
_L0:
      iVar7 = 0x12;
    }
    else {
_L0:
      iVar10 = nwk_is_device_zczr();
      if (((iVar10 != 0) &&
          (uVar15 = (uint)rx_info.mac_dst_addr, uVar12 = nwk_get_short_address(), uVar15 == uVar12))
         && (iVar10 = nwk_frame_get_dst_extaddr(msg,&iStack_4c), iVar10 == 0)) {
        piVar13 = (int *)nwk_get_extended_address();
        if ((iStack_4c != *piVar13) || (extaddr.field_0.u64._0_4_ != piVar13[1])) {
          nwk_raise_address_conflict(rx_info.mac_dst_addr);
          goto _L0;
        }
      }
      if (iVar6 != 0) {
        nwk_neighbor_update_lqa
                  (iVar6,rx_info.nwk_dst_addr._1_1_,(int)(char)(uint8_t)rx_info.nwk_src_addr);
        _Var5 = nwk_is_router_started();
        if (CONCAT31(extraout_var_03,_Var5) != 0) {
          iVar10 = nwk_neighbor_table_get_by_short(rx_info.mac_src_addr);
          if (((iVar10 != 0) && ((*(uint *)(iVar6 + 0xc) & 3) == 2)) &&
             ((stack0xffffffc2 != rx_info.mac_src_addr &&
              ((rx_info.mac_dst_addr < 0xfff8 || (iVar14 != 0)))))) {
            *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffffc3f | 0x1c0;
          }
          if (((*(uint *)(iVar6 + 0xc) & 0x3c0) == 0x140) && ((msg->flags & 2) != 0)) {
            nwk_neighbor_set_auth(iVar6);
          }
          if (((((fcf & 0x400) != 0) &&
               (_Var5 = nwk_fwd_is_addr_in_realm(rx_info.mac_dst_addr),
               CONCAT31(extraout_var_04,_Var5) != 0)) &&
              (iVar6 = nwk_route_table_find(rx_info.mac_src_addr), iVar6 != 0)) &&
             (((*(ushort *)(iVar6 + 0xe) & 0x10) != 0 && ((*(uint *)(iVar6 + 0xc) >> 0x13 & 1) == 0)
              ))) {
            *(ushort *)(iVar6 + 0xe) = *(ushort *)(iVar6 + 0xe) & 0xffdf;
          }
        }
      }
      if (iVar8 != 0) {
        if (iVar14 == 0) {
          msg_00 = msg;
          msg = (zmsg_t *)0x0;
        }
        else {
          msg_00 = (zmsg_t *)zmsg_clone(msg);
        }
        if (msg_00 != (zmsg_t *)0x0) {
          iStack_4c = CONCAT31(iStack_4c._1_3_,(char)msdu[3] + -1);
          zmsg_write_bytes(msg_00,6,1,&iStack_4c);
          nwk_fwd_send_msg_delayed(msg_00,0);
        }
      }
      if (iVar14 != 0) {
        eVar11 = nwk_handle_received_msg(msg,auStack_40);
        return eVar11;
      }
    }
  }
  else if ((extaddr.field_0.u8[7] == '\x06') || (extaddr.field_0.u8[7] == '\x0e')) {
    iVar8 = core_globals_get();
    if (eVar3 == *(ezb_shortaddr_t *)(iVar8 + 0x9e2)) goto _L0;
    iVar7 = 0x12;
  }
  else {
    _Var5 = nwk_is_joined_and_authed();
    if (CONCAT31(extraout_var_00,_Var5) == 0) goto _L0;
    iVar7 = 0x12;
  }
_L0:
  if (msg == (zmsg_t *)0x0) {
    return iVar7;
  }
_L0:
  zmsg_free(msg);
  return iVar7;
}

