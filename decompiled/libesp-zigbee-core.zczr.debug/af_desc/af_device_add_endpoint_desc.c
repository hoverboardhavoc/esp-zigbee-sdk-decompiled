/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_add_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_add_endpoint_desc(af_device_desc_t *dev_desc,af_ep_desc_t *ep_desc)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  af_ep_desc_t *head;
  
  if (dev_desc == (af_device_desc_t *)0x0) {
    eVar2 = 2;
  }
  else if (ep_desc == (af_ep_desc_t *)0x0) {
    eVar2 = 2;
  }
  else {
    head = dev_desc->ep_list;
    _Var1 = check_ep_is_unique(head,ep_desc->ep_id);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar2 = 2;
    }
    else {
      ep_desc->next = head;
      dev_desc->ep_list = ep_desc;
      eVar2 = 0;
    }
  }
  return eVar2;
}

