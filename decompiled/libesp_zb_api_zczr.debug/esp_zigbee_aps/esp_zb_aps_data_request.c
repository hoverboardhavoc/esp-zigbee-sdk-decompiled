/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_aps.o -> esp_zb_aps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_data_request(undefined1 *param_1)

{
  int iVar1;
  void *__dest;
  undefined2 *__s;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_func(0,*(int *)(param_1 + 0xc) + 0x1a);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_APS",&_LC1,uVar2,"ESP_ZIGBEE_APS","esp_zb_aps_data_request",0x5c);
    uVar2 = 0x101;
  }
  else {
    __dest = (void *)zb_buf_initial_alloc_func(*(undefined4 *)(param_1 + 0xc));
    memcpy(__dest,*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0xc));
    __s = (undefined2 *)zb_buf_get_tail_func(iVar1,0x1a);
    memset(__s,0,0x1a);
    *(undefined1 *)((int)__s + 0xf) = *param_1;
    *__s = *(undefined2 *)(param_1 + 2);
    *(undefined1 *)(__s + 6) = param_1[4];
    __s[4] = *(undefined2 *)(param_1 + 6);
    __s[5] = *(undefined2 *)(param_1 + 8);
    *(undefined1 *)((int)__s + 0xd) = param_1[10];
    *(undefined1 *)((int)__s + 0x11) = param_1[0x15];
    __s[9] = *(undefined2 *)(param_1 + 0x16);
    *(char *)(__s + 10) = (char)*(undefined4 *)(param_1 + 0x18);
    *(undefined1 *)(__s + 8) = param_1[0x14];
    *(undefined1 *)(__s + 7) = param_1[0x1c];
    zb_schedule_callback(&zb_apsde_data_request,iVar1);
    uVar2 = 0;
  }
  return uVar2;
}

