/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_handlers_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_custom_cluster_handlers_update(short *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_1 + 2);
  if ((iVar4 == 0) || (iVar5 = *(int *)(param_1 + 4), iVar5 == 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar3,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_custom_cluster_handlers_update",0x713);
    uVar3 = 0x102;
  }
  else {
    iVar2 = zb_zcl_get_ctx();
    if (*(byte *)(iVar2 + 0x23c) < 0x14) {
      uVar1 = 0;
      while( true ) {
        iVar2 = zb_zcl_get_ctx();
        if (*(byte *)(iVar2 + 0x23c) <= uVar1) break;
        iVar2 = zb_zcl_get_ctx();
        if (*(short *)(iVar2 + (uVar1 + 0xf) * 0x10 + 0xc) == *param_1) {
          iVar2 = zb_zcl_get_ctx();
          if (*(char *)(iVar2 + (uVar1 + 0xf) * 0x10 + 0xe) == (char)param_1[1]) {
            iVar2 = zb_zcl_get_ctx();
            iVar6 = (uVar1 + 0xf) * 0x10;
            *(int *)(iVar2 + iVar6 + 0x14) = iVar4;
            iVar2 = zb_zcl_get_ctx();
            *(int *)(iVar2 + iVar6 + 0x18) = iVar5;
          }
        }
        uVar1 = uVar1 + 1 & 0xff;
      }
      iVar2 = zb_zcl_get_ctx();
      if (uVar1 == *(byte *)(iVar2 + 0x23c)) {
        iVar6 = zb_zcl_get_ctx();
        iVar2 = (uVar1 + 0xf) * 0x10;
        *(short *)(iVar6 + iVar2 + 0xc) = *param_1;
        iVar6 = zb_zcl_get_ctx();
        *(char *)(iVar6 + iVar2 + 0xe) = (char)param_1[1];
        iVar6 = zb_zcl_get_ctx();
        *(undefined4 *)(iVar6 + iVar2 + 0x10) = 0;
        iVar6 = zb_zcl_get_ctx();
        *(int *)(iVar6 + iVar2 + 0x14) = iVar4;
        iVar4 = zb_zcl_get_ctx();
        *(int *)(iVar4 + iVar2 + 0x18) = iVar5;
        iVar4 = zb_zcl_get_ctx();
        *(char *)(iVar4 + 0x23c) = *(char *)(iVar4 + 0x23c) + '\x01';
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC12,uVar3,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_custom_cluster_handlers_update",0x714);
      uVar3 = 0x101;
    }
  }
  return uVar3;
}

