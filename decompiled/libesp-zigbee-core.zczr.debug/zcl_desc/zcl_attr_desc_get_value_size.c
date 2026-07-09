/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_get_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zcl_attr_desc_get_value_size(int param_1)

{
  if (param_1 != 0) {
    zcl_get_attr_value_size(*(undefined1 *)(param_1 + 2),*(undefined4 *)(param_1 + 8));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x88,"attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

