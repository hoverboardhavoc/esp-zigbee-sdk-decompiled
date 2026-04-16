/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_sampled_data_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: app_message */
/* WARNING: Unknown calling convention */

void zb_zcl_metering_get_sampled_data_resp_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_zb_uint24_t *dst;
  esp_err_t err;
  uint __nmemb;
  undefined2 uStack_28;
  undefined2 uStack_26;
  esp_zb_zcl_metering_get_sampled_data_resp_message_t app_message;
  
  memset(&app_message.info.cluster,0,0x12);
  uStack_26 = *(undefined2 *)((int)arg + 2);
  app_message._12_2_ = *(ushort *)((int)arg + 0x18);
  __nmemb = (uint)(ushort)app_message._12_2_;
                    /* WARNING: Load size is inaccurate */
  uStack_28 = *arg;
  app_message.info._0_2_ = *(undefined2 *)((int)arg + 0xc);
  app_message._4_4_ = *(undefined4 *)((int)arg + 0x10);
  app_message.sample_start_time._0_1_ = *(undefined1 *)((int)arg + 0x14);
  app_message.sample_start_time._2_2_ = *(undefined2 *)((int)arg + 0x16);
  dst = (esp_zb_uint24_t *)calloc(__nmemb,3);
  if (__nmemb == 0) {
    if (cb != (esp_zb_core_action_callback_t)0x0) goto _L0;
  }
  else {
    if (dst == (esp_zb_uint24_t *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      return;
    }
    array_copy_u32_to_u24(dst,*(uint32_t **)((int)arg + 0x1c),__nmemb);
    app_message._16_4_ = dst;
    if (cb == (esp_zb_core_action_callback_t)0x0) goto _L0;
_L0:
    err = (*cb)(ESP_ZB_CORE_METERING_GET_SAMPLED_DATA_RESP_CB_ID,&uStack_28);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x20) = eVar1;
  }
  if (dst == (esp_zb_uint24_t *)0x0) {
    return;
  }
_L0:
  free(dst);
  return;
}

