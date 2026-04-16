/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  byte bVar1;
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
      iVar3 = nwk_is_joined();
      if (iVar3 == 0) {
        iVar3 = core_globals_get();
        eVar2 = **(ezb_shortaddr_t **)(iVar3 + 0xac4);
      }
      else {
        iVar3 = core_globals_get();
        eVar2 = nwk_neighbor_get_shortaddr(*(undefined4 *)(iVar3 + 0xac4));
      }
      tx_info->mac_dst_addr = eVar2;
      iVar3 = nwk_is_joined();
      if (iVar3 == 0) {
        iVar3 = core_globals_get();
        bVar1 = *(byte *)(*(int *)(iVar3 + 0xac4) + 0x13);
      }
      else {
        iVar3 = core_globals_get();
        bVar1 = (byte)(*(uint *)(*(int *)(iVar3 + 0xac4) + 0xc) >> 0xd);
      }
      tx_info->iface_id = bVar1 & 0x1f;
      eVar4 = 0;
    }
  }
  return eVar4;
}

