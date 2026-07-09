/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_disc_table_delete(ushort *param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar5 = *(int *)(param_1 + 2);
  uVar1 = *param_1;
  uVar3 = nwk_get_short_address();
  iVar4 = core_globals_get();
  uVar6 = *(undefined4 *)(iVar4 + 0xc64);
  iVar4 = core_globals_get();
  uVar7 = *(undefined4 *)(iVar4 + 0xc68);
  iVar4 = core_globals_get();
  mempool_free_ent(uVar6,uVar7,0x10,*(undefined2 *)(iVar4 + 0xc6c),param_1);
  if (iVar5 != 0) {
    if (uVar1 == uVar3) {
      if (*(char *)(iVar5 + 0xd) == '\0') {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1a0,
                      "nwk_route_disc_table_delete","route->initiator > 0");
        iVar4 = core_globals_get();
        uVar3 = 0;
        while (uVar3 = bitmap_find_next_bit
                                 (*(undefined4 *)(iVar4 + 0xc68),*(undefined2 *)(iVar4 + 0xc6c),
                                  uVar3), uVar3 < *(ushort *)(iVar4 + 0xc6c)) {
          iVar5 = *(int *)(iVar4 + 0xc64) + uVar3 * 0x10;
          sVar2 = *(short *)(iVar5 + 8);
          if (sVar2 == 0) {
            nwk_route_disc_table_delete();
          }
          else {
            *(short *)(iVar5 + 8) = sVar2 + -1;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        }
        return;
      }
      *(char *)(iVar5 + 0xd) = *(char *)(iVar5 + 0xd) + -1;
    }
    nwk_route_finish_discovery(iVar5);
  }
  return;
}

