/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_get_next_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_simple_desc_t * af_get_next_simple_desc(af_simple_desc_t *simple_desc)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (simple_desc == (af_simple_desc_t *)0x0) {
    iVar2 = core_globals_get();
    uVar1 = 0;
    if (*(int *)(iVar2 + 0xd00) != 0) {
      for (; uVar1 < s_ep_num_on_dev; uVar1 = uVar1 + 1 & 0xff) {
        iVar2 = core_globals_get();
        if (*(int *)(*(int *)(iVar2 + 0xd00) + uVar1 * 4) != 0) {
          iVar2 = core_globals_get();
          puVar4 = (undefined4 *)(*(int *)(iVar2 + 0xd00) + uVar1 * 4);
          goto _L0;
        }
      }
    }
  }
  else {
    uVar1 = 0;
    do {
      if (s_ep_num_on_dev <= uVar1) {
        return (af_simple_desc_t *)0x0;
      }
      iVar2 = core_globals_get();
      iVar3 = uVar1 * 4;
      uVar1 = uVar1 + 1 & 0xff;
    } while (*(af_simple_desc_t **)(*(int *)(iVar2 + 0xd00) + iVar3) != simple_desc);
    for (; uVar1 < s_ep_num_on_dev; uVar1 = uVar1 + 1 & 0xff) {
      iVar2 = core_globals_get();
      if (*(int *)(*(int *)(iVar2 + 0xd00) + uVar1 * 4) != 0) {
        iVar2 = core_globals_get();
        puVar4 = (undefined4 *)(*(int *)(iVar2 + 0xd00) + uVar1 * 4);
_L0:
        return (af_simple_desc_t *)*puVar4;
      }
    }
  }
  return (af_simple_desc_t *)0x0;
}

