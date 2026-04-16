/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_get_first_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void zmsg_get_first_chunk(zmsg_t *msg,uint16_t offset,uint16_t *length,zmsg_chunk_t *chunk)

{
  ushort uVar1;
  undefined4 unaff_retaddr;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined2 in_register_0000202e;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  buffer_t *pbVar7;
  
  uVar4 = CONCAT22(in_register_0000202e,offset);
  pbVar7 = msg->chunks;
  uVar1 = msg->length;
  chunk->buffer = pbVar7;
  if (uVar4 < uVar1) {
    if ((int)(uint)uVar1 < (int)(*length + uVar4)) {
      *length = uVar1 - offset;
    }
    uVar5 = 0xab;
    puVar2 = (undefined1 *)register0x00002008;
    for (uVar4 = uVar4 + msg->header; uVar4 = uVar4 & 0xffff, uVar5 < uVar4; uVar4 = uVar4 - 0xac) {
      puVar3 = puVar2;
      if (pbVar7 == (buffer_t *)0x0) {
        puVar3 = puVar2 + -0x10;
        chunk = (zmsg_chunk_t *)0x0;
        length = (ushort *)0x0;
        *(undefined4 *)(puVar2 + -4) = unaff_retaddr;
        unaff_retaddr = 0x103f6;
        uVar4 = __assert_func(0,0);
      }
      pbVar7 = *(buffer_t **)&pbVar7->field_0;
      chunk->buffer = pbVar7;
      puVar2 = puVar3;
    }
    chunk->data = (uint8_t *)((int)pbVar7->data + uVar4);
    uVar4 = 0xac - uVar4 & 0xffff;
  }
  else {
    uVar4 = 0;
  }
  chunk->len = (ushort)uVar4;
  uVar1 = *length;
  uVar6 = (ushort)uVar4;
  if (uVar1 < uVar4) {
    chunk->len = uVar1;
    uVar6 = uVar1;
  }
  *length = *length - uVar6;
  return;
}

