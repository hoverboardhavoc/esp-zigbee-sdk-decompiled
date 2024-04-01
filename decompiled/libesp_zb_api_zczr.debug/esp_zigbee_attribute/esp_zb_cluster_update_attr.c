/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_cluster_update_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_update_attr(int param_1,uint param_2,void *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  size_t __size;
  void *pvVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC4,uVar4,0x10000);
    uVar4 = 0x102;
  }
  else {
    for (puVar2 = *(ushort **)(param_1 + 0xc); puVar2 != (ushort *)0x0;
        puVar2 = *(ushort **)(puVar2 + 6)) {
      if (*puVar2 == param_2) {
        free(*(void **)(puVar2 + 3));
        if (*(char *)((int)puVar2 + 3) == '@') {
          uVar1 = puVar2[1];
          pvVar3 = malloc((uint)(byte)uVar1);
          puVar2[3] = (ushort)pvVar3;
          puVar2[4] = (ushort)((uint)pvVar3 >> 0x10);
          memcpy(pvVar3,param_3,(uint)(byte)uVar1);
        }
        else {
          __size = esp_zb_zcl_get_attribute_size((char)puVar2[1],param_3);
          pvVar3 = malloc(__size);
          puVar2[3] = (ushort)pvVar3;
          puVar2[4] = (ushort)((uint)pvVar3 >> 0x10);
          esp_zb_zcl_put_attribute_value((char)puVar2[1],param_3,__size);
        }
        return 0;
      }
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar4,0x10000,param_2);
    uVar4 = 0x105;
  }
  return uVar4;
}

