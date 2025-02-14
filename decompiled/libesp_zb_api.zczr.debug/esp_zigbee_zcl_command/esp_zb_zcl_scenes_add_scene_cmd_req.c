/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_add_scene_cmd_req(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar7;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar7 = 0x104;
  }
  else {
    uVar7 = *(undefined2 *)(iVar1 + 1);
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar3,"ESP_ZIGBEE_COMMAND",0x18000,0x538,
                  "esp_zb_zcl_scenes_add_scene_cmd_req");
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    zb_zcl_start_command_header(1,0,0,0);
    puVar2 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(param_1 + 10));
    *puVar2 = *(undefined1 *)(param_1 + 0xc);
    puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 1,*(undefined2 *)(param_1 + 0xe));
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    while (*(undefined2 **)(param_1 + 0x10) != (undefined2 *)0x0) {
      puVar2 = (undefined1 *)zb_put_next_htole16(**(undefined2 **)(param_1 + 0x10));
      *puVar2 = *(undefined1 *)(*(int *)(param_1 + 0x10) + 2);
      uVar6 = 0;
      while( true ) {
        puVar2 = puVar2 + 1;
        iVar5 = *(int *)(param_1 + 0x10);
        if (*(byte *)(iVar5 + 2) <= uVar6) break;
        *puVar2 = *(undefined1 *)(*(int *)(iVar5 + 4) + uVar6);
        uVar6 = uVar6 + 1 & 0xff;
      }
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar5 + 8);
    }
    zb_zcl_finish_and_send_packet
              (iVar1,puVar2,param_1,2,*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),
               uVar7,5);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

