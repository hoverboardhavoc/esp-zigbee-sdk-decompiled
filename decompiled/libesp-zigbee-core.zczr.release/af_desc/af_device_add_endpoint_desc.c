/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_add_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_add_endpoint_desc(af_device_desc_t *dev_desc,af_ep_desc_t *ep_desc)

{
  ezb_err_t eVar1;
  af_ep_desc_t *paVar2;
  
  eVar1 = 2;
  if (dev_desc == (af_device_desc_t *)0x0) {
    return eVar1;
  }
  if (ep_desc != (af_ep_desc_t *)0x0) {
    for (paVar2 = dev_desc->ep_list; paVar2 != (af_ep_desc_t *)0x0; paVar2 = paVar2->next) {
      if (paVar2->ep_id == ep_desc->ep_id) {
        return 2;
      }
    }
    ep_desc->next = dev_desc->ep_list;
    dev_desc->ep_list = ep_desc;
    eVar1 = 0;
  }
  return eVar1;
}

