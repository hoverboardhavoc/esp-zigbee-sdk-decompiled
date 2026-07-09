/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_desc_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_device_desc_register(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 3;
  }
  else {
    iVar1 = core_globals_get();
    *(int *)(iVar1 + 0xca0) = param_1;
    iVar1 = core_globals_get();
    af_device_add_green_power_proxy_endpoint(*(undefined4 *)(iVar1 + 0xca0));
    iVar1 = core_globals_get();
    iVar1 = af_device_desc_init(*(undefined4 *)(iVar1 + 0xca0));
    if (iVar1 != 0) {
      iVar2 = core_globals_get();
      *(undefined4 *)(iVar2 + 0xca0) = 0;
    }
  }
  return iVar1;
}

