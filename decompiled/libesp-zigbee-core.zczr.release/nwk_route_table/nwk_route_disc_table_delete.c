/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_disc_table_delete(ushort *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  char cVar8;
  undefined4 uVar9;
  
  puVar4 = *(undefined2 **)(param_1 + 2);
  uVar2 = *param_1;
  uVar5 = nwk_get_short_address();
  iVar6 = core_globals_get();
  uVar9 = *(undefined4 *)(iVar6 + 0xc64);
  iVar6 = core_globals_get();
  uVar7 = *(undefined4 *)(iVar6 + 0xc68);
  iVar6 = core_globals_get();
  mempool_free_ent(uVar9,uVar7,0x10,*(undefined2 *)(iVar6 + 0xc6c),param_1);
  if (puVar4 != (undefined2 *)0x0) {
    if (uVar2 != uVar5) goto _L0;
    cVar8 = *(char *)((int)puVar4 + 0xd);
    if (cVar8 != '\0') goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      *(char *)((int)puVar4 + 0xd) = cVar8 + -1;
_L0:
      cVar8 = *(char *)(puVar4 + 6);
    } while (cVar8 == '\0');
    *(char *)(puVar4 + 6) = cVar8 + -1;
    if ((cVar8 == '\x01') && ((puVar4[7] & 7) != 0)) {
      bVar1 = *(byte *)((int)puVar4 + 0xf);
      uVar3 = *puVar4;
      iVar6 = core_globals_get();
      uVar9 = *(undefined4 *)(iVar6 + 0xc58);
      iVar6 = core_globals_get();
      uVar7 = *(undefined4 *)(iVar6 + 0xc5c);
      iVar6 = core_globals_get();
      mempool_free_ent(uVar9,uVar7,0x10,*(undefined2 *)(iVar6 + 0xc60),puVar4);
      nwk_fwd_handle_route_disc_done(uVar3,0x2d0);
      if ((bVar1 & 1) != 0) {
        nwk_mesh_route_discovery_done(uVar3,0x2d0,0);
        return;
      }
    }
  }
  return;
}

