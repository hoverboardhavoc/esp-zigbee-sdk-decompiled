/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x188,
                "len <= msg->tail");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

