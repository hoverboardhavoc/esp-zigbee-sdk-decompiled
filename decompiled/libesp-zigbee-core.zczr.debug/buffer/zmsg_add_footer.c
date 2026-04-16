/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_add_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zmsg_add_footer(zmsg_t *msg,void *obj,uint16_t len)

{
  uint uVar1;
  buffer_t *buf;
  uint8_t *__dest;
  undefined2 in_register_00002032;
  ezb_err_t unaff_s3;
  
  uVar1 = (uint)msg->tail + CONCAT22(in_register_00002032,len);
  if ((uVar1 & 0xffff) < 0xad) {
    unaff_s3 = zmsg_resize(msg,msg->length + len);
    if (unaff_s3 != 0) {
      return unaff_s3;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x172,"zmsg_add_footer",
                  "new_tail_len <= (176 - sizeof(struct buf_hdr_s))");
  }
  msg->tail = (uint16_t)(uVar1 * 0x10000 >> 0x10);
  buf = buffers_get_last(msg->chunks);
  __dest = buffer_get_tail(buf,(uint16_t)uVar1);
  memcpy(__dest,obj,CONCAT22(in_register_00002032,len));
  return unaff_s3;
}

