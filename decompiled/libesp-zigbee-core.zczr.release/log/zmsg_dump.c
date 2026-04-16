/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> log.o -> zmsg_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: chunk */
/* WARNING: Unknown calling convention */

void zmsg_dump(log_level_t level,char *tag,zmsg_t *msg)

{
  undefined2 uStack_1e;
  undefined1 auStack_1c [2];
  uint16_t len;
  zmsg_chunk_t chunk;
  
  uStack_1e = zmsg_get_length(msg);
  log_write(level,tag,"zmsg@%p len:%d");
  zmsg_get_first_chunk(msg,0,&uStack_1e,auStack_1c);
  while ((ushort)chunk.data != 0) {
    log_hexdump(level,tag,"chunk",chunk.buffer,(uint)(ushort)chunk.data);
    zmsg_get_next_chunk(&uStack_1e,auStack_1c);
  }
  return;
}

