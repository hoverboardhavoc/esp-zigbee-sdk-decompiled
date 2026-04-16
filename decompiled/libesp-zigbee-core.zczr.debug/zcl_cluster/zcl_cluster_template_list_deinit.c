/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_template_list_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zcl_cluster_template_list_deinit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  while (iVar1 = core_globals_get(), *(int *)(iVar1 + 0xd9c) != 0) {
    iVar1 = core_globals_get();
    puVar2 = *(undefined4 **)(iVar1 + 0xd9c);
    if (puVar2 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar1 + 0xd9c) = *puVar2;
      *puVar2 = puVar2;
    }
    mm_free(puVar2 + -5);
  }
  return;
}

