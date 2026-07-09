/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_restore(void)

{
  ushort uVar1;
  bool bVar2;
  undefined2 *__s;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined2 uStack_48;
  undefined1 auStack_46 [32];
  short sStack_26;
  char cStack_24;
  
  sStack_26 = 0;
  cStack_24 = '\0';
  bVar2 = false;
  ds_group_info_itor_read(&uStack_48);
  while (cStack_24 == '\0') {
    __s = (undefined2 *)group_table_find(uStack_48);
    if (__s == (undefined2 *)0x0) {
      iVar3 = core_globals_get();
      iVar3 = *(int *)(iVar3 + 0x95c);
      iVar4 = core_globals_get();
      uVar6 = *(undefined4 *)(iVar4 + 0x960);
      iVar4 = core_globals_get();
      uVar1 = *(ushort *)(iVar4 + 0x964);
      uVar5 = mempool_alloc_idx(uVar6,(uint)uVar1);
      if ((uVar1 <= uVar5) || (__s = (undefined2 *)(iVar3 + uVar5 * 0x22), __s == (undefined2 *)0x0)
         ) goto _L0;
    }
    else {
      bVar2 = true;
    }
    memset(__s,0,0x22);
    *__s = uStack_48;
    memcpy(__s + 1,auStack_46,0x20);
    if (cStack_24 == '\0') {
      sStack_26 = sStack_26 + 1;
      ds_group_info_itor_read(&uStack_48);
    }
  }
  if (bVar2) {
_L0:
    iVar3 = ds_internal_remove_entry(5,0xffffffff,0);
    if (iVar3 == 0) {
      iVar3 = core_globals_get();
      uVar5 = 0;
      while ((uVar5 = bitmap_find_next_bit
                                (*(undefined4 *)(iVar3 + 0x960),*(undefined2 *)(iVar3 + 0x964),uVar5
                                ), uVar5 < *(ushort *)(iVar3 + 0x964) &&
             (iVar4 = aps_group_table_store_group(uVar5 * 0x22 + *(int *)(iVar3 + 0x95c)),
             iVar4 == 0))) {
        uVar5 = uVar5 + 1 & 0xffff;
      }
    }
  }
  return;
}

