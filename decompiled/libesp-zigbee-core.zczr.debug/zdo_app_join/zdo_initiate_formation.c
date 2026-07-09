/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_initiate_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_initiate_formation(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xc) != 0 || *(int *)(iVar1 + 0x10) != 0) {
    iVar1 = core_globals_get();
    nwk_set_extended_panid(iVar1 + 0xc);
  }
  zdo_initiate_commissioning(0x82);
  return;
}

