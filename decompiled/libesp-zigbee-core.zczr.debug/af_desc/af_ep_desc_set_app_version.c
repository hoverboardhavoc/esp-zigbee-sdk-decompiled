/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_desc_set_app_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_ep_desc_set_app_version(int param_1,byte param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x1e3,
                  "af_ep_desc_set_app_version","ep_desc");
  }
  else {
    iVar1 = af_device_desc_is_registered();
    if (iVar1 == 0) {
      *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0x12) & 0xf0 | param_2 & 0xf;
      return 0;
    }
  }
  return 3;
}

