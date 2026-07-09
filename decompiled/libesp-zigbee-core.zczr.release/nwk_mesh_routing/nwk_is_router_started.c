/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_is_router_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_is_router_started(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = nwk_is_device_zczr();
  if (uVar1 != 0) {
    iVar2 = core_globals_get();
    uVar1 = *(uint *)(iVar2 + 0xb18) >> 1 & 1;
  }
  return uVar1;
}

