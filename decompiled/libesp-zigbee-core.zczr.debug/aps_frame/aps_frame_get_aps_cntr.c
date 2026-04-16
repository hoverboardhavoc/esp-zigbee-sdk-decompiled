/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_get_aps_cntr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t aps_frame_get_aps_cntr(zmsg_t *msg)

{
  uint16_t uVar1;
  uint8_t uStack_12;
  uint8_t auStack_11 [3];
  uint8_t cntr;
  uint8_t fcf;
  
  zmsg_read_bytes(0,1,auStack_11);
  uVar1 = aps_fcf_get_hdr_size(auStack_11[0]);
  zmsg_read_bytes(msg,uVar1 - 1,1,&uStack_12);
  return uStack_12;
}

