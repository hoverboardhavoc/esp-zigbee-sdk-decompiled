/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_link_mngr_handle_link_status(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  byte bVar1;
  byte bVar2;
  _Bool _Var3;
  short sVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  byte bVar11;
  uint uVar12;
  uint8_t cnt;
  uint uVar13;
  uint uVar14;
  ushort uStack_3c;
  byte bStack_3a;
  nwk_link_status status;
  ushort uStack_34;
  ezb_shortaddr_t end_addr;
  ezb_shortaddr_t start_addr;
  uint8_t cmd_opt;
  uint8_t cmd_id;
  
  end_addr._1_1_ = '\0';
  _Var3 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var3) == 0) {
    return;
  }
  iVar5 = nwk_secur_get_seclevel();
  if ((iVar5 != 0) != ((msg->flags & 2) != 0)) {
    return;
  }
  iVar5 = zmsg_get_offset(msg);
  iVar6 = zmsg_read_bytes(msg,iVar5,1,(int)&end_addr + 1);
  uVar12 = iVar5 + iVar6 & 0xffff;
  iVar5 = zmsg_read_bytes(msg,uVar12,1,&end_addr);
  uVar12 = uVar12 + iVar5 & 0xffff;
  uVar13 = (uint)(byte)end_addr;
  bVar1 = (byte)end_addr & 0x1f;
  if (end_addr._1_1_ == '\b') {
    if (rx_info->mac_src_addr != rx_info->nwk_src_addr) {
      return;
    }
    uVar7 = zmsg_get_length(msg);
    if (uVar7 < (uVar13 & 0x1f) * 3 + uVar12) {
      return;
    }
    zmsg_remove_header(msg,uVar12);
    uVar12 = (uint)rx_info->nwk_src_addr;
    iVar5 = nwk_neighbor_table_get_by_short(uVar12);
    if (iVar5 == 0) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_link_mngr.c",0x10f,
                  "nwk_link_mngr_handle_link_status","cmd_id == 0x08U");
_L0:
    iVar5 = nwk_neighbor_table_new(1);
    if (iVar5 == 0) {
      return;
    }
    iVar6 = nwk_address_by_short(uVar12,1,iVar5);
    if (iVar6 != 0) {
      return;
    }
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffc1fff | (rx_info->iface_id & 0x1f) << 0xd
    ;
    iVar6 = core_globals_get();
    *(undefined1 *)(iVar5 + 0x19) = *(undefined1 *)(iVar6 + 0xa25);
    iVar6 = core_globals_get();
    *(undefined1 *)(iVar5 + 0x18) = *(undefined1 *)(iVar6 + 0xa25);
    nwk_neighbor_update_lqa(iVar5,rx_info->lqi,(int)rx_info->rssi);
    if ((bVar1 == 0) && (iVar6 = core_globals_get(), *(short *)(iVar6 + 0xb04) == 0)) {
      iVar6 = milli_timer_get_now();
      iVar8 = core_globals_get();
      iVar8 = milli_timer_get_fire_time(iVar8 + 0xae4);
      if (1000 < (uint)(iVar8 - iVar6)) {
        iVar8 = random_add_jitter(500,1000);
        iVar9 = core_globals_get();
        milli_timer_stop(iVar9 + 0xae4);
        iVar9 = core_globals_get();
        milli_timer_fire_at(iVar9 + 0xae4,iVar6 + iVar8);
      }
    }
  }
  if ((*(uint *)(iVar5 + 0xc) & 3) == 3) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffffc | (uint)(uVar12 != 0);
  }
  if ((*(uint *)(iVar5 + 0xc) & 0x3c0) == 0xc0) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffc3f | 0x80;
  }
  *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfc03ffff;
  zmsg_read_bytes(msg,0,2,&uStack_34);
  zmsg_read_bytes(msg,((byte)end_addr & 0x1f) * '\x03' + -3,2,&status.link_status);
  if (((((byte)end_addr & 0x20) == 0) || (uVar12 = nwk_get_short_address(), uStack_34 <= uVar12)) &&
     ((((byte)end_addr & 0x40) == 0 || (uVar12 = nwk_get_short_address(), uVar12 <= stack0xffffffca)
      ))) {
    if (((byte)end_addr & 0x20) != 0) {
      *(undefined1 *)(iVar5 + 0x15) = 0;
      *(undefined1 *)(iVar5 + 0x17) = 0;
    }
    sVar10 = 0;
    for (uVar12 = 0; uVar12 < (uVar13 & 0x1f); uVar12 = uVar12 + 1 & 0xff) {
      sVar4 = zmsg_read_bytes(msg,sVar10,3,&uStack_3c);
      sVar10 = sVar10 + sVar4;
      uVar14 = (uint)uStack_3c;
      bVar11 = bStack_3a & 7;
      bVar1 = bStack_3a >> 4;
      bVar2 = bVar1 & 7;
      uVar7 = nwk_get_short_address();
      if (uVar14 == uVar7) {
        nwk_neighbor_set_outgoing_cost(iVar5,bVar11);
      }
      if ((bVar1 & 7) != 0) {
        if (bVar11 < bVar2) {
          bVar11 = bVar2;
        }
        *(byte *)(iVar5 + 0x15) = *(char *)(iVar5 + 0x15) + ('\a' - bVar11);
        iVar6 = nwk_neighbor_table_get_by_short(uStack_3c);
        if ((iVar6 == 0) || ((*(uint *)(iVar6 + 0xc) >> 0x1a & 7) == 0)) {
          *(byte *)(iVar5 + 0x17) = *(char *)(iVar5 + 0x17) + ('\a' - bVar11);
        }
      }
    }
    if (((byte)end_addr & 0x40) != 0) {
      *(undefined1 *)(iVar5 + 0x14) = *(undefined1 *)(iVar5 + 0x15);
      *(undefined1 *)(iVar5 + 0x16) = *(undefined1 *)(iVar5 + 0x17);
      goto _L0;
    }
  }
  else {
    nwk_neighbor_set_outgoing_cost(iVar5,0);
  }
  if (iVar5 == 0) {
    return;
  }
_L0:
  if (((*(uint *)(iVar5 + 0xc) & 3) == 0) && ((*(uint *)(iVar5 + 0xc) >> 0x1a & 7) != 0)) {
    iVar5 = core_globals_get();
    *(byte *)(iVar5 + 0xa2a) = *(byte *)(iVar5 + 0xa2a) | 8;
  }
  return;
}

