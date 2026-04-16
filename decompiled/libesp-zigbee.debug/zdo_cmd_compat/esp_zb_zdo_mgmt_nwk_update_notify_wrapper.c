/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_notify_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_mgmt_nwk_update_notify_wrapper
               (ezb_zdo_nwk_mgmt_nwk_update_req_result_t *result,void *user_ctx)

{
  code *pcVar1;
  ezb_zdp_nwk_mgmt_nwk_update_notify_field_t *peVar2;
  uint uStack_38;
  esp_zb_zdo_mgmt_update_notify_t notify;
  
                    /* WARNING: Load size is inaccurate */
  pcVar1 = *user_ctx;
  if (pcVar1 == (code *)0x0) goto _L0;
  uStack_38 = 0;
  notify.status = '\0';
  notify._1_3_ = 0;
  notify.scanned_channels = 0;
  notify.total_transmission = 0;
  notify.transmission_failures = 0;
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
  if (result->error == 0) {
    peVar2 = result->rsp;
    if (peVar2 == (ezb_zdp_nwk_mgmt_nwk_update_notify_field_t *)0x0) {
      __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c",
                    0x1fa,"esp_zb_zdo_mgmt_nwk_update_notify_wrapper","result->rsp");
      goto _L0;
    }
    uStack_38 = (uint)peVar2->status;
    notify._0_4_ = peVar2->scanned_channels;
    peVar2 = result->rsp;
    notify.scanned_channels._0_2_ = peVar2->total_transmissions;
    notify.scanned_channels._2_2_ = peVar2->transmissions_failure;
    notify._9_3_ = 0;
    notify.total_transmission._0_1_ = peVar2->scanned_channels_list_count;
    if (peVar2->scanned_channels_list_count != '\0') {
      memcpy((void *)((int)&notify.total_transmission + 1),peVar2->energy_values,
             (uint)peVar2->scanned_channels_list_count);
    }
  }
  else {
_L0:
    uStack_38 = CONCAT31(uStack_38._1_3_,0x85);
  }
  (*pcVar1)(&uStack_38,*(undefined4 *)((int)user_ctx + 4));
_L0:
  free(user_ctx);
  return;
}

