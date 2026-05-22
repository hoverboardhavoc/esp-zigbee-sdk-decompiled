/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  puVar2 = *(undefined4 **)(iVar1 + 0xce0);
  while( true ) {
    if ((zdo_mgmt_req_t *)(puVar2 + -1) == (zdo_mgmt_req_t *)0xfffffffc) {
      return;
    }
    if ((puVar2[7] & 1) == 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  zdo_mgmt_req_start((zdo_mgmt_req_t *)(puVar2 + -1));
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0xce4);
  return;
}

