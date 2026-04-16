/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_command(mac_device *dev,mac_frame_t *mac_frame)

{
  byte bVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  
  bVar1 = *(mac_frame->mpl).buf;
  if (bVar1 == 4) {
    mac_handle_data_req(dev,mac_frame);
  }
  else if (bVar1 < 5) {
    if (bVar1 == 1) {
      if (((dev->pib).field_0x2a & 1) != 0) {
        mac_handle_association_req(dev,mac_frame);
      }
    }
    else if (((bVar1 == 2) &&
             (((undefined1  [116])dev->ctx & (undefined1  [116])0xffff00) ==
              (undefined1  [116])0x60200)) && ((mac_frame->mhr).dst_addr.addr_mode != '\0')) {
      mac_stop_timer(dev);
      mac_finish_op(dev);
      mac_handle_association_rsp(dev,mac_frame);
      mac_perform_next_op(dev);
    }
  }
  else if ((bVar1 == 7) && (_Var2 = mac_should_send_beacon(dev), CONCAT31(extraout_var,_Var2) != 0))
  {
    mac_start_op(dev,MAC_OPERATION_TRANSMIT_BEACON);
  }
  return;
}

