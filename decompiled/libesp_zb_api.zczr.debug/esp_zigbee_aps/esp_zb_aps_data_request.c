/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_aps.o -> esp_zb_aps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_data_request(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined4 uVar8;
  int iVar9;
  void *__dest;
  byte *__s;
  
  if (((param_1 != (byte *)0x0) && (*param_1 < 5)) &&
     ((*(int *)(param_1 + 0x14) != 0) == (*(int *)(param_1 + 0x18) != 0))) {
    iVar9 = zb_buf_get_func(0,*(int *)(param_1 + 0x14) + 0x1a);
    if (iVar9 != 0) {
      __dest = (void *)zb_buf_initial_alloc_func(*(undefined4 *)(param_1 + 0x14));
      memcpy(__dest,*(void **)(param_1 + 0x18),*(size_t *)(param_1 + 0x14));
      __s = (byte *)zb_buf_get_tail_func(iVar9,0x1a);
      memset(__s,0,0x1a);
      __s[0xf] = *param_1;
      bVar1 = param_1[3];
      bVar2 = param_1[4];
      bVar3 = param_1[5];
      bVar4 = param_1[6];
      bVar5 = param_1[7];
      bVar6 = param_1[8];
      bVar7 = param_1[9];
      *__s = param_1[2];
      __s[1] = bVar1;
      __s[2] = bVar2;
      __s[3] = bVar3;
      __s[4] = bVar4;
      __s[5] = bVar5;
      __s[6] = bVar6;
      __s[7] = bVar7;
      __s[0xc] = param_1[10];
      *(undefined2 *)(__s + 8) = *(undefined2 *)(param_1 + 0xc);
      *(undefined2 *)(__s + 10) = *(undefined2 *)(param_1 + 0xe);
      __s[0xd] = param_1[0x10];
      __s[0x11] = param_1[0x1d];
      *(undefined2 *)(__s + 0x12) = *(undefined2 *)(param_1 + 0x1e);
      __s[0x14] = (byte)*(undefined4 *)(param_1 + 0x20);
      __s[0x10] = param_1[0x1c];
      __s[0xe] = param_1[0x24];
      zb_aps_set_user_data_tx_cb(zb_aps_data_confirm_handler);
      zb_buf_flags_or_func(iVar9,0x80);
      zb_schedule_callback(&zb_apsde_data_request,iVar9);
      return 0;
    }
    uVar8 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_APS","E (%lu) %s: %s(%d): Failed to get buffer id\n",uVar8,
            "ESP_ZIGBEE_APS","esp_zb_aps_data_request",0x6e);
    return 0x101;
  }
  uVar8 = esp_log_timestamp();
  esp_log(1,"ESP_ZIGBEE_APS","E (%lu) %s: %s(%d): Invalid argument\n",uVar8,"ESP_ZIGBEE_APS",
          "esp_zb_aps_data_request",0x6a);
  return 0x102;
}

