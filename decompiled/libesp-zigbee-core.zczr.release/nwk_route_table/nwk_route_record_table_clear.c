/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_record_table_clear(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  iVar4 = *(int *)(iVar2 + 0xcd4);
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0xcd8);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xcdc) != 0) && (iVar4 != 0)) && (iVar2 != 0)) {
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0xcd4);
    iVar2 = core_globals_get();
    memset(pvVar1,0,(uint)*(ushort *)(iVar2 + 0xcdc) * 0x1c);
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0xcd8);
    iVar2 = core_globals_get();
    memset(pvVar1,0,*(ushort *)(iVar2 + 0xcdc) + 7 >> 3);
    return;
  }
  __assert_func(0,0,0,0);
  iVar2 = core_globals_get();
  iVar4 = *(int *)(iVar2 + 0xcd4);
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0xcd8);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xcdc) != 0) && (iVar4 != 0)) && (iVar2 != 0)) {
    iVar2 = core_globals_get();
    mm_free(*(undefined4 *)(iVar2 + 0xcd4));
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xcd4) = 0;
    iVar2 = core_globals_get();
    mm_free(*(undefined4 *)(iVar2 + 0xcd8));
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xcd8) = 0;
    return;
  }
  __assert_func(0,0,0,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

