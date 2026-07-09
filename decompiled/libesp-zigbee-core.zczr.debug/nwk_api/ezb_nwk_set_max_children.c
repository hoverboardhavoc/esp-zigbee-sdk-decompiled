/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_set_max_children
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_set_max_children(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    uVar2 = 6;
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9db) = param_1;
    uVar2 = 0;
  }
  return uVar2;
}

