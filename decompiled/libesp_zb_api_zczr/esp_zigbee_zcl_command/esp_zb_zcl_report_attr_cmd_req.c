/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_report_attr_cmd_req(undefined2 *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  
  iVar3 = zb_zcl_get_attr_desc_manuf_a
                    (*(undefined1 *)((int)param_1 + 9),param_1[8],*(undefined1 *)(param_1 + 9),
                     param_1[10],0xffff);
  if (iVar3 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_report_attr_cmd_req",0x118,param_1[10]);
    uVar5 = 0x106;
  }
  else if ((*(byte *)(iVar3 + 3) & 4) == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC7,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_report_attr_cmd_req",0x119,param_1[10]);
    uVar5 = 0x106;
  }
  else {
    iVar3 = zb_zcl_get_ctx();
    if (*(int *)(iVar3 + 4) == 0) {
      uVar5 = 0;
    }
    else {
      uVar7 = 0;
      while( true ) {
        iVar3 = zb_zcl_get_ctx();
        if (**(byte **)(iVar3 + 4) <= uVar7) break;
        iVar3 = zb_zcl_get_ctx();
        iVar6 = uVar7 * 4;
        if (*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 1) + iVar6) + 0x1b) != 0) {
          iVar3 = zb_zcl_get_ctx();
          iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 1) + iVar6) + 0x1b);
          bVar2 = 0;
          while( true ) {
            iVar4 = zb_zcl_get_ctx();
            if (*(byte *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 1) + iVar6) + 0x1a) <= bVar2)
            break;
            if ((*(short *)(iVar3 + 2) == param_1[8]) && (*(short *)(iVar3 + 6) == param_1[10])) {
              bVar1 = *(byte *)(iVar3 + 8);
              *(byte *)(iVar3 + 8) = bVar1 | 2;
              *(byte *)(iVar3 + 8) = bVar1 | 6;
              *(byte *)(iVar3 + 8) = bVar1 & 0xf7 | 6;
              *(undefined2 *)(iVar3 + 0x28) = *param_1;
              *(undefined1 *)(iVar3 + 0x2a) = *(undefined1 *)(param_1 + 4);
              *(undefined1 *)(iVar3 + 1) = *(undefined1 *)((int)param_1 + 9);
              *(undefined2 *)(iVar3 + 0x2c) = 0x104;
              iVar4 = zb_zcl_get_ctx();
              if (*(char *)(iVar4 + 0xaa) != '\0') {
                uVar5 = zb_buf_get_out_func();
                esp_zb_zcl_send_report_attr_command(iVar3,uVar5,*(undefined4 *)(param_1 + 6));
                break;
              }
            }
            iVar3 = iVar3 + 0x30;
            bVar2 = bVar2 + 1;
          }
        }
        uVar7 = uVar7 + 1 & 0xff;
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}

