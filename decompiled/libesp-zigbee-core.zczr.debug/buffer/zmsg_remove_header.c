/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
          __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x150,"zmsg_remove_header",
                        0x10390);
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

