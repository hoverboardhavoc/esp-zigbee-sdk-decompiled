/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zcl_privilege_command_list_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zcl_privilege_command_list_add(uint param_1,uint param_2,uint param_3,undefined4 param_4)

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
      *(undefined4 *)(pbVar1 + 8) = param_4;
      return 0;
    }
    pbVar2 = *(byte **)(pbVar1 + 0xc);
  } while (*(byte **)(pbVar1 + 0xc) != (byte *)0x0);
  pbVar2 = (byte *)malloc(0x10);
  if (pbVar2 == (byte *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC1,uVar3,"ESP_ZIGBEE_CORE",
                  "esp_zcl_privilege_command_list_add",0x82);
    uVar3 = 0xffffffff;
  }
  else {
    *pbVar2 = (byte)param_1;
    *(short *)(pbVar2 + 2) = (short)param_2;
    *(short *)(pbVar2 + 4) = (short)param_3;
    *(undefined4 *)(pbVar2 + 8) = param_4;
    pbVar2[0xc] = 0;
    pbVar2[0xd] = 0;
    pbVar2[0xe] = 0;
    pbVar2[0xf] = 0;
    if (pbVar1 == (byte *)0x0) {
      uVar3 = 0;
      s_zcl_privilege_cluster_list = pbVar2;
    }
    else {
      *(byte **)(pbVar1 + 0xc) = pbVar2;
      uVar3 = 0;
    }
  }
  return uVar3;
}

