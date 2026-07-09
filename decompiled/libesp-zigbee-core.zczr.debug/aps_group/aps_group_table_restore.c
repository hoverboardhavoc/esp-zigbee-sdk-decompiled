/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_restore(void)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 *__s;
  bool bVar6;
  undefined4 uVar7;
  undefined2 uStack_48;
  undefined1 auStack_46 [32];
  undefined2 uStack_26;
  char cStack_24;
  
  uStack_26 = 0;
  cStack_24 = '\0';
  ds_group_info_itor_read(&uStack_48);
  bVar2 = false;
  do {
    if (cStack_24 != '\0') {
      bVar6 = false;
_L0:
      if ((bVar2) || (bVar6)) {
        aps_group_table_refresh_stored_groups();
      }
      return;
    }
    __s = (undefined2 *)group_table_find(uStack_48);
    if (__s == (undefined2 *)0x0) {
      iVar3 = core_globals_get();
      iVar3 = *(int *)(iVar3 + 0x95c);
      iVar4 = core_globals_get();
      uVar7 = *(undefined4 *)(iVar4 + 0x960);
      iVar4 = core_globals_get();
      uVar1 = *(ushort *)(iVar4 + 0x964);
      uVar5 = mempool_alloc_idx(uVar7,(uint)uVar1);
      if (uVar1 <= uVar5) {
        bVar6 = true;
        goto _L0;
      }
      __s = (undefined2 *)(iVar3 + uVar5 * 0x22);
      if (__s == (undefined2 *)0x0) {
        bVar6 = true;
        goto _L0;
      }
    }
    else {
      bVar2 = true;
    }
    memset(__s,0,0x22);
    *__s = uStack_48;
    memcpy(__s + 1,auStack_46,0x20);
    ds_group_info_next(&uStack_48);
  } while( true );
}

