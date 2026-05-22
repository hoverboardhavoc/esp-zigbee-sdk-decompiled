/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_api.o -> ezb_af_device_remove_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_af_ep_desc_t ezb_af_device_remove_endpoint_desc(ezb_af_device_desc_t dev_desc,uint8_t ep_id)

{
  ezb_af_ep_desc_t pvVar1;
  
  pvVar1 = (ezb_af_ep_desc_t)af_device_remove_endpoint_desc();
  return pvVar1;
}

