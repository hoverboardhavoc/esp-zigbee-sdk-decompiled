/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_update_neighbor
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
  nwk_neighbor_t *pnVar3;
  int iVar4;
  uint uVar5;
  
  eVar1 = rx_info->mac_src_addr;
  pnVar2 = (nwk_neighbor_t *)nwk_neighbor_table_get_by_short(eVar1);
  if (pnVar2 == (nwk_neighbor_t *)0x0) {
    pnVar3 = (nwk_neighbor_t *)nwk_neighbor_table_new(1);
    if (pnVar3 != (nwk_neighbor_t *)0x0) {
      iVar4 = nwk_address_by_short(eVar1,1,pnVar3);
      if (iVar4 == 0) {
        *(uint *)&pnVar3->field_0xc =
             *(uint *)&pnVar3->field_0xc & 0xfffc1fff | (rx_info->iface_id & 0x1f) << 0xd;
        iVar4 = core_globals_get();
        (pnVar3->dev).r.inbound_activity = *(uint8_t *)(iVar4 + 0xa25);
        iVar4 = core_globals_get();
        (pnVar3->dev).r.outbound_activity = *(uint8_t *)(iVar4 + 0xa25);
        nwk_neighbor_update_lqa(pnVar3,rx_info->lqi,(int)rx_info->rssi);
        uVar5 = *(uint *)&pnVar3->field_0xc;
        *(uint *)&pnVar3->field_0xc = uVar5 & 0xfffffffc | (uint)(eVar1 != 0);
        *(uint *)&pnVar3->field_0xc = uVar5 & 0xfffffc3c | (uint)(eVar1 != 0) | 0x80;
      }
      else {
        nwk_neighbor_table_delete(pnVar3);
        pnVar3 = pnVar2;
      }
    }
  }
  else {
    pnVar3 = pnVar2;
    if ((*(uint *)&pnVar2->field_0xc >> 0x1a & 7) == 0) {
      pnVar3 = (nwk_neighbor_t *)0x0;
    }
  }
  return pnVar3;
}

