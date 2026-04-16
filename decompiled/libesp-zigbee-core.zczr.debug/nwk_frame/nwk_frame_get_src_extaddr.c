/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_frame_get_src_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_frame_get_src_extaddr(zmsg_t *msg,ezb_extaddr_t *src_extaddr)

{
  ezb_err_t eVar1;
  undefined4 uVar2;
  ushort auStack_12 [2];
  uint16_t nwk_fcf;
  
  zmsg_read_bytes(0,2,auStack_12);
  if ((auStack_12[0] & 0x1000) == 0) {
    eVar1 = 5;
  }
  else {
    if ((auStack_12[0] & 0x800) == 0) {
      uVar2 = 8;
    }
    else {
      uVar2 = 0x10;
    }
    zmsg_read_bytes(msg,uVar2,8,src_extaddr);
    eVar1 = 0;
  }
  return eVar1;
}

