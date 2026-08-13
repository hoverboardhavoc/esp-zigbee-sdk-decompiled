/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_delete_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void ds_delete_common_data(void)

{
  int iVar1;
  
  iVar1 = ezb_plat_datasets_delete(1,0xffffffff);
  ds_log(3,iVar1,1,0);
  if (iVar1 != 6) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/datasets.c",0x11d,
                "ds_delete_common_data",
                "error != ((ezb_err_t)((0x06) == 0 ? 0 : ((((EZB_ERR_CATEGORY_GENERIC) & 0xff) << 8) | ((0x06) & 0xff))))"
               );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

