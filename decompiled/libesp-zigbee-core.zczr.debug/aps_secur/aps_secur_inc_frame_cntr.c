/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_inc_frame_cntr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t aps_secur_inc_frame_cntr(aps_device_key_pair_t *key_pair)

{
  uint32_t uVar1;
  
  if ((key_pair->outgoing_frame_cntr & 0x3ff) == 0) {
    aps_secur_store_key_pair(key_pair);
  }
  uVar1 = key_pair->outgoing_frame_cntr;
  key_pair->outgoing_frame_cntr = uVar1 + 1;
  return uVar1;
}

