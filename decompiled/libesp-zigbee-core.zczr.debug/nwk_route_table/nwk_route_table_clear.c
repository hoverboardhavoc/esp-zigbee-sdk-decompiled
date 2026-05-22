/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_table_clear(void)

{
  ushort uVar1;
  void *pvVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xc58);
  iVar5 = core_globals_get();
  iVar7 = *(int *)(iVar5 + 0xc5c);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xc60) != 0) && (iVar4 != 0)) && (iVar7 != 0)) {
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0xc58);
    iVar4 = core_globals_get();
    memset(pvVar2,0,(uint)*(ushort *)(iVar4 + 0xc60) << 4);
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0xc5c);
    iVar4 = core_globals_get();
    memset(pvVar2,0,*(ushort *)(iVar4 + 0xc60) + 7 >> 3);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1f9,
                "nwk_route_table_clear",&_LC9);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xc58);
  iVar5 = core_globals_get();
  iVar7 = *(int *)(iVar5 + 0xc5c);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xc60) != 0) && (iVar4 != 0)) && (iVar7 != 0)) {
    iVar4 = core_globals_get();
    mm_free(*(undefined4 *)(iVar4 + 0xc58));
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xc58) = 0;
    iVar4 = core_globals_get();
    mm_free(*(undefined4 *)(iVar4 + 0xc5c));
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xc5c) = 0;
    return;
  }
  uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1fe,
                        "nwk_route_table_deinit",&_LC9);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xc64);
  iVar5 = core_globals_get();
  iVar7 = *(int *)(iVar5 + 0xc68);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xc6c) != 0) && (iVar4 != 0)) && (iVar7 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x203,
                  "nwk_route_disc_table_init",&_LC9);
  }
  iVar4 = core_globals_get();
  *(undefined1 *)(iVar4 + 0xc64) = 0;
  *(undefined1 *)(iVar4 + 0xc65) = 0;
  *(undefined1 *)(iVar4 + 0xc66) = 0;
  *(undefined1 *)(iVar4 + 0xc67) = 0;
  *(undefined1 *)(iVar4 + 0xc68) = 0;
  *(undefined1 *)(iVar4 + 0xc69) = 0;
  *(undefined1 *)(iVar4 + 0xc6a) = 0;
  *(undefined1 *)(iVar4 + 0xc6b) = 0;
  *(undefined1 *)(iVar4 + 0xc6c) = 0;
  *(undefined1 *)(iVar4 + 0xc6d) = 0;
  *(undefined1 *)(iVar4 + 0xc6e) = 0;
  *(undefined1 *)(iVar4 + 0xc6f) = 0;
  iVar4 = core_globals_get();
  *(undefined2 *)(iVar4 + 0xc6c) = uVar3;
  iVar4 = core_globals_get();
  uVar3 = *(undefined2 *)(iVar4 + 0xc6c);
  iVar4 = core_globals_get();
  uVar6 = mm_calloc(uVar3,0x10);
  *(undefined4 *)(iVar4 + 0xc64) = uVar6;
  iVar4 = core_globals_get();
  uVar1 = *(ushort *)(iVar4 + 0xc6c);
  iVar4 = core_globals_get();
  uVar6 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar4 + 0xc68) = uVar6;
  return;
}

