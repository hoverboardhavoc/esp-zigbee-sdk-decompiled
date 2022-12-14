/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_add_scene_cmd_req(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = zb_buf_get_out_func();
  if ((*(short *)(param_1 + 0x10) == 0) && (*(char *)(param_1 + 0x16) != '\0')) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC2,uVar4,"ESP_ZIGBEE_COMMAND",
                  *(undefined2 *)(param_1 + 0x10));
  }
  zb_zcl_start_command_header(uVar2,1,0,0,0);
  puVar3 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(param_1 + 10));
  *puVar3 = *(undefined1 *)(param_1 + 0xc);
  puVar3 = (undefined1 *)zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(param_1 + 0xe));
  *puVar3 = 0;
  puVar3 = puVar3 + 1;
  if (*(short *)(param_1 + 0x10) != 0) {
    if (*(char *)(param_1 + 0x16) == '\0') {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC2,uVar4,"ESP_ZIGBEE_COMMAND",
                    *(undefined2 *)(param_1 + 0x10));
    }
    else {
      for (uVar1 = 0; uVar1 < *(ushort *)(param_1 + 0x10); uVar1 = uVar1 + 1) {
        iVar6 = uVar1 * 0xc + param_1;
        puVar3 = (undefined1 *)zb_put_next_htole16(puVar3,*(undefined2 *)(iVar6 + 0x14));
        *puVar3 = *(undefined1 *)(iVar6 + 0x16);
        for (uVar5 = 0; puVar3 = puVar3 + 1, uVar5 < *(byte *)(uVar1 * 0xc + param_1 + 0x16);
            uVar5 = uVar5 + 1 & 0xff) {
          *puVar3 = *(undefined1 *)(*(int *)(uVar1 * 0xc + param_1 + 0x18) + uVar5);
        }
      }
    }
  }
  zb_zcl_finish_and_send_packet
            (uVar2,puVar3,param_1,2,*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),0x104,
             5);
  return;
}

