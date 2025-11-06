/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_groups_get_group_membership_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_groups_get_group_membership_cmd_req(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 == 0) {
    uVar6 = 0x104;
  }
  else {
    uVar6 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar5,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_groups_get_group_membership_cmd_req",0x4c9,
            "esp_zb_zcl_groups_get_group_membership_cmd_req");
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    pcVar4 = (char *)zb_zcl_start_command_header(1,0,2,0);
    cVar1 = *(char *)(param_1 + 0x10);
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
    if (cVar1 != '\0') {
      for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0x10); uVar2 = uVar2 + 1 & 0xff) {
        pcVar4 = (char *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + uVar2 * 2));
      }
    }
    zb_zcl_finish_and_send_packet
              (iVar3,pcVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar6,4);
    zb_zcl_frame_get_sequence_number(iVar3);
  }
  return;
}

