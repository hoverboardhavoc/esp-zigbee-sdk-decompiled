/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_delete_common_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ds_delete_common_data(void)

{
  int error;
  
  error = ezb_plat_datasets_delete(1,0xffffffff);
  ds_log('\x03',error,1,(void *)0x0);
  if (error != 6) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/datasets.c",0x11d,"ds_delete_common_data",
                0x105f8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

