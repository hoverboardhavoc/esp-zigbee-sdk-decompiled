/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_process_receive_security(mac_device *dev,mac_frame_t *frame)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = (frame->mhr).fcf;
  if ((uVar1 & 8) != 0) {
    if ((uVar1 & 0x3000) == 0) {
      uVar2 = 0xde;
    }
    else {
      uVar2 = 0xdf;
    }
    return uVar2 | 0x100;
  }
  return 0;
}

