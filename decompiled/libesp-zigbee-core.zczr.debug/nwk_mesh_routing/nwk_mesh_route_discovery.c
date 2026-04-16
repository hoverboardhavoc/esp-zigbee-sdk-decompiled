/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_route_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mesh_route_discovery
                    (nwk_rreq_type_t rreq_type,ezb_shortaddr_t dst_addr,uint8_t radius)

{
  uint8_t rreq_id_00;
  ezb_shortaddr_t src_addr;
  undefined3 in_register_00002029;
  int iVar1;
  undefined2 in_register_0000202e;
  ezb_err_t eVar2;
  uint8_t rreq_id;
  
  if ((CONCAT31(in_register_00002029,rreq_type) != 0) ==
      0xfff7 < CONCAT22(in_register_0000202e,dst_addr)) {
    src_addr = nwk_get_short_address();
    iVar1 = core_globals_get();
    rreq_id_00 = *(uint8_t *)(iVar1 + 0x9da);
    *(uint8_t *)(iVar1 + 0x9da) = rreq_id_00 + '\x01';
    eVar2 = nwk_mesh_route_discovery_update(rreq_id_00,rreq_type,'\0',src_addr,src_addr,dst_addr);
    if (eVar2 == 0) {
      nwk_mesh_send_rreq(dst_addr,rreq_id_00,radius,rreq_type);
    }
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

