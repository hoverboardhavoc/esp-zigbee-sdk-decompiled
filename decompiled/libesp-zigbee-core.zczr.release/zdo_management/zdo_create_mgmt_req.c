/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_create_mgmt_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdo_mgmt_req_handle_t zdo_create_mgmt_req(uint16_t cluster_id)

{
  uint16_t *puVar1;
  
  puVar1 = (uint16_t *)mm_alloc(1,0x24);
  if (puVar1 != (uint16_t *)0x0) {
    memset(puVar1 + 1,0,0x22);
    *puVar1 = cluster_id;
    *(uint16_t **)(puVar1 + 2) = puVar1 + 2;
  }
  return puVar1;
}

