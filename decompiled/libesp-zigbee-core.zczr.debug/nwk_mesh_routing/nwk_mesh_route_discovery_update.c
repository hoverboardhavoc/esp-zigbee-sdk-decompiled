/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_route_discovery_update
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
  ezb_err_t eVar2;
  int iVar3;
  nwk_neighbor_t *pnVar4;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined2 in_register_00002036;
  undefined2 in_register_0000203e;
  
  iVar1 = nwk_route_disc_table_find_or_create
                    (CONCAT22(in_register_00002036,src_addr),CONCAT31(in_register_00002029,rreq_id))
  ;
  if (iVar1 == 0) {
    eVar2 = 1;
  }
  else if (CONCAT31(in_register_00002031,path_cost) < (uint)*(byte *)(iVar1 + 0xb)) {
    *(uint8_t *)(iVar1 + 0xb) = path_cost;
    *(ezb_shortaddr_t *)(iVar1 + 2) = sender_addr;
    if (CONCAT31(in_register_0000202d,rreq_type) == 0) {
      if (*(int *)(iVar1 + 4) == 0) {
        iVar3 = nwk_get_short_address();
        if ((iVar3 == CONCAT22(in_register_0000203e,dst_addr)) ||
           (pnVar4 = nwk_mesh_find_child(dst_addr), pnVar4 != (nwk_neighbor_t *)0x0)) {
          eVar2 = 0;
        }
        else {
          iVar3 = nwk_route_table_find_or_create(CONCAT22(in_register_0000203e,dst_addr));
          if (iVar3 == 0) {
            nwk_route_disc_table_delete(iVar1);
            eVar2 = 1;
          }
          else {
            nwk_route_start_discovery(iVar1);
            eVar2 = 0;
          }
        }
      }
      else {
        eVar2 = 0;
      }
    }
    else {
      eVar2 = 0;
    }
  }
  else {
    eVar2 = -1;
  }
  return eVar2;
}

