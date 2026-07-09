/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> nwk_mm_get_next_router_iface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_mm_get_next_router_iface(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((*param_1 == -1) && (iVar2 = nwk_mm_iface_is_enabled(0), iVar2 != 0)) &&
     (iVar2 = core_globals_get(), (*(uint *)(iVar2 + 0xc7c) >> 7 & 1) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  *param_1 = '\0';
  return uVar1;
}

