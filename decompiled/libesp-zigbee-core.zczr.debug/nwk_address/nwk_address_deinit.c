/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_address_deinit(void)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  
  iVar2 = core_globals_get();
  _Var1 = addr_table_is_inited((nwk_addr_table_t *)(iVar2 + 0xcb0));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    mm_free(*(undefined4 *)(iVar2 + 0xcb4));
    *(undefined4 *)(iVar2 + 0xcb4) = 0;
    mm_free(*(undefined4 *)(iVar2 + 0xcb0));
    *(undefined4 *)(iVar2 + 0xcb0) = 0;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_address.c",0x338,"nwk_address_deinit",&_L0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

