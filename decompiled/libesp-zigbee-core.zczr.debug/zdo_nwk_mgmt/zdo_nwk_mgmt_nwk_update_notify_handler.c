/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_nwk_update_notify_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_nwk_update_notify_handler(zdo_packet_t *packet)

{
  zdp_status_t zVar1;
  byte bVar2;
  undefined3 extraout_var;
  uint uVar3;
  undefined1 auStack_38 [4];
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  auStack_38 = (undefined1  [4])0x0;
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
    uVar3 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    uVar3 = 0xfe;
  }
  else {
    zVar1 = zdo_op_nwk_mgmt_nwk_update_notify
                      (packet->payload,(zdp_nwk_mgmt_nwk_update_notify_field_t *)auStack_38,false);
    uVar3 = CONCAT31(extraout_var,zVar1);
    if (uVar3 == 0) {
      bVar2 = zdo_cb_nwk_mgmt_nwk_update_notify
                        ((zdp_nwk_mgmt_nwk_update_notify_field_t *)auStack_38,&packet->ctx);
      uVar3 = (uint)bVar2;
    }
  }
  return (zdp_status_t)uVar3;
}

