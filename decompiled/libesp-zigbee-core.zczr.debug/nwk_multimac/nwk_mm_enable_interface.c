/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_enable_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_mm_enable_interface(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = nwk_mm_iface_is_disabled();
    if (iVar1 == 0) {
      uVar2 = 3;
    }
    else {
      iVar1 = core_globals_get();
      *(uint *)(iVar1 + 0xc7c) = *(uint *)(iVar1 + 0xc7c) & 0xffffff9f | 0x40;
      mac_iface_set_enabled(0,1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

