/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_table_deinit(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xc58);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0xc5c);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xc60) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    iVar3 = core_globals_get();
    mm_free(*(undefined4 *)(iVar3 + 0xc58));
    iVar3 = core_globals_get();
    *(undefined4 *)(iVar3 + 0xc58) = 0;
    iVar3 = core_globals_get();
    mm_free(*(undefined4 *)(iVar3 + 0xc5c));
    iVar3 = core_globals_get();
    *(undefined4 *)(iVar3 + 0xc5c) = 0;
    return;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1fe,
                        "nwk_route_table_deinit",&_LC9);
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xc64);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0xc68);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xc6c) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x203,
                  "nwk_route_disc_table_init",&_LC9);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xc64) = 0;
  *(undefined1 *)(iVar3 + 0xc65) = 0;
  *(undefined1 *)(iVar3 + 0xc66) = 0;
  *(undefined1 *)(iVar3 + 0xc67) = 0;
  *(undefined1 *)(iVar3 + 0xc68) = 0;
  *(undefined1 *)(iVar3 + 0xc69) = 0;
  *(undefined1 *)(iVar3 + 0xc6a) = 0;
  *(undefined1 *)(iVar3 + 0xc6b) = 0;
  *(undefined1 *)(iVar3 + 0xc6c) = 0;
  *(undefined1 *)(iVar3 + 0xc6d) = 0;
  *(undefined1 *)(iVar3 + 0xc6e) = 0;
  *(undefined1 *)(iVar3 + 0xc6f) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xc6c) = uVar2;
  iVar3 = core_globals_get();
  uVar2 = *(undefined2 *)(iVar3 + 0xc6c);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2,0x10);
  *(undefined4 *)(iVar3 + 0xc64) = uVar5;
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0xc6c);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xc68) = uVar5;
  return;
}

