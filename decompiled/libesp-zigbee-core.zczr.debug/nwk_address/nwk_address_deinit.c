/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  _Var1 = addr_table_is_inited((nwk_addr_table_t *)(iVar2 + 0xc4c));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    mm_free(*(undefined4 *)(iVar2 + 0xc50));
    *(undefined4 *)(iVar2 + 0xc50) = 0;
    mm_free(*(undefined4 *)(iVar2 + 0xc4c));
    *(undefined4 *)(iVar2 + 0xc4c) = 0;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x2cc,
                "nwk_address_deinit",&_L0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

