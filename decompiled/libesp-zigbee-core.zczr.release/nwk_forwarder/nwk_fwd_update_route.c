/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_update_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_fwd_update_route(zmsg_t *msg,nwk_tx_info_t *tx_info)

{
  nwk_route_t *route;
  uint8_t uVar1;
  _Bool _Var2;
  ezb_shortaddr_t eVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  uint16_t offset;
  uint uVar6;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  ushort uStack_22;
  nwk_sroute_field_t sroute;
  uint16_t fcf;
  
  zmsg_read_le16(msg,0,&uStack_22);
  zmsg_read_le16(msg,2,&tx_info->nwk_dst_addr);
  zmsg_read_le16(msg,4,&tx_info->nwk_src_addr);
  iVar4 = nwk_is_device_zed();
  if (iVar4 != 0) {
    iVar4 = core_globals_get();
    if (*(int *)(iVar4 + 0xac4) != 0) {
      eVar3 = nwk_get_parent_shortaddr();
      tx_info->mac_dst_addr = eVar3;
      uVar1 = nwk_get_parent_mac_iface_idx();
      tx_info->iface_id = uVar1;
      return 0;
    }
    return 8;
  }
  if (tx_info->nwk_dst_addr < 0xfff8) {
    if ((uStack_22 & 0x400) == 0) {
      iVar4 = nwk_neighbor_table_get_by_short(tx_info->nwk_dst_addr);
      if ((iVar4 != 0) &&
         (((*(uint *)(iVar4 + 0xc) & 0x2c0) == 0x40 ||
          (iVar5 = nwk_neighbor_get_outgoing_cost(), iVar5 != 0)))) {
        eVar3 = nwk_neighbor_get_shortaddr(iVar4);
        uVar6 = *(uint *)(iVar4 + 0xc);
        tx_info->mac_dst_addr = eVar3;
_L0:
        tx_info->iface_id = (byte)(uVar6 >> 0xd) & 0x1f;
        return 0;
      }
      iVar4 = nwk_route_table_find(tx_info->nwk_dst_addr);
      if (iVar4 != 0) {
        if ((*(ushort *)(iVar4 + 0xe) & 7) == 0) {
          iVar5 = nwk_neighbor_table_get_by_short(*(undefined2 *)(iVar4 + 2));
          if (iVar5 == 0) {
            return 0x2d1;
          }
          uVar6 = *(uint *)(iVar5 + 0xc) & 0x3c0;
          if ((uVar6 != 0x80) && (uVar6 != 0x240)) {
            return 0x2d1;
          }
          if (*(int *)(iVar4 + 4) != -1) {
            *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + 1;
          }
          if (*(char *)(iVar4 + 10) != -1) {
            *(char *)(iVar4 + 10) = *(char *)(iVar4 + 10) + '\x01';
          }
          if (*(char *)(iVar5 + 0x18) != -1) {
            *(char *)(iVar5 + 0x18) = *(char *)(iVar5 + 0x18) + '\x01';
          }
          if (((uStack_22 & 3) == 0) &&
             (_Var2 = nwk_fwd_is_addr_in_realm(tx_info->nwk_src_addr),
             CONCAT31(extraout_var_00,_Var2) != 0)) {
            tx_info->field_0x7 =
                 (*(uint *)(iVar4 + 0xc) & 0x300000) == 0x300000 | tx_info->field_0x7 & 0xfe;
          }
          eVar3 = nwk_neighbor_get_shortaddr(iVar5);
          uVar6 = *(uint *)(iVar5 + 0xc);
          tx_info->mac_dst_addr = eVar3;
          goto _L0;
        }
        if (((*(ushort *)(iVar4 + 0xe) & 7) == 1) && (*(char *)(iVar4 + 0xd) != '\0')) {
          return 0xc;
        }
      }
      if ((uStack_22 & 0xc0) != 0x40) {
        return 0x2d1;
      }
      iVar4 = nwk_mesh_route_discovery(0,tx_info->nwk_dst_addr,0x1e);
      if (iVar4 == 0) {
        return 0xc;
      }
      return iVar4;
    }
    uVar1 = nwk_fcf_get_hdr_size(uStack_22);
    iVar4 = CONCAT31(extraout_var,uVar1);
    zmsg_read_bytes(msg,iVar4,2,&bStack_24);
    if (bStack_23 == 0) {
      offset = 2;
    }
    else {
      bStack_23 = bStack_23 - 1;
      bStack_25 = bStack_23;
      if (bStack_24 <= bStack_23) {
        __assert_func(0,0,0,0);
      }
      zmsg_write_bytes(msg,iVar4 + 1U & 0xffff,1,&bStack_25);
      offset = (short)iVar4 + (bStack_23 + 1) * 2;
    }
    zmsg_read_le16(msg,offset,&tx_info->mac_dst_addr);
  }
  else {
    tx_info->mac_dst_addr = 0xffff;
  }
  tx_info->iface_id = '\0';
  return 0;
}

