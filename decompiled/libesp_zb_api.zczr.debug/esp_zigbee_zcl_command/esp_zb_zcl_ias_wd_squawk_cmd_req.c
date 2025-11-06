/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_wd_squawk_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_wd_squawk_cmd_req(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined2 uVar8;
  
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 == 0) {
    uVar8 = 0x104;
  }
  else {
    uVar8 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar6,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_ias_wd_squawk_cmd_req",0x6aa,
            "esp_zb_zcl_ias_wd_squawk_cmd_req");
    pcVar7 = (char *)zb_zcl_get_ctx();
    *pcVar7 = *pcVar7 + '\x01';
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x12);
    bVar2 = *(byte *)(param_1 + 0x11);
    cVar3 = *(char *)(param_1 + 0x10);
    pbVar5 = (byte *)zb_zcl_start_command_header(1,0,0);
    *pbVar5 = bVar1 & 3 | (bVar2 & 1) << 3 | cVar3 << 4;
    zb_zcl_finish_and_send_packet
              (iVar4,pbVar5 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar8,0x502);
    zb_zcl_frame_get_sequence_number(iVar4);
  }
  return;
}

