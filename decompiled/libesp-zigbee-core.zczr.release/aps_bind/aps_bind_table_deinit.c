/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  iVar3 = *(int *)(iVar1 + 0x974);
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x978);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0x97c) != 0) && (iVar3 != 0)) && (iVar1 != 0)) {
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x974));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x974) = 0;
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x978));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x978) = 0;
    iVar1 = core_globals_get();
    iVar3 = *(int *)(iVar1 + 0x968);
    iVar1 = core_globals_get();
    iVar1 = *(int *)(iVar1 + 0x96c);
    iVar2 = core_globals_get();
    if (*(short *)(iVar2 + 0x970) != 0) goto _L0;
  }
  do {
    __assert_func(0,0,0,0);
_L0:
  } while ((iVar3 == 0) || (iVar1 == 0));
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x968));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x968) = 0;
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x96c));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x96c) = 0;
  return;
}

