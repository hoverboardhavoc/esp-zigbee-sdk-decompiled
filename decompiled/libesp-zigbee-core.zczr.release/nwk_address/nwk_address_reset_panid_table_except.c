/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_reset_panid_table_except
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_address_reset_panid_table_except(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar3 = nwk_address_get_panid_ref(param_1);
  if (uVar3 == 0xff) {
    uVar3 = __assert_func(0,0,0,0);
  }
  nwk_address_reset_panid_table();
  uVar1 = 1 << (uVar3 & 7) & 0xff;
  uVar3 = __atomic_fetch_or_1((uVar3 >> 3) + iVar2 + 0xc48,uVar1,5);
  return (uVar3 & uVar1) != 0;
}

