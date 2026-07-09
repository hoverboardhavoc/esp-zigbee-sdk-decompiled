/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/datasets.c",0x11d,__func___0,
                0x10608);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

