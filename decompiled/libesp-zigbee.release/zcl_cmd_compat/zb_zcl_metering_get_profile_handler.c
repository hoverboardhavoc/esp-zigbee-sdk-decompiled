/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_handler
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
  undefined4 *puVar2;
  uint32_t *dst;
  uint __nmemb;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  esp_zb_zcl_metering_get_profile_message_t app_message;
  
  memset(&app_message,0,0x18);
  uStack_3a = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  uStack_3c = *arg;
  app_message.end_time._0_1_ = *(byte *)((int)arg + 0x14);
  app_message.info.status = *(esp_zb_zcl_status_t *)((int)arg + 0xc);
  app_message._4_4_ = *(undefined4 *)((int)arg + 0x10);
  src = (esp_zb_uint24_t *)calloc((uint)(byte)app_message.end_time,3);
  if (src == (esp_zb_uint24_t *)0x0) {
_L0:
    esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
    return;
  }
  app_message.resp_info_offered._4_4_ = src;
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_METERING_GET_PROFILE_CB_ID,&uStack_3c);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x18) = eVar1;
  }
  if (*(char *)((int)arg + 0x18) == '\0') {
    puVar2 = (undefined4 *)calloc(1,0x14);
    *(undefined4 **)((int)arg + 0x1c) = puVar2;
    if (puVar2 == (undefined4 *)0x0) goto _L0;
    __nmemb = (uint)app_message.resp_info_offered.end_time._2_1_;
    *(byte *)(puVar2 + 3) = app_message.resp_info_offered.end_time._2_1_;
    if (__nmemb != 0) {
      dst = (uint32_t *)calloc(__nmemb,4);
      if (dst == (uint32_t *)0x0) goto _L0;
      array_copy_u24_to_u32(dst,src,__nmemb);
      puVar2[4] = dst;
      *puVar2 = app_message._12_4_;
      puVar2[1] = (uint)(byte)app_message.resp_info_offered.end_time;
      puVar2[2] = (uint)app_message.resp_info_offered.end_time._1_1_;
    }
    *(code **)((int)arg + 0x20) = free_memory_for_get_profile;
    *(undefined4 **)((int)arg + 0x24) = puVar2;
  }
  free(src);
  return;
}

