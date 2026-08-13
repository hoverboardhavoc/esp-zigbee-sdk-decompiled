/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void nwk_address_deinit(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  iVar2 = addr_table_is_inited(iVar1 + 0xc4c);
  if (iVar2 != 0) {
    mm_free(*(undefined4 *)(iVar1 + 0xc50));
    *(undefined4 *)(iVar1 + 0xc50) = 0;
    mm_free(*(undefined4 *)(iVar1 + 0xc4c));
    *(undefined4 *)(iVar1 + 0xc4c) = 0;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x2ce,
                "nwk_address_deinit",&_L0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

