/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_set_tc_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_set_tc_address(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 auStack_12 [5];
  
  iVar3 = core_globals_get();
  if ((*(int *)(iVar3 + 0x9ac) != *param_1) || (*(int *)(iVar3 + 0x9b0) != param_1[1])) {
    auStack_12[0] = 0xffff;
    iVar3 = core_globals_get();
    iVar3 = nwk_address_ref_by_extended(iVar3 + 0x9ac,auStack_12);
    if (iVar3 == 0) {
      nwk_address_unlock_ref(auStack_12[0]);
    }
    nwk_address_by_extended(param_1,1,auStack_12);
    iVar4 = core_globals_get();
    iVar2 = param_1[1];
    iVar3 = *param_1;
    iVar1 = param_1[1];
    *(char *)(iVar4 + 0x9ac) = (char)(short)*param_1;
    *(char *)(iVar4 + 0x9ad) = (char)((uint)iVar3 >> 8);
    *(char *)(iVar4 + 0x9af) = (char)((uint)iVar3 >> 0x18);
    *(char *)(iVar4 + 0x9b1) = (char)((uint)iVar1 >> 8);
    *(char *)(iVar4 + 0x9ae) = (char)((uint)iVar3 >> 0x10);
    *(char *)(iVar4 + 0x9b0) = (char)(short)iVar2;
    *(char *)(iVar4 + 0x9b2) = (char)((uint)iVar1 >> 0x10);
    *(char *)(iVar4 + 0x9b3) = (char)((uint)iVar1 >> 0x18);
  }
  return;
}

