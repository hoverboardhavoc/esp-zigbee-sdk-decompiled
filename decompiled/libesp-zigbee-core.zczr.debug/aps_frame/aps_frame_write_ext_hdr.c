/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_write_ext_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_frame_write_ext_hdr(zmsg_t *msg,uint8_t block_nr,uint8_t block_idx)

{
  uint16_t unaff_s0;
  uint uVar1;
  undefined3 in_register_00002031;
  undefined1 uStack_22;
  uint8_t auStack_21 [4];
  uint8_t fcf;
  
  uVar1 = CONCAT31(in_register_00002031,block_idx);
  zmsg_read_bytes(0,1,auStack_21);
  if ((char)auStack_21[0] < '\0') {
    unaff_s0 = aps_fcf_get_hdr_size(auStack_21[0]);
    if (uVar1 == 0) {
      uStack_22 = 1;
      goto _L51;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_frame.c",0xa2,"aps_frame_write_ext_hdr",
                  "aps_fcf_has_ext_hdr(fcf)");
  }
  uStack_22 = 2;
_L51:
  zmsg_write_bytes(msg,unaff_s0,1,&uStack_22);
  if (uVar1 == 0) {
    uVar1 = (uint)block_nr;
  }
  uStack_22 = (undefined1)uVar1;
  zmsg_write_bytes(msg,unaff_s0 + 1,1,&uStack_22);
  return;
}

