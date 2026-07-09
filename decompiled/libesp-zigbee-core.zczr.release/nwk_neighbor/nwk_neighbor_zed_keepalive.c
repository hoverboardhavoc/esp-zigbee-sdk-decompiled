/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_zed_keepalive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_zed_keepalive(int param_1)

{
  nwk_neighbor_zed_set_timeout(*(uint *)(param_1 + 0x14) >> 0x14 & 0xf);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x1000000;
  return;
}

