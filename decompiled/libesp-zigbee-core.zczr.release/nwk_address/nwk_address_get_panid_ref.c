/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_get_panid_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_address_get_panid_ref(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(iVar1 + 0xc48,0x10,uVar2);
    uVar2 = uVar2 & 0xff;
    if (0xf < uVar2) {
      return 0xff;
    }
    iVar3 = uVar2 * 10 + iVar1 + 0x1000;
    if ((*(int *)(iVar3 + -0x458) == *param_1) && (*(int *)(iVar3 + -0x454) == param_1[1])) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return uVar2;
}

