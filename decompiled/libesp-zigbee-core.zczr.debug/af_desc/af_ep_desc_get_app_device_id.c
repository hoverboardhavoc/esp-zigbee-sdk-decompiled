/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_desc_get_app_device_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t af_ep_desc_get_app_device_id(af_ep_desc_t *ep_desc)

{
  int iVar1;
  
  if (ep_desc != (af_ep_desc_t *)0x0) {
    return (ep_desc->simple_desc).app_device_id;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1ec,
                        "af_ep_desc_get_app_device_id","ep_desc");
  if (iVar1 != 0) {
    iVar1 = iVar1 + 0xc;
  }
  return (uint16_t)iVar1;
}

