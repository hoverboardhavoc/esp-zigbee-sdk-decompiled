/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_join.c",0x4c,
                "zdo_comm_op_to_str","op <= ZDO_COMM_OP_TCLK_UPDATE");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

