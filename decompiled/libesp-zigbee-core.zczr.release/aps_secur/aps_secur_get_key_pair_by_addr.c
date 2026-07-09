/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_get_key_pair_by_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * aps_secur_get_key_pair_by_addr(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 != (int *)0x0) &&
     ((param_1[1] + 1U != (uint)(*param_1 == 0) || (*param_1 - 1U < 0xfffffffe)))) {
    uVar4 = 0;
    while( true ) {
      iVar3 = core_globals_get();
      uVar1 = *(undefined4 *)(iVar3 + 0x9a4);
      iVar3 = core_globals_get();
      uVar4 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x9a8),uVar4);
      iVar3 = core_globals_get();
      if (*(ushort *)(iVar3 + 0x9a8) <= uVar4) break;
      iVar3 = core_globals_get();
      piVar2 = (int *)(*(int *)(iVar3 + 0x9a0) + uVar4 * 0x38);
      if ((*param_1 == *piVar2) && (param_1[1] == piVar2[1])) {
        return piVar2;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    }
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0x9b0) + 1U == (uint)(*(int *)(iVar3 + 0x9ac) == 0)) &&
       (0xfffffffd < *(int *)(iVar3 + 0x9ac) - 1U)) {
      uVar4 = 0;
      while( true ) {
        iVar3 = core_globals_get();
        uVar1 = *(undefined4 *)(iVar3 + 0x9a4);
        iVar3 = core_globals_get();
        uVar4 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x9a8),uVar4);
        iVar3 = core_globals_get();
        if (*(ushort *)(iVar3 + 0x9a8) <= uVar4) break;
        iVar3 = core_globals_get();
        piVar2 = (int *)(*(int *)(iVar3 + 0x9a0) + uVar4 * 0x38);
        iVar3 = core_globals_get();
        if ((*piVar2 == *(int *)(iVar3 + 0x9ac)) && (piVar2[1] == *(int *)(iVar3 + 0x9b0))) {
          return piVar2;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      }
    }
  }
  return (int *)0x0;
}

