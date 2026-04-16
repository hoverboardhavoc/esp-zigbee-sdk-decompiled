/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_frame.o -> nwk_frame_remove_dst_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_frame_remove_dst_extaddr(zmsg_t *msg)

{
  ushort uStack_14;
  ushort uStack_12;
  uint16_t fcf;
  
  zmsg_read_bytes(0,2,&uStack_14);
  if ((int)((uint)uStack_14 << 0x14) < 0) {
    zmsg_delete_header(msg,8);
    uStack_14 = uStack_14 & 0xf7ff;
    uStack_12 = uStack_14;
    zmsg_write_bytes(msg,0,2,&uStack_12);
  }
  return;
}

