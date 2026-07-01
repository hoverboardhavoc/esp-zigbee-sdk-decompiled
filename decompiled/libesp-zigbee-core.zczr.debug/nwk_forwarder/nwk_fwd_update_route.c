/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_update_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: fcf */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_fwd_update_route(zmsg_t *msg,nwk_tx_info_t *tx_info)

{
  uint8_t uVar1;
  ezb_shortaddr_t eVar2;
  int iVar3;
  ezb_err_t eVar4;
  int iVar5;
  uint uVar6;
  ushort auStack_12 [2];
  uint16_t fcf;
  
  zmsg_read_bytes(0,2,auStack_12);
  zmsg_read_bytes(msg,2,&tx_info->nwk_dst_addr);
  zmsg_read_bytes(msg,4,2,tx_info);
  iVar3 = nwk_is_device_zed();
  if (iVar3 == 0) {
    if (tx_info->nwk_dst_addr < 0xfff8) {
      if ((auStack_12[0] & 0x400) == 0) {
        iVar3 = nwk_neighbor_table_get_by_short();
        if ((iVar3 == 0) ||
           (((uVar6 = *(uint *)(iVar3 + 0xc) & 0x3c0, uVar6 != 0x40 && (uVar6 != 0x140)) &&
            (iVar5 = nwk_neighbor_get_outgoing_cost(), iVar5 == 0)))) {
          eVar4 = nwk_fwd_update_mesh_route(msg,auStack_12[0],tx_info);
        }
        else {
          eVar2 = nwk_neighbor_get_shortaddr(iVar3);
          tx_info->mac_dst_addr = eVar2;
          tx_info->iface_id = (byte)(*(uint *)(iVar3 + 0xc) >> 0xd) & 0x1f;
          eVar4 = 0;
        }
      }
      else {
        nwk_fwd_update_sroute(msg,auStack_12[0],tx_info);
        eVar4 = 0;
      }
    }
    else {
      tx_info->mac_dst_addr = 0xffff;
      tx_info->iface_id = '\0';
      eVar4 = 0;
    }
  }
  else {
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xac4) == 0) {
      eVar4 = 8;
    }
    else {
      eVar2 = nwk_get_parent_shortaddr();
      tx_info->mac_dst_addr = eVar2;
      uVar1 = nwk_get_parent_mac_iface_idx();
      tx_info->iface_id = uVar1;
      eVar4 = 0;
    }
  }
  return eVar4;
}

