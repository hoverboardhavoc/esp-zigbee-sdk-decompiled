/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
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
  short sVar3;
  short sVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined2 uVar9;
  int iVar10;
  
  iVar5 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar5 == 0) {
    uVar9 = 0x104;
  }
  else {
    uVar9 = *(undefined2 *)(iVar5 + 1);
  }
  iVar5 = 0;
  sVar4 = 0x98;
  while ((iVar5 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    iVar10 = *(int *)(param_1 + 0x14) + iVar5 * 0xc;
    sVar3 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar10 + 2),*(undefined4 *)(iVar10 + 8));
    sVar4 = sVar3 + sVar4;
    iVar5 = iVar5 + 1;
  }
  iVar5 = zb_buf_get_func(0,sVar4);
  if (iVar5 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar8,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_write_attr_cmd_req",0xd7,"esp_zb_zcl_write_attr_cmd_req");
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
    iVar10 = 0;
    while ((iVar10 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      iVar2 = iVar10 * 0xc;
      puVar6 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar2));
      *puVar6 = (char)*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar2 + 2);
      iVar2 = *(int *)(param_1 + 0x14) + iVar2;
      puVar6 = (undefined1 *)
               zb_zcl_put_value_to_packet
                         (puVar6 + 1,*(undefined1 *)(iVar2 + 2),*(undefined4 *)(iVar2 + 8));
      iVar10 = iVar10 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar5,puVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar9,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar5);
  }
  return;
}

