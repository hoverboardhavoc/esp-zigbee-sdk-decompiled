/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_disc_table_clear(void)

{
  ushort uVar1;
  void *pvVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar4 = core_globals_get();
  iVar7 = *(int *)(iVar4 + 0xcc8);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xccc);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xcd0) != 0) && (iVar7 != 0)) && (iVar4 != 0)) {
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0xcc8);
    iVar4 = core_globals_get();
    memset(pvVar2,0,(uint)*(ushort *)(iVar4 + 0xcd0) << 4);
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0xccc);
    iVar4 = core_globals_get();
    memset(pvVar2,0,*(ushort *)(iVar4 + 0xcd0) + 7 >> 3);
    return;
  }
  __assert_func(0,0,0,0);
  iVar4 = core_globals_get();
  iVar7 = *(int *)(iVar4 + 0xcc8);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xccc);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xcd0) != 0) && (iVar7 != 0)) && (iVar4 != 0)) {
    iVar4 = core_globals_get();
    mm_free(*(undefined4 *)(iVar4 + 0xcc8));
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xcc8) = 0;
    iVar4 = core_globals_get();
    mm_free(*(undefined4 *)(iVar4 + 0xccc));
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xccc) = 0;
    return;
  }
  uVar3 = __assert_func(0,0,0,0);
  iVar4 = core_globals_get();
  iVar7 = *(int *)(iVar4 + 0xcd4);
  iVar4 = core_globals_get();
  iVar5 = *(int *)(iVar4 + 0xcd8);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xcdc) != 0) && (iVar7 != 0)) && (iVar5 != 0)) {
    __assert_func(0,0,0,0);
  }
  iVar4 = core_globals_get();
  memset((void *)(iVar4 + 0xcd4),0,0xc);
  iVar4 = core_globals_get();
  *(undefined2 *)(iVar4 + 0xcdc) = uVar3;
  iVar4 = core_globals_get();
  uVar3 = *(undefined2 *)(iVar4 + 0xcdc);
  iVar4 = core_globals_get();
  uVar6 = mm_calloc(uVar3,0x1c);
  *(undefined4 *)(iVar4 + 0xcd4) = uVar6;
  iVar4 = core_globals_get();
  uVar1 = *(ushort *)(iVar4 + 0xcdc);
  iVar4 = core_globals_get();
  uVar6 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar4 + 0xcd8) = uVar6;
  return;
}

