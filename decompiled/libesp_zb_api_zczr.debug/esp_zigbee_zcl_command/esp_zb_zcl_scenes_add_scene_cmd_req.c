/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_add_scene_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar4,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_scenes_add_scene_cmd_req",0x4a6,*(undefined1 *)(param_1 + 9));
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar4,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_scenes_add_scene_cmd_req",0x4a7,
                    "esp_zb_zcl_scenes_add_scene_cmd_req");
      pcVar5 = (char *)zb_zcl_get_ctx();
      *pcVar5 = *pcVar5 + '\x01';
    }
    else {
      zb_zcl_start_command_header(1,0,0,0);
      puVar3 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(param_1 + 10));
      *puVar3 = *(undefined1 *)(param_1 + 0xc);
      puVar3 = (undefined1 *)zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(param_1 + 0xe));
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
      while (*(undefined2 **)(param_1 + 0x10) != (undefined2 *)0x0) {
        puVar3 = (undefined1 *)zb_put_next_htole16(**(undefined2 **)(param_1 + 0x10));
        *puVar3 = *(undefined1 *)(*(int *)(param_1 + 0x10) + 2);
        uVar7 = 0;
        while( true ) {
          puVar3 = puVar3 + 1;
          iVar6 = *(int *)(param_1 + 0x10);
          if (*(byte *)(iVar6 + 2) <= uVar7) break;
          *puVar3 = *(undefined1 *)(*(int *)(iVar6 + 4) + uVar7);
          uVar7 = uVar7 + 1 & 0xff;
        }
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar6 + 8);
      }
      zb_zcl_finish_and_send_packet
                (iVar2,puVar3,param_1,2,*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),
                 *(undefined2 *)(iVar1 + 1),5);
      zb_zcl_frame_get_sequence_number(iVar2);
    }
  }
  return;
}

