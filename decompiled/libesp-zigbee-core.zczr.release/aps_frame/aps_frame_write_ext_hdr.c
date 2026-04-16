/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_write_ext_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_frame_write_ext_hdr(zmsg_t *msg,uint8_t block_nr,uint8_t block_idx)

{
  uint uVar1;
  uint16_t uVar2;
  undefined3 in_register_00002031;
  uint8_t uStack_22;
  char acStack_21 [3];
  uint8_t fcf;
  
  uVar1 = CONCAT31(in_register_00002031,block_idx);
  zmsg_read_u8(msg,0,&uStack_22);
  if (-1 < (char)uStack_22) {
    uStack_22 = __assert_func(0,0,0,0);
  }
  uVar2 = aps_fcf_get_hdr_size(uStack_22);
  acStack_21[0] = (uVar1 != 0) + '\x01';
  zmsg_write_bytes(msg,uVar2,1,acStack_21);
  if (uVar1 == 0) {
    uVar1 = (uint)block_nr;
  }
  acStack_21[0] = (char)uVar1;
  zmsg_write_bytes(msg,uVar2 + 1,1,acStack_21);
  return;
}

