/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  int iVar3;
  uint uVar4;
  
  eVar1 = rx_info->mac_src_addr;
  pnVar2 = (nwk_neighbor_t *)nwk_neighbor_table_get_by_short(eVar1);
  if (pnVar2 == (nwk_neighbor_t *)0x0) {
    pnVar2 = (nwk_neighbor_t *)nwk_neighbor_table_new(1);
    if (pnVar2 == (nwk_neighbor_t *)0x0) {
      return (nwk_neighbor_t *)0x0;
    }
    iVar3 = nwk_address_by_short(eVar1,1,pnVar2);
    if (iVar3 != 0) {
      nwk_neighbor_table_delete(pnVar2);
      return (nwk_neighbor_t *)0x0;
    }
  }
  iVar3 = nwk_neighbor_get_incoming_cost(pnVar2);
  if (iVar3 == 0) {
    *(uint *)&pnVar2->field_0xc =
         *(uint *)&pnVar2->field_0xc & 0xfffc1fff | (rx_info->iface_id & 0x1f) << 0xd;
    iVar3 = core_globals_get();
    (pnVar2->dev).r.inbound_activity = *(uint8_t *)(iVar3 + 0xa25);
    iVar3 = core_globals_get();
    (pnVar2->dev).r.outbound_activity = *(uint8_t *)(iVar3 + 0xa25);
    nwk_neighbor_update_lqa(pnVar2,rx_info->lqi,(int)rx_info->rssi);
    uVar4 = *(uint *)&pnVar2->field_0xc;
    *(uint *)&pnVar2->field_0xc = uVar4 & 0xfffffffc | (uint)(eVar1 != 0);
    uVar4 = uVar4 & 0xfffffc3c | (uint)(eVar1 != 0);
    *(uint *)&pnVar2->field_0xc = uVar4 | 0x80;
    *(uint *)&pnVar2->field_0xc = uVar4 | 0x1c000080;
  }
  else {
    iVar3 = nwk_neighbor_get_outgoing_cost(pnVar2);
    if (iVar3 == 0) {
      pnVar2 = (nwk_neighbor_t *)0x0;
    }
  }
  return pnVar2;
}

