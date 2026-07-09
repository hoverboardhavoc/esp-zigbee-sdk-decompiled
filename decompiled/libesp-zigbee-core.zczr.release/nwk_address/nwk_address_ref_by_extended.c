/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_ref_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010a0c) */
/* WARNING: Removing unreachable block (ram,0x00010a3c) */

undefined4 nwk_address_ref_by_extended(int *param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = core_globals_get();
  if (param_1 == (int *)0x0) {
    uVar3 = 2;
  }
  else {
    if ((param_1[1] + 1U == (uint)(*param_1 == 0)) && (0xfffffffd < *param_1 - 1U)) {
      return 2;
    }
    uVar2 = search_extended(iVar1 + 0xc4c,param_1);
    if (uVar2 < *(ushort *)(iVar1 + 0xc54)) {
      addr_table_lru_update(iVar1 + 0xc4c,uVar2);
      *param_2 = (short)uVar2;
      uVar3 = 0;
    }
    else {
      uVar3 = 5;
    }
  }
  return uVar3;
}

