/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_route_discovery_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_route_discovery_done
               (ezb_shortaddr_t dst_addr,ezb_err_t status,nwk_network_status_t nwk_status_code)

{
  undefined2 in_register_0000202a;
  undefined3 in_register_00002031;
  
  log_write(3,"nwk_mesh_routing.c","nwk_mesh_route_discovery_done(%d, 0x%02x): 0x%04x",status,
            CONCAT31(in_register_00002031,nwk_status_code),CONCAT22(in_register_0000202a,dst_addr));
  return;
}

