/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * nwk_route_disc_table_find_or_create(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = core_globals_get();
  puVar2 = (undefined2 *)route_disc_table_find(iVar1 + 0xc64,param_1,param_2);
  if ((puVar2 == (undefined2 *)0x0) &&
     (puVar2 = (undefined2 *)
               mempool_alloc_ent(*(undefined4 *)(iVar1 + 0xc64),*(undefined4 *)(iVar1 + 0xc68),0x10,
                                 *(undefined2 *)(iVar1 + 0xc6c)), puVar2 != (undefined2 *)0x0)) {
    memset(puVar2 + 2,0,0xc);
    puVar2[1] = 0xffff;
    *(undefined1 *)((int)puVar2 + 0xb) = 0xff;
    *(undefined1 *)(puVar2 + 6) = 0xff;
    *(char *)(puVar2 + 5) = (char)param_2;
    *puVar2 = (short)param_1;
    puVar2[4] = 10;
  }
  return puVar2;
}

