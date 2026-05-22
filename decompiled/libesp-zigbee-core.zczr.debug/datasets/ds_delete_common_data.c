/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/datasets.c",0x11d,
                "ds_delete_common_data",0x10608);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

