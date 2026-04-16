/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_received_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_received_frame(uint8_t iface_id,mac_frame_t *rx_frame)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = (ushort *)(rx_frame->mpl).buf;
  if ((((puVar3 != (ushort *)0x0) && (bVar1 = (rx_frame->mpl).len, bVar1 != 0)) && (2 < bVar1)) &&
     (uVar2 = *puVar3, (uVar2 & 0x3c) == 8)) {
    if ((uVar2 & 3) == 3) {
      nwk_fwd_handle_intrp_frame(iface_id,rx_frame);
    }
    else {
      nwk_fwd_handle_nwk_frame(iface_id,rx_frame);
    }
  }
  return;
}

