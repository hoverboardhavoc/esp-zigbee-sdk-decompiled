/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_aps.o -> esp_zb_apsme_switch_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_apsme_switch_key_request(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  
  iVar8 = zb_buf_get_out_func();
  if (iVar8 == 0) {
    uVar10 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_APS",&_L0,uVar10,"ESP_ZIGBEE_APS","esp_zb_apsme_switch_key_request",
                  0xe6);
    uVar10 = 0x101;
  }
  else {
    puVar9 = (undefined1 *)zb_buf_get_tail_func(9);
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    uVar4 = param_1[4];
    uVar5 = param_1[5];
    uVar6 = param_1[6];
    uVar7 = param_1[7];
    *puVar9 = *param_1;
    puVar9[1] = uVar1;
    puVar9[2] = uVar2;
    puVar9[3] = uVar3;
    puVar9[4] = uVar4;
    puVar9[5] = uVar5;
    puVar9[6] = uVar6;
    puVar9[7] = uVar7;
    puVar9[8] = param_1[8];
    zb_schedule_callback(&zb_apsme_switch_key_request,iVar8);
    uVar10 = 0;
  }
  return uVar10;
}

