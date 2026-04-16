/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_update_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void zmsg_update_footer(zmsg_t *msg,void *obj,uint16_t len)

{
  ushort tail_size;
  buffer_t *buf;
  uint8_t *__dest;
  undefined2 in_register_00002032;
  
  tail_size = msg->tail;
  if (CONCAT22(in_register_00002032,len) <= (uint)tail_size) {
    buf = buffers_get_last(msg->chunks);
    __dest = buffer_get_tail(buf,tail_size);
    memcpy(__dest,obj,CONCAT22(in_register_00002032,len));
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x188,"len <= msg->tail");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

