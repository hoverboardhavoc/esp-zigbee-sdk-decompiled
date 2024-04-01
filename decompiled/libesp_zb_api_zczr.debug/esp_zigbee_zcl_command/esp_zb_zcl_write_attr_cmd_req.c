/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_write_attr_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  
  iVar6 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar6 == 0) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar9,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_write_attr_cmd_req",0xd3,*(undefined1 *)(param_1 + 9));
    pcVar8 = (char *)zb_zcl_get_ctx();
    *pcVar8 = *pcVar8 + '\x01';
  }
  else {
    iVar2 = 0;
    sVar5 = 0x98;
    while ((iVar2 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      iVar10 = *(int *)(param_1 + 0x14) + iVar2 * 0xc;
      sVar4 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar10 + 2),*(undefined4 *)(iVar10 + 8))
      ;
      sVar5 = sVar4 + sVar5;
      iVar2 = iVar2 + 1;
    }
    iVar2 = zb_buf_get_func(0,sVar5);
    if (iVar2 == 0) {
      uVar9 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar9,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_write_attr_cmd_req",0xd7,"esp_zb_zcl_write_attr_cmd_req");
      pcVar8 = (char *)zb_zcl_get_ctx();
      *pcVar8 = *pcVar8 + '\x01';
    }
    else {
      puVar7 = (undefined1 *)zb_buf_reuse_func();
      *puVar7 = 0;
      pcVar8 = (char *)zb_zcl_get_ctx();
      cVar1 = *pcVar8;
      *pcVar8 = cVar1 + '\x01';
      puVar7[1] = cVar1;
      puVar7[2] = 2;
      puVar7 = puVar7 + 3;
      iVar10 = 0;
      while ((iVar10 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
        iVar3 = iVar10 * 0xc;
        puVar7 = (undefined1 *)
                 zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar3));
        *puVar7 = (char)*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar3 + 2);
        iVar3 = *(int *)(param_1 + 0x14) + iVar3;
        puVar7 = (undefined1 *)
                 zb_zcl_put_value_to_packet
                           (puVar7 + 1,*(undefined1 *)(iVar3 + 2),*(undefined4 *)(iVar3 + 8));
        iVar10 = iVar10 + 1;
      }
      zb_zcl_finish_and_send_packet
                (iVar2,puVar7,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar6 + 1),
                 *(undefined2 *)(param_1 + 0x10));
      zb_zcl_frame_get_sequence_number(iVar2);
    }
  }
  return;
}

