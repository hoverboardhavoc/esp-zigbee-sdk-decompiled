/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_key_pair_set_deinit(void)

{
  code *unaff_retaddr;
  undefined4 unaff_s0;
  int unaff_s1;
  int iVar1;
  int unaff_s2;
  
  while( true ) {
    *(code **)((int)register0x00002008 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -8) = unaff_s0;
    *(int *)((int)register0x00002008 + -0xc) = unaff_s1;
    *(int *)((int)register0x00002008 + -0x10) = unaff_s2;
    aps_secur_key_pair_set_clear();
    iVar1 = core_globals_get();
    unaff_s0 = 0x1000;
    unaff_s2 = *(int *)(iVar1 + 0x9a0);
    iVar1 = core_globals_get();
    unaff_s1 = *(int *)(iVar1 + 0x9a4);
    iVar1 = core_globals_get();
    if (((*(short *)(iVar1 + 0x9a8) != 0) && (unaff_s2 != 0)) && (unaff_s1 != 0)) break;
    unaff_retaddr = aps_secur_deinit;
    __assert_func(0,0,0,0);
    register0x00002008 = (BADSPACEBASE *)((int)register0x00002008 + -0x10);
  }
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x9a0));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x9a0) = 0;
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x9a4));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x9a4) = 0;
  return;
}

