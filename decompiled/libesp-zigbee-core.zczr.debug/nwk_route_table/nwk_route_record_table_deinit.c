/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_record_table_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0xcd4);
  iVar2 = core_globals_get();
  iVar3 = *(int *)(iVar2 + 0xcd8);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0xcdc) != 0) && (iVar1 != 0)) && (iVar3 != 0)) {
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0xcd4));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0xcd4) = 0;
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0xcd8));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0xcd8) = 0;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_route_table.c",0x21c,
                "nwk_route_record_table_deinit",&_LC9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

