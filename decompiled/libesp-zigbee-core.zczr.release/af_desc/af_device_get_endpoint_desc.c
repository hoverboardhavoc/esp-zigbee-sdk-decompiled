/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_get_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_device_get_endpoint_desc(af_device_desc_t *dev_desc,uint8_t ep_id)

{
  af_ep_desc_t *paVar1;
  undefined3 in_register_0000202d;
  
  for (paVar1 = dev_desc->ep_list;
      (paVar1 != (af_ep_desc_t *)0x0 &&
      ((uint)paVar1->ep_id != CONCAT31(in_register_0000202d,ep_id))); paVar1 = paVar1->next) {
  }
  return paVar1;
}

