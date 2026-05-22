/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_set_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void zmsg_set_offset(zmsg_t *msg,uint16_t offset)

{
  int unaff_s0;
  undefined2 in_register_0000202e;
  
  if (CONCAT22(in_register_0000202e,offset) <= (uint)msg->length) {
    msg->offset = offset;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",199,"zmsg_set_offset",
                "offset <= msg->length");
  FUN_00010346((int)*(undefined8 *)(unaff_s0 + 0x60));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

