/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_get_key_pair_by_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * aps_secur_get_key_pair_by_addr(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != (int *)0x0) {
    if ((*param_1 != 0 || param_1[1] != 0) && ((*param_1 != -1 || (param_1[1] != -1)))) {
      uVar4 = 0;
      while( true ) {
        iVar2 = core_globals_get();
        uVar5 = *(undefined4 *)(iVar2 + 0x9a4);
        iVar2 = core_globals_get();
        uVar4 = bitmap_find_next_bit(uVar5,*(undefined2 *)(iVar2 + 0x9a8),uVar4);
        iVar2 = core_globals_get();
        if (*(ushort *)(iVar2 + 0x9a8) <= uVar4) break;
        iVar2 = core_globals_get();
        piVar1 = (int *)(*(int *)(iVar2 + 0x9a0) + uVar4 * 0x38);
        if ((*piVar1 == *param_1) && (piVar1[1] == param_1[1])) {
          return piVar1;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      }
      piVar1 = (int *)aps_secur_get_tc_address();
      if (*piVar1 == 0 && piVar1[1] == 0) {
        uVar4 = 0;
      }
      else {
        if ((*piVar1 != -1) || (piVar1[1] != -1)) {
          return (int *)0x0;
        }
        uVar4 = 0;
      }
      while( true ) {
        iVar2 = core_globals_get();
        uVar5 = *(undefined4 *)(iVar2 + 0x9a4);
        iVar2 = core_globals_get();
        uVar4 = bitmap_find_next_bit(uVar5,*(undefined2 *)(iVar2 + 0x9a8),uVar4);
        iVar2 = core_globals_get();
        if (*(ushort *)(iVar2 + 0x9a8) <= uVar4) break;
        iVar2 = core_globals_get();
        piVar1 = (int *)(*(int *)(iVar2 + 0x9a0) + uVar4 * 0x38);
        piVar3 = (int *)aps_secur_get_tc_address();
        if ((*piVar1 == *piVar3) && (piVar1[1] == piVar3[1])) {
          return piVar1;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      }
    }
  }
  return (int *)0x0;
}

