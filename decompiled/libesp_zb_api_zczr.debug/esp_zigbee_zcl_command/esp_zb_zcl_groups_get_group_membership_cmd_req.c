/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_groups_get_group_membership_cmd_req
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
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar6,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_groups_get_group_membership_cmd_req",0x48d,
                  *(undefined1 *)(param_1 + 9));
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    iVar4 = zb_buf_get_out_func();
    if (iVar4 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar6,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_groups_get_group_membership_cmd_req",0x48e,
                    "esp_zb_zcl_groups_get_group_membership_cmd_req");
      pcVar5 = (char *)zb_zcl_get_ctx();
      *pcVar5 = *pcVar5 + '\x01';
    }
    else {
      pcVar5 = (char *)zb_zcl_start_command_header(1,0,2,0);
      cVar1 = *(char *)(param_1 + 0x10);
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
      if (cVar1 != '\0') {
        for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0x10); uVar2 = uVar2 + 1 & 0xff) {
          pcVar5 = (char *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + uVar2 * 2)
                                              );
        }
      }
      zb_zcl_finish_and_send_packet
                (iVar4,pcVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar3 + 1),4);
      zb_zcl_frame_get_sequence_number(iVar4);
    }
  }
  return;
}

