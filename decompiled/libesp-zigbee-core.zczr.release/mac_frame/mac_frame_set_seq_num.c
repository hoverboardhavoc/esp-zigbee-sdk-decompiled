/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_set_seq_num
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_frame_set_seq_num(ezb_radio_frame_t *frame,uint8_t seq)

{
  uint8_t extraout_a1;
  ushort *puVar1;
  
  puVar1 = (ushort *)frame->psdu;
  if ((*puVar1 & 0x100) != 0) {
    __assert_func(0,0,0,0);
    seq = extraout_a1;
  }
  *(uint8_t *)(puVar1 + 1) = seq;
  return;
}

