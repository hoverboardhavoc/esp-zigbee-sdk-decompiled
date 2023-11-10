/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_add_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_add_privilege_command(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  pbVar2 = s_zcl_privilege_cluster_list;
  do {
    pbVar1 = pbVar2;
    if (pbVar1 == (byte *)0x0) break;
    if (((*pbVar1 == param_1) && (*(ushort *)(pbVar1 + 2) == param_2)) &&
       (*(ushort *)(pbVar1 + 4) == param_3)) {
      return 0;
    }
    pbVar2 = *(byte **)(pbVar1 + 8);
  } while (*(byte **)(pbVar1 + 8) != (byte *)0x0);
  pbVar2 = (byte *)malloc(0xc);
  if (pbVar2 == (byte *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC43,uVar3,"ESP_ZIGBEE_CORE",
                  "esp_zb_zcl_add_privilege_command",0xed);
    uVar3 = 0xffffffff;
  }
  else {
    *pbVar2 = (byte)param_1;
    *(short *)(pbVar2 + 2) = (short)param_2;
    *(short *)(pbVar2 + 4) = (short)param_3;
    pbVar2[8] = 0;
    pbVar2[9] = 0;
    pbVar2[10] = 0;
    pbVar2[0xb] = 0;
    if (pbVar1 == (byte *)0x0) {
      uVar3 = 0;
      s_zcl_privilege_cluster_list = pbVar2;
    }
    else {
      *(byte **)(pbVar1 + 8) = pbVar2;
      uVar3 = 0;
    }
  }
  return uVar3;
}

