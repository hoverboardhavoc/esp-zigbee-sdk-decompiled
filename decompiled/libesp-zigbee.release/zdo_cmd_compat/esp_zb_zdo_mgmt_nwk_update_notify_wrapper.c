/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_notify_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: notify */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_mgmt_nwk_update_notify_wrapper
               (ezb_zdo_nwk_mgmt_nwk_update_req_result_t *result,void *user_ctx)

{
  ezb_zdp_nwk_mgmt_nwk_update_notify_field_t *peVar1;
  code *pcVar2;
  uint8_t auStack_38 [4];
  esp_zb_zdo_mgmt_update_notify_t notify;
  
                    /* WARNING: Load size is inaccurate */
  pcVar2 = *user_ctx;
  if (pcVar2 != (code *)0x0) {
    memset(auStack_38,0,0x28);
    if (result->error == 0) {
      peVar1 = result->rsp;
      if (peVar1 == (ezb_zdp_nwk_mgmt_nwk_update_notify_field_t *)0x0) {
        peVar1 = (ezb_zdp_nwk_mgmt_nwk_update_notify_field_t *)__assert_func(0,0,0);
      }
      auStack_38[0] = peVar1->status;
      notify.total_transmission._0_1_ = peVar1->scanned_channels_list_count;
      notify._0_4_ = peVar1->scanned_channels;
      notify.scanned_channels._0_2_ = peVar1->total_transmissions;
      notify.scanned_channels._2_2_ = peVar1->transmissions_failure;
      if ((byte)notify.total_transmission != 0) {
        memcpy((void *)((int)&notify.total_transmission + 1),peVar1->energy_values,
               (uint)(byte)notify.total_transmission);
      }
    }
    else {
      auStack_38[0] = 0x85;
    }
    (*pcVar2)(auStack_38,*(undefined4 *)((int)user_ctx + 4));
  }
  free(user_ctx);
  return;
}

