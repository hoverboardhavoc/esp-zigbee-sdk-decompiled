/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_bind_table_add(undefined4 param_1,int param_2,undefined4 param_3,char *param_4,int param_5)

{
  ushort uVar1;
  undefined2 *__s;
  undefined2 *puVar2;
  uint uVar3;
  size_t __n;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (0xfd < (param_2 - 1U & 0xff)) {
    return 2;
  }
  if (((*param_4 != '\x03') || (param_5 == 0)) && (*param_4 != '\x01')) {
    return 2;
  }
  __s = (undefined2 *)bind_table_find_src(param_1,param_2,param_3);
  if (__s == (undefined2 *)0x0) {
    iVar4 = core_globals_get();
    iVar5 = *(int *)(iVar4 + 0x968);
    iVar4 = core_globals_get();
    uVar7 = *(undefined4 *)(iVar4 + 0x96c);
    uVar6 = bind_src_size();
    iVar4 = core_globals_get();
    uVar1 = *(ushort *)(iVar4 + 0x970);
    uVar3 = mempool_alloc_idx(uVar7,(uint)uVar1);
    if (uVar1 <= uVar3) {
      return 1;
    }
    __s = (undefined2 *)(iVar5 + (uVar6 & 0xffff) * uVar3);
    if (__s == (undefined2 *)0x0) {
      return 1;
    }
    __n = bind_src_size();
    memset(__s,0,__n);
    *__s = 0xffff;
    iVar4 = nwk_address_by_extended(param_1,1,__s);
    if (iVar4 != 0) goto _L0;
    *(char *)(__s + 1) = (char)param_2;
    __s[2] = (short)param_3;
  }
  puVar2 = (undefined2 *)bind_table_find_dst(param_4,param_5);
  if (puVar2 != (undefined2 *)0x0) goto _L0;
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x974);
  iVar5 = core_globals_get();
  uVar7 = *(undefined4 *)(iVar5 + 0x978);
  iVar5 = core_globals_get();
  uVar1 = *(ushort *)(iVar5 + 0x97c);
  uVar6 = mempool_alloc_idx(uVar7,(uint)uVar1);
  if (uVar6 < uVar1) {
    puVar2 = (undefined2 *)(iVar4 + uVar6 * 6);
    if (puVar2 != (undefined2 *)0x0) {
      *(undefined1 *)puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 1) = 0;
      *(undefined1 *)(puVar2 + 1) = 0;
      *(undefined1 *)((int)puVar2 + 3) = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
      *(undefined1 *)((int)puVar2 + 5) = 0;
      if (*param_4 == '\x01') {
        *puVar2 = *(undefined2 *)(param_4 + 2);
        *(byte *)((int)puVar2 + 5) = *(byte *)((int)puVar2 + 5) | 1;
      }
      else {
        iVar4 = nwk_address_by_extended(param_4 + 2,1,puVar2);
        if (iVar4 != 0) {
          bind_dst_table_free(puVar2);
          goto _L0;
        }
        *(char *)(puVar2 + 1) = (char)param_5;
      }
_L0:
      bind_table_bind(__s,puVar2);
      return 0;
    }
    iVar4 = 1;
  }
  else {
    iVar4 = 1;
  }
_L0:
  iVar5 = bind_src_is_empty(__s);
  if (iVar5 != 0) {
    bind_src_table_free(__s);
  }
  return iVar4;
}

