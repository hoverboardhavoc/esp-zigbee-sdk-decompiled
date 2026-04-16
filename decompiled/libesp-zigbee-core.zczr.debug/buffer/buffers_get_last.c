/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> buffers_get_last
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

buffer_t * buffers_get_last(buffer_t *bufs)

{
  buffer_t *pbVar1;
  
  if (bufs != (buffer_t *)0x0) {
    do {
      pbVar1 = bufs;
      bufs = *(buffer_t **)&bufs->field_0;
    } while (bufs != (buffer_t *)0x0);
    return pbVar1;
  }
  return (buffer_t *)0x0;
}

