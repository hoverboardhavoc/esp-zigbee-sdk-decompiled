/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_next_by_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_group_t * aps_group_table_next_by_endpoint(uint8_t endpoint,aps_group_t *group)

{
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  
  iVar3 = core_globals_get();
  if (group == (aps_group_t *)0x0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = ((int)group - *(int *)(iVar3 + 0x95c) >> 1) * -0xf0f0f0f & 0xffff;
  }
  do {
    uVar1 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar3 + 0x960),*(undefined2 *)(iVar3 + 0x964),
                       uVar1 + 1 & 0xffff);
    if (*(ushort *)(iVar3 + 0x964) <= uVar1) {
      return (aps_group_t *)0x0;
    }
    _Var2 = group_check_endpoint((aps_group_t *)(*(int *)(iVar3 + 0x95c) + uVar1 * 0x22),endpoint);
  } while (CONCAT31(extraout_var,_Var2) == 0);
  return (aps_group_t *)(*(int *)(iVar3 + 0x95c) + uVar1 * 0x22);
}

