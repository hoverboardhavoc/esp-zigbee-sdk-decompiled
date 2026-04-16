/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_op_to_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

char * zdo_comm_op_to_str(zdo_comm_operation_t op)

{
  undefined3 in_register_00002029;
  
  if (CONCAT31(in_register_00002029,op) < 10) {
    return zdo_comm_op_to_str::operation_string[CONCAT31(in_register_00002029,op)];
  }
  __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_join.c",0x4c,"zdo_comm_op_to_str",
                "op <= ZDO_COMM_OP_TCLK_UPDATE");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

