/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_find_payload_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t aps_frame_find_payload_offset(zmsg_t *msg)

{
  uint16_t uVar1;
  byte abStack_11 [4];
  uint8_t fcf;
  
  abStack_11[0] = 0;
  zmsg_read_bytes(0,1,abStack_11);
  uVar1 = aps_frame_fcf_skip_aux_hdr_offset(abStack_11[0],msg);
  if ((abStack_11[0] & 3) == 1) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

