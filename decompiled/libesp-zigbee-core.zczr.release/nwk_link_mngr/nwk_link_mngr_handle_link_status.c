/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_link_mngr_handle_link_status(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ezb_shortaddr_t eVar1;
  byte bVar2;
  uint uVar3;
  _Bool _Var4;
  short sVar5;
  short sVar6;
  undefined3 extraout_var;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint8_t c_out;
  byte bVar13;
  uint uVar14;
  byte bVar15;
  char cStack_3a;
  byte bStack_39;
  ushort uStack_38;
  uint8_t cmd_id;
  uint8_t cmd_opt;
  ezb_shortaddr_t start_addr;
  ezb_shortaddr_t end_addr;
  nwk_link_status status;
  
  cStack_3a = '\0';
  _Var4 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var4) == 0) {
    return;
  }
  iVar7 = nwk_secur_get_seclevel();
  if ((ushort)(iVar7 != 0) != (msg->flags >> 1 & 1)) {
    return;
  }
  iVar7 = zmsg_get_offset(msg);
  iVar8 = zmsg_read_bytes(msg,iVar7,1,&cStack_3a);
  uVar3 = iVar7 + iVar8 & 0xffff;
  iVar7 = zmsg_read_bytes(msg,uVar3,1,&bStack_39);
  if (cStack_3a != '\b') {
    iVar7 = __assert_func(0,0,0,0);
  }
  if (rx_info->mac_src_addr != rx_info->nwk_src_addr) {
    return;
  }
  uVar14 = (uint)bStack_39;
  bVar2 = bStack_39 & 0x1f;
  uVar3 = uVar3 + iVar7 & 0xffff;
  uVar9 = zmsg_get_length(msg);
  if (uVar9 < (uVar14 & 0x1f) * 3 + uVar3) {
    return;
  }
  zmsg_remove_header(msg,uVar3);
  eVar1 = rx_info->nwk_src_addr;
  iVar7 = nwk_neighbor_table_get_by_short(eVar1);
  if (iVar7 == 0) {
    iVar7 = nwk_neighbor_table_new(1);
    if (iVar7 == 0) {
      return;
    }
    iVar8 = nwk_address_by_short(eVar1,1,iVar7);
    if (iVar8 != 0) {
      return;
    }
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffc1fff | (rx_info->iface_id & 0x1f) << 0xd
    ;
    iVar8 = core_globals_get();
    *(undefined1 *)(iVar7 + 0x19) = *(undefined1 *)(iVar8 + 0xa25);
    iVar8 = core_globals_get();
    *(undefined1 *)(iVar7 + 0x18) = *(undefined1 *)(iVar8 + 0xa25);
    nwk_neighbor_update_lqa(iVar7,rx_info->lqi,(int)rx_info->rssi);
    if ((bVar2 == 0) && (iVar8 = core_globals_get(), *(short *)(iVar8 + 0xb04) == 0)) {
      iVar8 = milli_timer_get_now();
      iVar10 = core_globals_get();
      iVar10 = milli_timer_get_fire_time(iVar10 + 0xae4);
      if (1000 < (uint)(iVar10 - iVar8)) {
        iVar10 = random_add_jitter(500);
        iVar11 = core_globals_get();
        milli_timer_stop(iVar11 + 0xae4);
        iVar11 = core_globals_get();
        milli_timer_fire_at(iVar11 + 0xae4,iVar8 + iVar10);
      }
    }
  }
  if ((*(uint *)(iVar7 + 0xc) & 3) == 3) {
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffffc | (uint)(eVar1 != 0);
  }
  if ((*(uint *)(iVar7 + 0xc) & 0x3c0) == 0xc0) {
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffc3f | 0x80;
  }
  *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfc03ffff;
  zmsg_read_bytes(msg,0,2,&uStack_38);
  zmsg_read_bytes(msg,(bStack_39 & 0x1f) * '\x03' + -3,2,&cmd_id);
  if ((((bStack_39 & 0x20) == 0) || (uVar3 = nwk_get_short_address(), uStack_38 <= uVar3)) &&
     (((bStack_39 & 0x40) == 0 || (uVar3 = nwk_get_short_address(), uVar3 <= _cmd_id)))) {
    if ((bStack_39 & 0x20) != 0) {
      *(undefined1 *)(iVar7 + 0x15) = 0;
      *(undefined1 *)(iVar7 + 0x17) = 0;
    }
    sVar6 = 0;
    for (uVar3 = 0; uVar3 != (uVar14 & 0x1f); uVar3 = uVar3 + 1 & 0xff) {
      sVar5 = zmsg_read_bytes(msg,sVar6,3,&start_addr);
      uVar12 = (uint)start_addr;
      sVar6 = sVar5 + sVar6;
      bVar15 = (byte)end_addr & 7;
      bVar2 = (byte)end_addr >> 4;
      bVar13 = bVar2 & 7;
      uVar9 = nwk_get_short_address();
      if (uVar12 == uVar9) {
        nwk_neighbor_set_outgoing_cost(iVar7,bVar15);
      }
      if ((bVar2 & 7) != 0) {
        if (bVar15 < bVar13) {
          bVar15 = bVar13;
        }
        *(byte *)(iVar7 + 0x15) = *(char *)(iVar7 + 0x15) + ('\a' - bVar15);
        iVar8 = nwk_neighbor_table_get_by_short(start_addr);
        if ((iVar8 == 0) || ((*(uint *)(iVar8 + 0xc) >> 0x1a & 7) == 0)) {
          *(byte *)(iVar7 + 0x17) = ('\a' - bVar15) + *(char *)(iVar7 + 0x17);
        }
      }
    }
    if ((bStack_39 & 0x40) != 0) {
      *(undefined1 *)(iVar7 + 0x14) = *(undefined1 *)(iVar7 + 0x15);
      *(undefined1 *)(iVar7 + 0x16) = *(undefined1 *)(iVar7 + 0x17);
    }
  }
  else {
    nwk_neighbor_set_outgoing_cost(iVar7,0);
  }
  if (((*(uint *)(iVar7 + 0xc) & 3) == 0) && ((*(uint *)(iVar7 + 0xc) >> 0x1a & 7) != 0)) {
    iVar7 = core_globals_get();
    *(byte *)(iVar7 + 0xa2a) = *(byte *)(iVar7 + 0xa2a) | 8;
  }
  return;
}

