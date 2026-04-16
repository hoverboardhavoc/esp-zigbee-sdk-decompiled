/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_add_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_add_simple_desc(af_simple_desc_t *desc)

{
  uint uVar1;
  int iVar2;
  
  if (desc == (af_simple_desc_t *)0x0) {
    return 2;
  }
  uVar1 = 0;
  while( true ) {
    if (s_ep_num_on_dev <= uVar1) {
      return 5;
    }
    iVar2 = core_globals_get();
    if (*(int *)(*(int *)(iVar2 + 0xd00) + uVar1 * 4) == 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = core_globals_get();
  *(af_simple_desc_t **)(*(int *)(iVar2 + 0xd00) + uVar1 * 4) = desc;
  return 0;
}

