/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_device_type
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_set_device_type(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 3) {
    iVar1 = core_globals_get();
    if (*(uint *)(iVar1 + 0xa2c) == param_1) {
      uVar2 = 0;
    }
    else {
      nwk_dev_ctx_deinit();
      iVar1 = core_globals_get();
      *(uint *)(iVar1 + 0xa2c) = param_1;
      nwk_dev_ctx_init();
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

