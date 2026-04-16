/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_iterator_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_iterator_init(uint16_t index,aps_bind_table_iterator_t *itor)

{
  uint uVar1;
  undefined2 in_register_0000202a;
  
  uVar1 = 0;
  memset(itor,0,0xc);
  do {
    if (itor->is_done != false) {
      return;
    }
    uVar1 = uVar1 + 1 & 0xffff;
    aps_bind_table_iterator_next(itor);
  } while (uVar1 <= CONCAT22(in_register_0000202a,index));
  return;
}

