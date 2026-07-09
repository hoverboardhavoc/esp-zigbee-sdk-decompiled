/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_address_by_extended(int *param_1,int param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = core_globals_get();
  iVar1 = iVar2 + 0xc4c;
  if (param_1 == (int *)0x0) {
    uVar4 = 2;
  }
  else if (*param_1 == 0 && param_1[1] == 0) {
    uVar4 = 2;
  }
  else if ((*param_1 == -1) && (param_1[1] == -1)) {
    uVar4 = 2;
  }
  else {
    uVar3 = search_extended(iVar1,param_1);
    if (uVar3 < *(ushort *)(iVar2 + 0xc54)) {
      addr_table_lru_update(iVar1,uVar3);
    }
    else {
      if (param_2 == 0) {
        return 5;
      }
      uVar3 = addr_table_add(iVar1,0xffff,param_1);
      if (*(ushort *)(iVar2 + 0xc54) <= uVar3) {
        return 1;
      }
    }
    *param_4 = (short)uVar3;
    if (param_3 == 0) {
      uVar4 = 0;
    }
    else {
      nwk_address_lock_ref(uVar3);
      uVar4 = 0;
    }
  }
  return uVar4;
}

