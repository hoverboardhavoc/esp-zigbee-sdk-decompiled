/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_op_to_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 zdo_comm_op_to_str(uint param_1)

{
  if (param_1 < 10) {
    return *(undefined4 *)(operation_string_1 + param_1 * 4);
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_join.c",0x4c,
                "zdo_comm_op_to_str","op <= ZDO_COMM_OP_TCLK_UPDATE");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

