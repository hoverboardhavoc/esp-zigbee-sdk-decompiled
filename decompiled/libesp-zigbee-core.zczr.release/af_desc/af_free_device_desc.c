/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_free_device_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_free_device_desc(af_device_desc_t *dev_desc)

{
  af_ep_desc_s *paVar1;
  af_ep_desc_t *ep_desc;
  
  if (dev_desc != (af_device_desc_t *)0x0) {
    ep_desc = dev_desc->ep_list;
    while (ep_desc != (af_ep_desc_t *)0x0) {
      paVar1 = ep_desc->next;
      af_free_endpoint_desc(ep_desc);
      ep_desc = paVar1;
    }
    mm_free(dev_desc);
    return;
  }
  return;
}

