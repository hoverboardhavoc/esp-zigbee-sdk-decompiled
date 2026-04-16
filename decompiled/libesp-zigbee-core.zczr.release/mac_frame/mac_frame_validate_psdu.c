/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_validate_psdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_validate_psdu(ezb_radio_frame_t *frame)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  uint uVar2;
  ezb_err_t eVar3;
  
  uVar1 = mac_frame_find_payload_index(frame);
  uVar2 = CONCAT31(extraout_var,uVar1);
  if (uVar2 == 0xff) {
    eVar3 = 0;
  }
  else {
    if ((*(ushort *)frame->psdu & 7) == 3) {
      uVar2 = uVar2 + 1 & 0xff;
    }
    eVar3 = (uint)((uint)frame->length < (uVar2 + 2 & 0xff)) << 4;
  }
  return eVar3;
}

