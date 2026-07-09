/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_finish_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_finish_discovery(undefined2 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  cVar1 = *(char *)(param_1 + 6);
  if (cVar1 == '\0') {
    puVar4 = (undefined2 *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x10e,
                           "nwk_route_finish_discovery","route->ref > 0");
  }
  else {
    *(char *)(param_1 + 6) = cVar1 + -1;
    if (cVar1 != '\x01') {
      return;
    }
    puVar4 = param_1;
    if ((param_1[7] & 7) == 0) {
      return;
    }
  }
  bVar2 = *(byte *)((int)puVar4 + 0xf);
  uVar3 = *puVar4;
  iVar5 = core_globals_get();
  uVar6 = *(undefined4 *)(iVar5 + 0xc58);
  iVar5 = core_globals_get();
  uVar7 = *(undefined4 *)(iVar5 + 0xc5c);
  iVar5 = core_globals_get();
  mempool_free_ent(uVar6,uVar7,0x10,*(undefined2 *)(iVar5 + 0xc60),param_1);
  nwk_fwd_handle_route_disc_done(uVar3,0x2d0);
  if ((bVar2 & 1) != 0) {
    nwk_mesh_route_discovery_done(uVar3,0x2d0,0);
  }
  return;
}

