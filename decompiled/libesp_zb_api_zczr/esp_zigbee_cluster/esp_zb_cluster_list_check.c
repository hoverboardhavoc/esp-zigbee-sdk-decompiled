/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_check(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC7;
  }
  else if ((param_2 == 0) || (*(int *)(param_2 + 0xc) == 0)) {
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC8;
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 10);
    if (-1 < (short)param_3) {
      if (param_3 != uVar1) {
        uVar2 = esp_log_timestamp(0);
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC9,uVar2,"ESP_ZIGBEE_CLUSTER",(uint)uVar1);
        return 0x102;
      }
      return 0;
    }
    if ((short)uVar1 < 0) {
      return 0;
    }
    uVar2 = esp_log_timestamp(0);
    puVar3 = &_LC10;
  }
  esp_log_write(1,"ESP_ZIGBEE_CLUSTER",puVar3,uVar2,"ESP_ZIGBEE_CLUSTER");
  return 0x102;
}

