/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_beacon
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_beacon(mac_device *dev,mac_frame_t *frame)

{
  ezb_err_t eVar1;
  undefined1 auStack_2c [4];
  mac_beacon_notify_ind_t beacon_ind;
  
  auStack_2c[0] = '\0';
  auStack_2c[1] = '\0';
  auStack_2c[2] = '\0';
  auStack_2c[3] = 0;
  beacon_ind.iface_id = '\0';
  beacon_ind.bsn = '\0';
  beacon_ind.beacon_type = '\0';
  beacon_ind._3_1_ = 0;
  beacon_ind.pan_descriptor.coord_addr._0_4_ = 0;
  beacon_ind.pan_descriptor.coord_addr.u._2_4_ = 0;
  beacon_ind.pan_descriptor._8_4_ = 0;
  beacon_ind.pan_descriptor.channel_page = '\0';
  beacon_ind.pan_descriptor.channel_number = '\0';
  beacon_ind.pan_descriptor.superframe_spec = 0;
  beacon_ind.pan_descriptor.lqi = '\0';
  beacon_ind.pan_descriptor.rssi = '\0';
  beacon_ind.beacon_payload_length = '\0';
  beacon_ind._23_1_ = 0;
  eVar1 = mac_convert_beacon_to_beacon_notify_ind(frame,(mac_beacon_notify_ind_t *)auStack_2c);
  if (eVar1 == 0) {
    nwk_mm_beacon_notify_indication((dev->ctx).iface_id,auStack_2c);
  }
  return;
}

