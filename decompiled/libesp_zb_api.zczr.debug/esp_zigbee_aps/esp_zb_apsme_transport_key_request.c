/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_aps.o -> esp_zb_apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_apsme_transport_key_request(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  
  iVar9 = zb_buf_get_out_func();
  if (iVar9 == 0) {
    uVar11 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_APS","E (%lu) %s: %s(%d): No memory for APSME-Transport-Key Request\n",
            uVar11,"ESP_ZIGBEE_APS","esp_zb_apsme_transport_key_request",0xc4);
    uVar11 = 0x101;
  }
  else {
    puVar10 = (undefined1 *)zb_buf_get_tail_func(0x28);
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    uVar4 = param_1[4];
    uVar5 = param_1[5];
    uVar6 = param_1[6];
    uVar7 = param_1[7];
    *puVar10 = *param_1;
    puVar10[1] = uVar1;
    puVar10[2] = uVar2;
    puVar10[3] = uVar3;
    puVar10[4] = uVar4;
    puVar10[5] = uVar5;
    puVar10[6] = uVar6;
    puVar10[7] = uVar7;
    cVar8 = param_1[8];
    puVar10[9] = cVar8;
    puVar10[8] = 3;
    if (cVar8 == '\x01') {
      puVar10[0x1b] = param_1[0x22];
      puVar10[0x1a] = param_1[0x21];
      uVar1 = param_1[0x1a];
      uVar2 = param_1[0x1b];
      uVar3 = param_1[0x1c];
      uVar4 = param_1[0x1d];
      uVar5 = param_1[0x1e];
      uVar6 = param_1[0x1f];
      uVar7 = param_1[0x20];
      puVar10[0x1c] = param_1[0x19];
      puVar10[0x1d] = uVar1;
      puVar10[0x1e] = uVar2;
      puVar10[0x1f] = uVar3;
      puVar10[0x20] = uVar4;
      puVar10[0x21] = uVar5;
      puVar10[0x22] = uVar6;
      puVar10[0x23] = uVar7;
      memcpy(puVar10 + 10,param_1 + 9,0x10);
    }
    else if (cVar8 == '\x03') {
      puVar10[0x22] = param_1[0x21];
      uVar1 = param_1[0x1a];
      uVar2 = param_1[0x1b];
      uVar3 = param_1[0x1c];
      uVar4 = param_1[0x1d];
      uVar5 = param_1[0x1e];
      uVar6 = param_1[0x1f];
      uVar7 = param_1[0x20];
      puVar10[0x1a] = param_1[0x19];
      puVar10[0x1b] = uVar1;
      puVar10[0x1c] = uVar2;
      puVar10[0x1d] = uVar3;
      puVar10[0x1e] = uVar4;
      puVar10[0x1f] = uVar5;
      puVar10[0x20] = uVar6;
      puVar10[0x21] = uVar7;
      memcpy(puVar10 + 10,param_1 + 9,0x10);
    }
    else {
      if (param_1[8] != '\x04') {
        zb_buf_free_func(iVar9);
        return 0x106;
      }
      memcpy(puVar10 + 10,param_1 + 9,0x10);
    }
    zb_schedule_callback(&zb_apsme_transport_key_request,iVar9);
    uVar11 = 0;
  }
  return uVar11;
}

