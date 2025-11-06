/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_ace_bypass_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_ace_bypass_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  undefined2 uVar8;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar8 = 0x104;
  }
  else {
    uVar8 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar4,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_ias_ace_bypass_cmd_req",0x5c3,
            "esp_zb_zcl_ias_ace_bypass_cmd_req");
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    pbVar3 = (byte *)zb_zcl_start_command_header(1,0,0);
    *pbVar3 = *(byte *)(param_1 + 0x10);
    for (iVar7 = 0; pbVar6 = pbVar3 + 1, iVar7 < (int)(uint)*(byte *)(param_1 + 0x10);
        iVar7 = iVar7 + 1) {
      *pbVar6 = *(byte *)(param_1 + iVar7 + 0x11);
      pbVar3 = pbVar6;
    }
    bVar1 = *(byte *)(param_1 + 0x110);
    *pbVar6 = bVar1;
    memcpy(pbVar3 + 2,(void *)(param_1 + 0x111),(uint)bVar1);
    zb_zcl_finish_and_send_packet
              (iVar2,pbVar3 + 2 + *(byte *)(param_1 + 0x110),param_1,*(undefined1 *)(param_1 + 0xc),
               *(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),uVar8,0x501);
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

