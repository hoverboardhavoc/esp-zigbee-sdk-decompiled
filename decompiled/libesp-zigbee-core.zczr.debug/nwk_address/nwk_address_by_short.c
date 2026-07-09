/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_address_by_short(uint param_1,int param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  iVar1 = iVar2 + 0xc4c;
  if (0xfff7 < param_1) {
    return 2;
  }
  uVar3 = search_short(iVar1,param_1);
  if (uVar3 < *(ushort *)(iVar2 + 0xc54)) {
    addr_table_lru_update(iVar1,uVar3);
  }
  else {
    if (param_2 == 0) {
      return 5;
    }
    uVar3 = addr_table_add(iVar1,param_1,0);
    if (*(ushort *)(iVar2 + 0xc54) <= uVar3) {
      return 1;
    }
  }
  *param_4 = (short)uVar3;
  if (param_3 != 0) {
    nwk_address_lock_ref(uVar3);
  }
  return 0;
}

