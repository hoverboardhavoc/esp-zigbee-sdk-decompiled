/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
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
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar2 = 0;
  sVar5 = 0x98;
  while ((iVar2 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    iVar9 = *(int *)(param_1 + 0x14) + iVar2 * 0xc;
    sVar4 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar9 + 2),*(undefined4 *)(iVar9 + 8));
    sVar5 = sVar4 + sVar5;
    iVar2 = iVar2 + 1;
  }
  iVar2 = zb_buf_get_func(0,sVar5);
  if (iVar2 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar8,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_write_attr_cmd_req",0xd3);
    pcVar7 = (char *)zb_zcl_get_ctx();
    *pcVar7 = *pcVar7 + '\x01';
  }
  else {
    puVar6 = (undefined1 *)zb_buf_reuse_func();
    *puVar6 = 0;
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar7;
    *pcVar7 = cVar1 + '\x01';
    puVar6[1] = cVar1;
    puVar6[2] = 2;
    puVar6 = puVar6 + 3;
    iVar9 = 0;
    while ((iVar9 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      iVar3 = iVar9 * 0xc;
      puVar6 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar3));
      *puVar6 = (char)*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar3 + 2);
      iVar3 = *(int *)(param_1 + 0x14) + iVar3;
      puVar6 = (undefined1 *)
               zb_zcl_put_value_to_packet
                         (puVar6 + 1,*(undefined1 *)(iVar3 + 2),*(undefined4 *)(iVar3 + 8));
      iVar9 = iVar9 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar2,puVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

