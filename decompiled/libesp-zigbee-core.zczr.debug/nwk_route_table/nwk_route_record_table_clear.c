/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_record_table_clear(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0xc70);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0xc74);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xc78) != 0) && (iVar2 != 0)) && (iVar4 != 0)) {
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0xc70);
    iVar2 = core_globals_get();
    memset(pvVar1,0,(uint)*(ushort *)(iVar2 + 0xc78) * 0x1c);
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0xc74);
    iVar2 = core_globals_get();
    memset(pvVar1,0,*(ushort *)(iVar2 + 0xc78) + 7 >> 3);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x217,
                "nwk_route_record_table_clear",&_LC9);
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0xc70);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0xc74);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xc78) != 0) && (iVar2 != 0)) && (iVar4 != 0)) {
    iVar2 = core_globals_get();
    mm_free(*(undefined4 *)(iVar2 + 0xc70));
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xc70) = 0;
    iVar2 = core_globals_get();
    mm_free(*(undefined4 *)(iVar2 + 0xc74));
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xc74) = 0;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x21c,
                "nwk_route_record_table_deinit",&_LC9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

