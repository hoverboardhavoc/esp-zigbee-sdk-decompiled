/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_calculate_poll_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_pim_calculate_poll_interval(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = nwk_pim_get_default_poll_interval();
  iVar2 = core_globals_get();
  if (((*(byte *)(iVar2 + 0xb16) & 0x10) != 0) && (1000 < uVar1)) {
    uVar1 = 1000;
  }
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0xb14) != 0) {
    iVar2 = core_globals_get();
    if (*(uint *)(iVar2 + 0xb10) <= uVar1) {
      iVar2 = core_globals_get();
      uVar1 = *(uint *)(iVar2 + 0xb10);
    }
  }
  if (uVar1 == 0) {
    uVar1 = 10;
  }
  return uVar1;
}

