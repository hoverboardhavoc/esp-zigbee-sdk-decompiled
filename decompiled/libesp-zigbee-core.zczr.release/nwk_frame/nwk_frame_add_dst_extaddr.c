/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_frame.o -> nwk_frame_add_dst_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_frame_add_dst_extaddr(zmsg_t *msg,ezb_extaddr_t *device_address)

{
  ushort uStack_1a;
  uint uStack_18;
  uint16_t fcf;
  undefined4 uStack_14;
  
  zmsg_read_bytes(0,2,&uStack_1a);
  if (-1 < (int)((uint)uStack_1a << 0x14)) {
    zmsg_insert_header(msg,8);
    uStack_18 = CONCAT22(fcf,uStack_1a) | 0x800;
    uStack_1a = uStack_1a | 0x800;
    zmsg_write_bytes(msg,0,2,&stack0xffffffe8);
  }
  uStack_18 = *(uint *)&device_address->field_0;
  uStack_14 = *(undefined4 *)((int)&device_address->field_0 + 4);
  zmsg_write_bytes(msg,8,&stack0xffffffe8);
  return;
}

