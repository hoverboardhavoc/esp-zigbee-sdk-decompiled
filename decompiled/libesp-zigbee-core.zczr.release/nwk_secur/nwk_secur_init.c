/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_secur_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_secur_init(void)

{
  int iVar1;
  undefined4 uStack_14;
  dataset_nib_cntr_t nib_cntr;
  
  iVar1 = core_globals_get();
  memset((void *)(iVar1 + 0x9fc),0,0x28);
  *(undefined1 *)(iVar1 + 0xa23) = 10;
  uStack_14 = 0;
  ds_internal_read_entry(8,0,&uStack_14,4);
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x9fc) = uStack_14;
  return;
}

