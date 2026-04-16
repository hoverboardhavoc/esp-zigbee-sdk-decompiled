/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void zmsg_free(zmsg_t *msg)

{
  buffer_t *pbVar1;
  buffer_t *pbVar2;
  
  pbVar2 = msg->chunks;
  while (pbVar2 != (buffer_t *)0x0) {
    pbVar1 = *(buffer_t **)&pbVar2->field_0;
    pbVar2->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0;
    mempool_free(0);
    pbVar2 = pbVar1;
  }
  msg->chunks = (buffer_t *)0x0;
  mempool_free(1,msg);
  return;
}

