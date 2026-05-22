/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_desc_set_app_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_ep_desc_set_app_version(af_ep_desc_t *ep_desc,uint8_t app_version)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1e3,
                  "af_ep_desc_set_app_version","ep_desc");
  }
  else {
    _Var1 = af_device_desc_is_registered();
    if (CONCAT31(extraout_var,_Var1) == 0) {
      (ep_desc->simple_desc).field_0x6 = (ep_desc->simple_desc).field_0x6 & 0xf0 | app_version & 0xf
      ;
      return 0;
    }
  }
  return 3;
}

