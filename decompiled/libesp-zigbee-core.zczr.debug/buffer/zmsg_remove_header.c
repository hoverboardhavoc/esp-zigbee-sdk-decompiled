/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_remove_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_remove_header(zmsg_t *msg,uint16_t length)

{
  undefined2 in_register_0000202e;
  
  if ((uint)msg->length < CONCAT22(in_register_0000202e,length)) {
    msg = (zmsg_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x150,
                        "zmsg_remove_header",0x103a0);
  }
  else {
    msg->header = msg->header + length;
    msg->length = msg->length - length;
    if (CONCAT22(in_register_0000202e,length) < (uint)msg->offset) {
      msg->offset = msg->offset - length;
      return;
    }
  }
  msg->offset = 0;
  return;
}

