/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_start_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_start_discovery(int param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_2 + 2) == 0) {
    if ((*(ushort *)(param_1 + 0xe) & 7) != 0) {
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xfff8 | 1;
    }
    uVar1 = *param_2;
    uVar2 = nwk_get_short_address();
    if (uVar1 != uVar2) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0xfd,
                  "nwk_route_start_discovery","route_disc->route == ((void *)0)");
  }
  if (*(char *)(param_1 + 0xd) == -1) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x104,
                  "nwk_route_start_discovery","route->initiator < (0xff)");
    iVar3 = nwk_route_table_find();
    if (iVar3 != 0) {
      if (*(char *)(iVar3 + 0xc) == '\0') {
        iVar4 = core_globals_get();
        uVar5 = *(undefined4 *)(iVar4 + 0xc58);
        iVar4 = core_globals_get();
        uVar6 = *(undefined4 *)(iVar4 + 0xc5c);
        iVar4 = core_globals_get();
        mempool_free_ent(uVar5,uVar6,0x10,*(undefined2 *)(iVar4 + 0xc60),iVar3);
      }
      else {
        *(ushort *)(iVar3 + 0xe) = *(ushort *)(iVar3 + 0xe) & 0xfff8 | 1;
      }
    }
    return;
  }
  *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) + '\x01';
_L0:
  *(int *)(param_2 + 2) = param_1;
  *(char *)(param_1 + 0xc) = *(char *)(param_1 + 0xc) + '\x01';
  return;
}

