/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_route_discovery_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mesh_route_discovery_update
                    (uint8_t rreq_id,nwk_rreq_type_t rreq_type,uint8_t path_cost,
                    ezb_shortaddr_t src_addr,ezb_shortaddr_t sender_addr,ezb_shortaddr_t dst_addr)

{
  undefined3 in_register_00002029;
  int iVar1;
  int iVar2;
  int iVar3;
  ezb_err_t eVar4;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined2 in_register_00002036;
  undefined2 in_register_0000203e;
  
  iVar3 = CONCAT22(in_register_0000203e,dst_addr);
  iVar1 = nwk_route_disc_table_find_or_create
                    (CONCAT22(in_register_00002036,src_addr),CONCAT31(in_register_00002029,rreq_id))
  ;
  if (iVar1 == 0) {
_L0:
    eVar4 = 1;
  }
  else {
    if ((uint)*(byte *)(iVar1 + 0xb) <= CONCAT31(in_register_00002031,path_cost)) {
      return -1;
    }
    *(uint8_t *)(iVar1 + 0xb) = path_cost;
    *(ezb_shortaddr_t *)(iVar1 + 2) = sender_addr;
    if ((((CONCAT31(in_register_0000202d,rreq_type) == 0) && (*(int *)(iVar1 + 4) == 0)) &&
        (iVar2 = nwk_get_short_address(), iVar2 != iVar3)) &&
       ((iVar2 = nwk_neighbor_table_get_by_short(iVar3), iVar2 == 0 ||
        ((*(uint *)(iVar2 + 0xc) & 0x3c0) != 0x40)))) {
      iVar3 = nwk_route_table_find_or_create(iVar3);
      if (iVar3 == 0) {
        nwk_route_disc_table_delete(iVar1);
        goto _L0;
      }
      nwk_route_start_discovery(iVar1);
    }
    eVar4 = 0;
  }
  return eVar4;
}

