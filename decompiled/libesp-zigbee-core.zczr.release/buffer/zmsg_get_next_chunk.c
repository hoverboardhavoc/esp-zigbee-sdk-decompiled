/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_get_next_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_get_next_chunk(uint16_t *length,zmsg_chunk_t *chunk)

{
  ushort *extraout_a0;
  zmsg_chunk_t *extraout_a1;
  ushort uVar1;
  anon_union_4_2_77b2d3ce_for_buffer_s_0 aVar2;
  
  if (*length == 0) {
    chunk->len = 0;
    return;
  }
  aVar2 = chunk->buffer->field_0;
  chunk->buffer = (buffer_t *)aVar2;
  if (aVar2 == (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0) {
    zmsg_remove_header((zmsg_t *)length,(uint16_t)chunk);
    length = extraout_a0;
    chunk = extraout_a1;
  }
  chunk->data = (uint8_t *)((int)aVar2 + 4);
  chunk->len = 0xac;
  uVar1 = *length;
  if (0xac < uVar1) {
    uVar1 = 0xac;
  }
  chunk->len = uVar1;
  *length = *length - uVar1;
  return;
}

