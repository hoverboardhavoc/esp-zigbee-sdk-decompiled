/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_write_attr_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar7 = 0x104;
  }
  else {
    uVar7 = *(undefined2 *)(iVar1 + 1);
  }
  iVar1 = 0;
  iVar8 = 0;
  while ((iVar1 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
    iVar6 = *(int *)(param_1 + 0x18) + iVar1 * 0xc;
    iVar6 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar6 + 2),*(undefined4 *)(iVar6 + 8));
    if (iVar6 == 0xffff) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC7,uVar2,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_write_attr_cmd_req",0xe4,
                    *(undefined2 *)(*(int *)(param_1 + 0x18) + iVar1 * 0xc));
      pcVar3 = (char *)zb_zcl_get_ctx();
      *pcVar3 = *pcVar3 + '\x01';
      return;
    }
    iVar8 = iVar6 + iVar8 + 3;
    iVar1 = iVar1 + 1;
  }
  if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
    iVar1 = 0x5a;
  }
  else {
    iVar1 = 0x5c;
  }
  iVar1 = zb_buf_get_func(0,iVar1 + iVar8);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_write_attr_cmd_req",0xea,"esp_zb_zcl_write_attr_cmd_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x10);
    uVar2 = zb_zcl_construct_general_command_header
                      (uVar5 >> 0x12 & 1,uVar5 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                       uVar5 >> 0x13 & 1,2);
    iVar8 = 0;
    while ((iVar8 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      iVar6 = iVar8 * 0xc;
      puVar4 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar6));
      *puVar4 = (char)*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar6 + 2);
      iVar6 = *(int *)(param_1 + 0x18) + iVar6;
      uVar2 = zb_zcl_put_value_to_packet
                        (puVar4 + 1,*(undefined1 *)(iVar6 + 2),*(undefined4 *)(iVar6 + 8));
      iVar8 = iVar8 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar7,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

