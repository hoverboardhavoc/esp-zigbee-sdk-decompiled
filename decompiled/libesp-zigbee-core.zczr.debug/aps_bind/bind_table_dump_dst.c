/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_dump_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int bind_table_dump_dst(undefined2 *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *__s;
  undefined2 *puVar5;
  uint uVar6;
  size_t __n;
  int iVar7;
  int extraout_a1;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = core_globals_get();
  iVar10 = -0x55555555;
  uVar2 = ((int)param_1 - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555;
  if ((*(byte *)((int)param_1 + 5) & 1) != 0) {
    iVar3 = log_write(3,"aps_bind.c",0x10edc,uVar2 & 0xffff,*param_1);
    return iVar3;
  }
  iVar3 = nwk_address_extended_by_ref(*param_1,&uStack_18);
  if (iVar3 == 0) {
    iVar3 = log_write(3,"aps_bind.c",0x10ef0,uVar2 & 0xffff,uStack_18,uStack_14,
                      *(undefined1 *)(param_1 + 1));
    return iVar3;
  }
  pcVar9 = "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &dst_addr)) == 0";
  pcVar8 = "bind_table_dump_dst";
  uVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1d4);
  if (0xfd < (extraout_a1 - 1U & 0xff)) {
    return 2;
  }
  if (((*pcVar9 != '\x03') || (iVar10 == 0)) && (*pcVar9 != '\x01')) {
    return 2;
  }
  __s = (undefined2 *)bind_table_find_src(uVar4,extraout_a1,pcVar8);
  if (__s == (undefined2 *)0x0) {
    iVar3 = core_globals_get();
    iVar7 = *(int *)(iVar3 + 0x968);
    iVar3 = core_globals_get();
    uVar11 = *(undefined4 *)(iVar3 + 0x96c);
    uVar2 = bind_src_size();
    iVar3 = core_globals_get();
    uVar1 = *(ushort *)(iVar3 + 0x970);
    uVar6 = mempool_alloc_idx(uVar11,(uint)uVar1);
    if (uVar1 <= uVar6) {
      return 1;
    }
    __s = (undefined2 *)(iVar7 + (uVar2 & 0xffff) * uVar6);
    if (__s == (undefined2 *)0x0) {
      return 1;
    }
    __n = bind_src_size();
    memset(__s,0,__n);
    *__s = 0xffff;
    iVar3 = nwk_address_by_extended(uVar4,1,__s);
    if (iVar3 != 0) goto _L0;
    *(char *)(__s + 1) = (char)extraout_a1;
    __s[2] = (short)pcVar8;
  }
  puVar5 = (undefined2 *)bind_table_find_dst(pcVar9,iVar10);
  if (puVar5 != (undefined2 *)0x0) goto _L0;
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x974);
  iVar7 = core_globals_get();
  uVar4 = *(undefined4 *)(iVar7 + 0x978);
  iVar7 = core_globals_get();
  uVar1 = *(ushort *)(iVar7 + 0x97c);
  uVar2 = mempool_alloc_idx(uVar4,(uint)uVar1);
  if (uVar2 < uVar1) {
    puVar5 = (undefined2 *)(iVar3 + uVar2 * 6);
    if (puVar5 != (undefined2 *)0x0) {
      *(undefined1 *)puVar5 = 0;
      *(undefined1 *)((int)puVar5 + 1) = 0;
      *(undefined1 *)(puVar5 + 1) = 0;
      *(undefined1 *)((int)puVar5 + 3) = 0;
      *(undefined1 *)(puVar5 + 2) = 0;
      *(undefined1 *)((int)puVar5 + 5) = 0;
      if (*pcVar9 == '\x01') {
        *puVar5 = *(undefined2 *)(pcVar9 + 2);
        *(byte *)((int)puVar5 + 5) = *(byte *)((int)puVar5 + 5) | 1;
      }
      else {
        iVar3 = nwk_address_by_extended(pcVar9 + 2,1,puVar5);
        if (iVar3 != 0) {
          bind_dst_table_free(puVar5);
          goto _L0;
        }
        *(char *)(puVar5 + 1) = (char)iVar10;
      }
_L0:
      bind_table_bind(__s,puVar5);
      return 0;
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 1;
  }
_L0:
  iVar10 = bind_src_is_empty(__s);
  if (iVar10 != 0) {
    bind_src_table_free(__s);
  }
  return iVar3;
}

