/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_update_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_mesh_update_neighbor(nwk_rx_info_t *rx_info)

{
  ezb_shortaddr_t eVar1;
  nwk_neighbor_t *pnVar2;
  int iVar3;
  
  eVar1 = rx_info->mac_src_addr;
  pnVar2 = (nwk_neighbor_t *)nwk_neighbor_table_get_by_short(eVar1);
  if (pnVar2 == (nwk_neighbor_t *)0x0) {
    pnVar2 = (nwk_neighbor_t *)nwk_neighbor_table_new(1);
    if (pnVar2 != (nwk_neighbor_t *)0x0) {
      iVar3 = nwk_address_by_short(eVar1,1,pnVar2);
      if (iVar3 == 0) {
        *(uint *)&pnVar2->field_0xc =
             *(uint *)&pnVar2->field_0xc & 0xfffc1fff | (rx_info->iface_id & 0x1f) << 0xd;
        iVar3 = core_globals_get();
        (pnVar2->dev).r.inbound_activity = *(uint8_t *)(iVar3 + 0xa25);
        iVar3 = core_globals_get();
        (pnVar2->dev).r.outbound_activity = *(uint8_t *)(iVar3 + 0xa25);
        nwk_neighbor_update_lqa(pnVar2,rx_info->lqi,(int)rx_info->rssi);
        *(ushort *)&pnVar2->field_0xc = eVar1 != 0 | 0x80 | *(ushort *)&pnVar2->field_0xc & 0xfc3c;
        return pnVar2;
      }
      nwk_neighbor_table_delete(pnVar2);
    }
  }
  else if ((*(uint *)&pnVar2->field_0xc >> 0x1a & 7) != 0) {
    return pnVar2;
  }
  return (nwk_neighbor_t *)0x0;
}

