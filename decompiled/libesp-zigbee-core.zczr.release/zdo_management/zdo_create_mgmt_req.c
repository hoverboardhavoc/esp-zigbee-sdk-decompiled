/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_create_mgmt_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * zdo_create_mgmt_req(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)mm_alloc(1,0x24);
  if (puVar1 != (undefined2 *)0x0) {
    memset(puVar1 + 1,0,0x22);
    *puVar1 = param_1;
    *(undefined2 **)(puVar1 + 2) = puVar1 + 2;
  }
  return puVar1;
}

