/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_task(void *arg)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = core_globals_get();
  puVar2 = *(undefined4 **)(iVar1 + 0xd44);
  while( true ) {
    if ((zdo_mgmt_req_t *)(puVar2 + -1) == (zdo_mgmt_req_t *)0xfffffffc) {
      return;
    }
    if ((puVar2[7] & 1) == 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  zdo_mgmt_req_start((zdo_mgmt_req_t *)(puVar2 + -1));
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0xd48);
  return;
}

