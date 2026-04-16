/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_server_get_time_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_time_server_time_ctx_t * time_server_get_time_ctx(uint8_t endpoint)

{
  zcl_attr_desc_t *pzVar1;
  zcl_time_server_time_ctx_t *pzVar2;
  
  pzVar1 = time_server_get_manufacturer_attr_desc(endpoint,0xeffe);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    pzVar2 = (zcl_time_server_time_ctx_t *)0x0;
  }
  else {
    pzVar2 = (zcl_time_server_time_ctx_t *)pzVar1->data_p;
    if (pzVar2 == (zcl_time_server_time_ctx_t *)0x0) {
      pzVar2 = (zcl_time_server_time_ctx_t *)0x0;
    }
  }
  return pzVar2;
}

