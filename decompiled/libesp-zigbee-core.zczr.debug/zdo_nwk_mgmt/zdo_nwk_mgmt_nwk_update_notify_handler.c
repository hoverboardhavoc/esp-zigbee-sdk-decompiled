/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_nwk_update_notify_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_nwk_update_notify_handler(zdo_packet_t *packet)

{
  int8_t *offset_00;
  zdp_status_t zVar1;
  uint uVar2;
  undefined1 auStack_3c [4];
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  uint16_t offset;
  
  notify.energy_values[0x19] = '\0';
  notify.energy_values[0x1a] = '\0';
  auStack_3c = (undefined1  [4])0x0;
  notify.status = '\0';
  notify._1_3_ = 0;
  notify.scanned_channels = 0;
  notify.total_transmissions = 0;
  notify.transmissions_failure = 0;
  notify.scanned_channels_list_count = '\0';
  notify.energy_values[0] = '\0';
  notify.energy_values[1] = '\0';
  notify.energy_values[2] = '\0';
  notify.energy_values[3] = '\0';
  notify.energy_values[4] = '\0';
  notify.energy_values[5] = '\0';
  notify.energy_values[6] = '\0';
  notify.energy_values[7] = '\0';
  notify.energy_values[8] = '\0';
  notify.energy_values[9] = '\0';
  notify.energy_values[10] = '\0';
  notify.energy_values[0xb] = '\0';
  notify.energy_values[0xc] = '\0';
  notify.energy_values[0xd] = '\0';
  notify.energy_values[0xe] = '\0';
  notify.energy_values[0xf] = '\0';
  notify.energy_values[0x10] = '\0';
  notify.energy_values[0x11] = '\0';
  notify.energy_values[0x12] = '\0';
  notify.energy_values[0x13] = '\0';
  notify.energy_values[0x14] = '\0';
  notify.energy_values[0x15] = '\0';
  notify.energy_values[0x16] = '\0';
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    uVar2 = zmsg_get_length();
    offset_00 = notify.energy_values + 0x19;
    af_read_le8(packet->payload,(uint16_t *)offset_00,auStack_3c);
    af_read_le32(packet->payload,(uint16_t *)offset_00,(uint32_t *)&notify);
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)&notify.scanned_channels);
    af_read_le16(packet->payload,(uint16_t *)offset_00,
                 (uint16_t *)((int)&notify.scanned_channels + 2));
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)&notify.total_transmissions);
    af_read_bytes(packet->payload,(uint16_t *)offset_00,(ushort)(byte)notify.total_transmissions,
                  (uint8_t *)((int)&notify.total_transmissions + 1));
    if (uVar2 < (ushort)notify.energy_values._25_2_) {
      zVar1 = 0xfe;
    }
    else {
      zVar1 = zdo_cb_nwk_mgmt_nwk_update_notify
                        ((zdp_nwk_mgmt_nwk_update_notify_field_t *)auStack_3c,&packet->ctx);
    }
  }
  return zVar1;
}

