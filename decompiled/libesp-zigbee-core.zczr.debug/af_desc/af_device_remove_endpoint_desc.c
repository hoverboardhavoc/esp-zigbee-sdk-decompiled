/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_remove_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_device_remove_endpoint_desc(af_device_desc_t *dev_desc,uint8_t ep_id)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 in_register_0000202d;
  af_ep_desc_s *paVar2;
  af_ep_desc_t *paVar3;
  
  _Var1 = af_device_desc_is_registered();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    if (dev_desc == (af_device_desc_t *)0x0) {
      paVar3 = (af_ep_desc_t *)0x0;
    }
    else {
      paVar2 = dev_desc->ep_list;
      while ((paVar2 != (af_ep_desc_s *)0x0 &&
             ((paVar3 = dev_desc->ep_list, paVar3 == (af_ep_desc_t *)0x0 ||
              ((uint)paVar3->ep_id != CONCAT31(in_register_0000202d,ep_id)))))) {
        dev_desc = (af_device_desc_t *)&paVar3->next;
        paVar2 = paVar3->next;
      }
      if (dev_desc == (af_device_desc_t *)0x0) {
        paVar3 = (af_ep_desc_t *)0x0;
      }
      else {
        paVar3 = dev_desc->ep_list;
        if (paVar3 != (af_ep_desc_t *)0x0) {
          dev_desc->ep_list = paVar3->next;
          paVar3->next = (af_ep_desc_s *)0x0;
        }
      }
    }
  }
  else {
    paVar3 = (af_ep_desc_t *)0x0;
  }
  return paVar3;
}

