/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_set_length
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zmsg_set_length(zmsg_t *msg,uint16_t length)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  
  eVar1 = zmsg_resize(msg,length);
  if ((eVar1 == 0) &&
     (msg->length = length, CONCAT22(in_register_0000202e,length) < (uint)msg->offset)) {
    msg->offset = length;
  }
  return eVar1;
}

