/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> ezb_set_channel_mask
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_set_channel_mask(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 0x8000000) {
    uVar1 = 2;
    if (0x7ff < (param_1 & 0x7ffffff)) {
      iVar2 = core_globals_get(2);
      *(uint *)(iVar2 + 8) = param_1;
      uVar1 = 0;
    }
    return uVar1;
  }
  return 2;
}

