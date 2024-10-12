/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_aps.o -> esp_zb_aps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_data_request(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  void *__dest;
  undefined1 *__s;
  undefined4 uVar9;
  
  iVar8 = zb_buf_get_func(0,*(int *)(param_1 + 0x14) + 0x1a);
  if (iVar8 == 0) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_APS",&_LC2,uVar9,"ESP_ZIGBEE_APS","esp_zb_aps_data_request",0x66);
    uVar9 = 0x101;
  }
  else {
    __dest = (void *)zb_buf_initial_alloc_func(*(undefined4 *)(param_1 + 0x14));
    memcpy(__dest,*(void **)(param_1 + 0x18),*(size_t *)(param_1 + 0x14));
    __s = (undefined1 *)zb_buf_get_tail_func(iVar8,0x1a);
    memset(__s,0,0x1a);
    __s[0xf] = *param_1;
    uVar1 = param_1[3];
    uVar2 = param_1[4];
    uVar3 = param_1[5];
    uVar4 = param_1[6];
    uVar5 = param_1[7];
    uVar6 = param_1[8];
    uVar7 = param_1[9];
    *__s = param_1[2];
    __s[1] = uVar1;
    __s[2] = uVar2;
    __s[3] = uVar3;
    __s[4] = uVar4;
    __s[5] = uVar5;
    __s[6] = uVar6;
    __s[7] = uVar7;
    __s[0xc] = param_1[10];
    *(undefined2 *)(__s + 8) = *(undefined2 *)(param_1 + 0xc);
    *(undefined2 *)(__s + 10) = *(undefined2 *)(param_1 + 0xe);
    __s[0xd] = param_1[0x10];
    __s[0x11] = param_1[0x1d];
    *(undefined2 *)(__s + 0x12) = *(undefined2 *)(param_1 + 0x1e);
    __s[0x14] = (char)*(undefined4 *)(param_1 + 0x20);
    __s[0x10] = param_1[0x1c];
    __s[0xe] = param_1[0x24];
    zb_buf_flags_or_func(iVar8,0x80);
    zb_schedule_callback(&zb_apsde_data_request,iVar8);
    uVar9 = 0;
  }
  return uVar9;
}

