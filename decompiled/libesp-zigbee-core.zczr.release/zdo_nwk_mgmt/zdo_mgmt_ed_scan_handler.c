/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_mgmt_ed_scan_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_ed_scan_handler(nwk_ed_scan_result_t *result,void *user_ctx)

{
  uint uVar1;
  undefined1 auStack_3c [8];
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  memset(auStack_3c + 4,0,0x28);
  if (user_ctx == (void *)0x0) {
    __assert_func(0,0,0,0);
  }
  zmsg_get_footer(*(undefined4 *)((int)user_ctx + 0x14),auStack_3c + 4,0x28);
  zmsg_remove_footer(*(undefined4 *)((int)user_ctx + 0x14),0x28);
  if (result == (nwk_ed_scan_result_t *)0x0) {
    zmsg_append_u8(*(zmsg_t **)((int)user_ctx + 0x14),'\0');
    auStack_3c._0_4_ = notify._0_4_;
    zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),4,auStack_3c);
    auStack_3c._0_2_ = (undefined2)notify.scanned_channels;
    zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),2,auStack_3c);
    auStack_3c._0_2_ = notify.scanned_channels._2_2_;
    zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),2,auStack_3c);
    zmsg_append_u8(*(zmsg_t **)((int)user_ctx + 0x14),(byte)notify.total_transmissions);
    zmsg_append_bytes(*(undefined4 *)((int)user_ctx + 0x14),(byte)notify.total_transmissions,
                      (undefined1 *)((int)&notify.total_transmissions + 1));
    zdo_packet_send(user_ctx);
  }
  else {
    notify.scanned_channels = 0;
    notify._0_4_ = notify._0_4_ | 1 << (result->channel_number & 0x1f);
    uVar1 = (uint)(byte)notify.total_transmissions;
    if (uVar1 < 0x1b) {
      notify.total_transmissions._0_1_ = (byte)notify.total_transmissions + 1;
      notify.energy_values[uVar1 - 4] = result->max_rssi;
    }
    zmsg_add_footer(auStack_3c + 4,0x28);
  }
  return;
}

