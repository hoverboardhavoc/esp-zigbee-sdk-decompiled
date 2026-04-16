/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_ed_scan_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_ed_scan_handler(nwk_ed_scan_result_t *result,void *user_ctx)

{
  undefined1 auStack_3c [8];
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  auStack_3c._4_4_ = 0;
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
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x3f3,"zdo_mgmt_ed_scan_handler",
                  &_L0);
  }
  else {
    zmsg_get_footer(*(undefined4 *)((int)user_ctx + 0x14),auStack_3c + 4,0x28);
    zmsg_remove_footer(*(undefined4 *)((int)user_ctx + 0x14),0x28);
    if (result != (nwk_ed_scan_result_t *)0x0) {
      notify._0_4_ = notify._0_4_ | 1 << (result->channel_number & 0x1f);
      notify.scanned_channels = 0;
      if ((notify._8_4_ & 0xff) < 0x1b) {
        notify.energy_values[(notify._8_4_ & 0xff) - 4] = result->max_rssi;
        notify.total_transmissions._0_1_ = (char)notify._8_4_ + '\x01';
      }
      zmsg_add_footer(*(undefined4 *)((int)user_ctx + 0x14),auStack_3c + 4,0x28);
      return;
    }
  }
  auStack_3c._0_4_ = auStack_3c._0_4_ & 0xffffff00;
  zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),1,auStack_3c);
  auStack_3c._0_4_ = notify._0_4_;
  zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),4,auStack_3c);
  auStack_3c._0_2_ = (undefined2)notify.scanned_channels;
  zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),2,auStack_3c);
  auStack_3c._0_2_ = notify.scanned_channels._2_2_;
  zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),2,auStack_3c);
  auStack_3c[0] = (char)notify.total_transmissions;
  zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),1,auStack_3c);
  zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),notify._8_4_ & 0xff,
                    (undefined1 *)((int)&notify.total_transmissions + 1));
  zdo_packet_send(user_ctx);
  return;
}

