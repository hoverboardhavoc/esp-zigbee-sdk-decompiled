/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_delete_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_delete_panid(uint param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  iVar1 = iVar1 + 0xc48;
  if (param_1 < 0x10) goto _L0;
  do {
    iVar1 = __assert_func(0,0,0,0);
_L0:
    iVar1 = test_and_clr_bitmap(param_1,iVar1);
  } while (iVar1 == 0);
  return;
}

