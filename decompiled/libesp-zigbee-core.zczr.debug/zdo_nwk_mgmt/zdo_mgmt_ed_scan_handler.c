/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_ed_scan_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_ed_scan_handler(nwk_ed_scan_result_t *result,void *user_ctx)

{
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
  if (user_ctx == (void *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x426,
                  "zdo_mgmt_ed_scan_handler",&_LC8);
  }
  else {
    zmsg_get_footer(*(undefined4 *)((int)user_ctx + 0x14),auStack_38,0x28);
    zmsg_remove_footer(*(undefined4 *)((int)user_ctx + 0x14),0x28);
    if (result != (nwk_ed_scan_result_t *)0x0) {
      notify._0_4_ = notify._0_4_ | 1 << (result->channel_number & 0x1f);
      notify.scanned_channels = 0;
      if ((notify._8_4_ & 0xff) < 0x1b) {
        notify.energy_values[(notify._8_4_ & 0xff) - 4] = result->max_rssi;
        notify.total_transmissions._0_1_ = (char)notify._8_4_ + '\x01';
      }
      zmsg_add_footer(*(undefined4 *)((int)user_ctx + 0x14),auStack_38,0x28);
      return;
    }
  }
  auStack_38 = (undefined1  [4])((uint)auStack_38 & 0xffffff00);
  zdo_op_nwk_mgmt_nwk_update_notify
            (*(zdo_packet_payload_t **)((int)user_ctx + 0x14),
             (zdp_nwk_mgmt_nwk_update_notify_field_t *)auStack_38,true);
  zdo_packet_send(user_ctx);
  mm_free(user_ctx);
  return;
}

