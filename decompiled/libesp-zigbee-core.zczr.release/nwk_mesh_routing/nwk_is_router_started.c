/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_is_router_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_is_router_started(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = nwk_is_device_zczr();
  if (uVar1 != 0) {
    iVar2 = core_globals_get();
    uVar1 = *(uint *)(iVar2 + 0xb18) >> 1 & 1;
  }
  return SUB41(uVar1,0);
}

