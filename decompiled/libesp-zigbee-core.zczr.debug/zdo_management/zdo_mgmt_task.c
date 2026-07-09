/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_task(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = core_globals_get();
  puVar2 = *(undefined4 **)(iVar1 + 0xce0);
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    if ((puVar2[7] & 1) == 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  zdo_mgmt_req_start();
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0xce4);
  return;
}

