/*
 * Last changed at upstream commit b278a1511ed728943e19c371f88a01e9d130f19f
 * https://github.com/espressif/esp-zigbee-sdk/commit/b278a1511ed728943e19c371f88a01e9d130f19f
 * Upstream date: 2023-02-27 14:43:05 +0800
 * Upstream subject: zcl: add ZCL API for color and report attribute(af3fa1e)
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
    esp_log_write(1,0x10000,&_LC5,uVar4,0x10000,*(undefined2 *)(param_1 + 0x10));
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
      esp_log_write(1,0x10000,&_LC5,uVar4,0x10000,*(undefined2 *)(param_1 + 0x10));
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

