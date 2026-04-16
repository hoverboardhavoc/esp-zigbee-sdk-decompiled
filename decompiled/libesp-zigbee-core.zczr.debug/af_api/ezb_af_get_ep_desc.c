/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_api.o -> ezb_af_get_ep_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_af_ep_desc_t ezb_af_get_ep_desc(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  ezb_af_ep_desc_t pvVar1;
  
  pvVar1 = (ezb_af_ep_desc_t)af_get_ep_desc(CONCAT31(in_register_00002029,ep_id));
  return pvVar1;
}

