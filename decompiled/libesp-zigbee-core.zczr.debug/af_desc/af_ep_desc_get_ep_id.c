/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_desc_get_ep_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t af_ep_desc_get_ep_id(af_ep_desc_t *ep_desc)

{
  int iVar1;
  
  if (ep_desc != (af_ep_desc_t *)0x0) {
    return ep_desc->ep_id;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1c6,
                        "af_ep_desc_get_ep_id","ep_desc");
  if (iVar1 != 0) {
    return (uint8_t)*(undefined2 *)(iVar1 + 2);
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1cc,
                        "af_ep_desc_get_profile_id","ep_desc");
  if (iVar1 != 0) {
    return (byte)*(undefined2 *)(iVar1 + 0x12) & 0xf;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1dc,
                        "af_ep_desc_get_app_version","ep_desc");
  if (iVar1 != 0) {
    return (uint8_t)*(undefined2 *)(iVar1 + 0x10);
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1ec,
                        "af_ep_desc_get_app_device_id","ep_desc");
  if (iVar1 != 0) {
    iVar1 = iVar1 + 0xc;
  }
  return (uint8_t)iVar1;
}

