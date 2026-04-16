/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_next_by_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_group_t * aps_group_table_next_by_endpoint(uint8_t endpoint,aps_group_t *group)

{
  undefined3 in_register_00002029;
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if (group == (aps_group_t *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = ((int)group - *(int *)(iVar1 + 0x95c) >> 1) * -0xf0f0f0f & 0xffff;
  }
  do {
    uVar2 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0x960),*(undefined2 *)(iVar1 + 0x964),
                       uVar2 + 1 & 0xffff);
    if (*(ushort *)(iVar1 + 0x964) <= uVar2) {
      return (aps_group_t *)0x0;
    }
    fence();
    fence();
  } while (((uint)*(byte *)(*(int *)(iVar1 + 0x95c) + uVar2 * 0x22 +
                            (CONCAT31(in_register_00002029,endpoint) >> 3) + 2) &
           1 << (endpoint & 7)) == 0);
  return (aps_group_t *)(*(int *)(iVar1 + 0x95c) + uVar2 * 0x22);
}

