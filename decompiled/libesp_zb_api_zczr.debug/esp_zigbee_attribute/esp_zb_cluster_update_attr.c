/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
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
  void *pvVar3;
  size_t __size;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar4,0x10000);
    uVar4 = 0x102;
  }
  else {
    for (puVar2 = *(ushort **)(param_1 + 0xc); puVar2 != (ushort *)0x0;
        puVar2 = *(ushort **)(puVar2 + 6)) {
      if (*puVar2 == param_2) {
        free(*(void **)(puVar2 + 3));
        if ((*(byte *)((int)puVar2 + 3) & 0x40) == 0) {
          __size = esp_zb_zcl_get_attribute_size((char)puVar2[1],param_3);
          pvVar3 = malloc(__size);
          puVar2[3] = (ushort)pvVar3;
          puVar2[4] = (ushort)((uint)pvVar3 >> 0x10);
          esp_zb_zcl_put_attribute_value((char)puVar2[1],param_3,__size);
        }
        else {
          uVar1 = puVar2[1];
          pvVar3 = malloc((uint)(byte)uVar1);
          puVar2[3] = (ushort)pvVar3;
          puVar2[4] = (ushort)((uint)pvVar3 >> 0x10);
          memcpy(pvVar3,param_3,(uint)(byte)uVar1);
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

