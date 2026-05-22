/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  undefined1 auStack_38 [4];
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  memset(auStack_38,0,0x28);
  if (user_ctx == (void *)0x0) {
    __assert_func(0,0,0,0);
  }
  zmsg_get_footer(*(undefined4 *)((int)user_ctx + 0x14),auStack_38,0x28);
  zmsg_remove_footer(*(undefined4 *)((int)user_ctx + 0x14),0x28);
  if (result == (nwk_ed_scan_result_t *)0x0) {
    auStack_38[0] = '\0';
    zdo_op_nwk_mgmt_nwk_update_notify
              (*(zdo_packet_payload_t **)((int)user_ctx + 0x14),
               (zdp_nwk_mgmt_nwk_update_notify_field_t *)auStack_38,true);
    zdo_packet_send(user_ctx);
    mm_free(user_ctx);
  }
  else {
    notify.scanned_channels = 0;
    notify._0_4_ = notify._0_4_ | 1 << (result->channel_number & 0x1f);
    uVar1 = (uint)(byte)notify.total_transmissions;
    if (uVar1 < 0x1b) {
      notify.total_transmissions._0_1_ = (byte)notify.total_transmissions + 1;
      notify.energy_values[uVar1 - 4] = result->max_rssi;
    }
    zmsg_add_footer(auStack_38,0x28);
  }
  return;
}

