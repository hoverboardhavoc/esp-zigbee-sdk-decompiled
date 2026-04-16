/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_prepend_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zmsg_prepend_bytes(zmsg_t *msg,uint16_t length,void *buf)

{
  buffer_t *pbVar1;
  undefined2 in_register_0000202e;
  
  while( true ) {
    if (CONCAT22(in_register_0000202e,length) <= (uint)msg->header) {
      msg->header = msg->header - length;
      msg->length = msg->length + length;
      msg->offset = msg->offset + length;
      if (buf != (void *)0x0) {
        zmsg_write_bytes(msg,0,length,buf);
      }
      return 0;
    }
    pbVar1 = (buffer_t *)mempool_malloc(0);
    if (pbVar1 == (buffer_t *)0x0) break;
    pbVar1->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)msg->chunks;
    msg->chunks = pbVar1;
    msg->header = msg->header + 0xac;
  }
  return 1;
}

