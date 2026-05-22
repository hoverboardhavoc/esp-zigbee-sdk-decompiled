/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_ep_desc_set_profile_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_ep_desc_set_profile_id(af_ep_desc_t *ep_desc,uint16_t profile_id)

{
  _Bool _Var1;
  undefined3 extraout_var;
  uint16_t extraout_a1;
  ezb_err_t eVar2;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    ep_desc = (af_ep_desc_t *)__assert_func(0,0,0);
    profile_id = extraout_a1;
  }
  _Var1 = af_device_desc_is_registered();
  eVar2 = 3;
  if (CONCAT31(extraout_var,_Var1) == 0) {
    ep_desc->profile_id = profile_id;
    eVar2 = 0;
  }
  return eVar2;
}

