/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_desc_get_ep_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint af_ep_desc_get_ep_id(byte *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != (byte *)0x0) {
    return (uint)*param_1;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1c6,
                        "af_ep_desc_get_ep_id","ep_desc");
  if (iVar1 != 0) {
    return (uint)*(ushort *)(iVar1 + 2);
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1cc,
                        "af_ep_desc_get_profile_id","ep_desc");
  if (iVar1 != 0) {
    return *(ushort *)(iVar1 + 0x12) & 0xf;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1dc,
                        "af_ep_desc_get_app_version","ep_desc");
  if (iVar1 != 0) {
    return (uint)*(ushort *)(iVar1 + 0x10);
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1ec,
                        "af_ep_desc_get_app_device_id","ep_desc");
  if (uVar2 != 0) {
    uVar2 = uVar2 + 0xc;
  }
  return uVar2;
}

