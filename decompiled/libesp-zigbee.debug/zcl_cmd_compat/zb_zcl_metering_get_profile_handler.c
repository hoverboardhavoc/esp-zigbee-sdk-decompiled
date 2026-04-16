/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_metering_get_profile_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_zb_uint24_t *src;
  esp_err_t err;
  void *pvVar2;
  uint32_t *dst;
  uint __nmemb;
  undefined4 uStack_3c;
  esp_zb_zcl_metering_get_profile_message_t app_message;
  
  app_message.number_of_periods = '\0';
  app_message._13_3_ = 0;
  app_message.resp_info_offered.end_time = 0;
  app_message.resp_info_offered.status = '\0';
  app_message.resp_info_offered.profile_interval_period = '\0';
  app_message.resp_info_offered.number_of_periods_delivered = '\0';
  app_message.resp_info_offered._7_1_ = 0;
                    /* WARNING: Load size is inaccurate */
  uStack_3c = *arg;
  app_message.info.dst_endpoint = '\0';
  app_message.info.cluster = 0;
  app_message.info.status = *(byte *)((int)arg + 0xc);
  app_message._4_4_ = *(undefined4 *)((int)arg + 0x10);
  app_message.end_time = (uint32_t)*(byte *)((int)arg + 0x14);
  src = (esp_zb_uint24_t *)calloc((uint)*(byte *)((int)arg + 0x14),3);
  if (src == (esp_zb_uint24_t *)0x0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
  }
  else {
    app_message.resp_info_offered._4_4_ = src;
    if (cb != (esp_zb_core_action_callback_t)0x0) {
      err = (*cb)(ESP_ZB_CORE_METERING_GET_PROFILE_CB_ID,&uStack_3c);
      eVar1 = esp_err_to_zcl_status(err);
      *(ezb_zcl_status_t *)((int)arg + 0x18) = eVar1;
    }
    if (*(char *)((int)arg + 0x18) == '\0') {
      pvVar2 = calloc(1,0x14);
      *(void **)((int)arg + 0x1c) = pvVar2;
      if (pvVar2 == (void *)0x0) {
        esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
        return;
      }
      __nmemb = (uint)app_message.resp_info_offered.end_time._2_1_;
      *(byte *)((int)pvVar2 + 0xc) = app_message.resp_info_offered.end_time._2_1_;
      if (__nmemb != 0) {
        dst = (uint32_t *)calloc(__nmemb,4);
        if (dst == (uint32_t *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u24_to_u32(dst,src,__nmemb);
        *(uint32_t **)(*(int *)((int)arg + 0x1c) + 0x10) = dst;
        **(undefined4 **)((int)arg + 0x1c) = app_message._12_4_;
        *(uint32_t *)(*(int *)((int)arg + 0x1c) + 4) = app_message.resp_info_offered.end_time & 0xff
        ;
        *(uint32_t *)(*(int *)((int)arg + 0x1c) + 8) =
             app_message.resp_info_offered.end_time >> 8 & 0xff;
      }
      *(code **)((int)arg + 0x20) = free_memory_for_get_profile;
      *(undefined4 *)((int)arg + 0x24) = *(undefined4 *)((int)arg + 0x1c);
    }
    free(src);
  }
  return;
}

