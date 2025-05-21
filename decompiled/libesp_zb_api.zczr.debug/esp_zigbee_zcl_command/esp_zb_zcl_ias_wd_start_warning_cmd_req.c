/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_wd_start_warning_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_wd_start_warning_cmd_req(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined2 uVar9;
  
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 == 0) {
    uVar9 = 0x104;
  }
  else {
    uVar9 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar7,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_ias_wd_start_warning_cmd_req",0x688,
                  "esp_zb_zcl_ias_wd_start_warning_cmd_req");
    pcVar8 = (char *)zb_zcl_get_ctx();
    *pcVar8 = *pcVar8 + '\x01';
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x12);
    bVar2 = *(byte *)(param_1 + 0x11);
    cVar3 = *(char *)(param_1 + 0x10);
    pbVar5 = (byte *)zb_zcl_start_command_header(1,0,0,0);
    *pbVar5 = bVar1 & 3 | (bVar2 & 3) << 2 | cVar3 << 4;
    puVar6 = (undefined1 *)zb_put_next_htole16(pbVar5 + 1,*(undefined2 *)(param_1 + 0x14));
    *puVar6 = *(undefined1 *)(param_1 + 0x16);
    puVar6[1] = *(undefined1 *)(param_1 + 0x17);
    zb_zcl_finish_and_send_packet
              (iVar4,puVar6 + 2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar9,0x502);
    zb_zcl_frame_get_sequence_number(iVar4);
  }
  return;
}

