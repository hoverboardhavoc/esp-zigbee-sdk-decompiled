/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zmsg_t * zmsg_clone(zmsg_t *msg)

{
  zmsg_t *dst_msg;
  ezb_err_t eVar1;
  
  dst_msg = zmsg_alloc(msg->header);
  if (dst_msg != (zmsg_t *)0x0) {
    eVar1 = zmsg_append_bytes_from_msg(dst_msg,msg,0,msg->length);
    if (eVar1 == 0) {
      dst_msg->flags = msg->flags;
      (dst_msg->timestamp).val = (msg->timestamp).val;
      dst_msg->offset = msg->offset;
      return dst_msg;
    }
    zmsg_free(dst_msg);
  }
  return (zmsg_t *)0x0;
}

