/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> test_and_clr_bitmap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool test_and_clr_bitmap(uint n,bitmap_t *p)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1 << (n & 7) & 0xff;
  uVar2 = __atomic_fetch_and_1(p + (n >> 3),~uVar1 & 0xff,5);
  return (uVar2 & uVar1) != 0;
}

