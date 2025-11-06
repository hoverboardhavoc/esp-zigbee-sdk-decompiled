/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_cluster_update_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_update_attr(int param_1,uint param_2,void *param_3)

{
  ushort *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  size_t __size;
  uint __size_00;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar2,0x10000);
    uVar2 = 0x102;
  }
  else {
    for (puVar1 = *(ushort **)(param_1 + 0xc); puVar1 != (ushort *)0x0;
        puVar1 = *(ushort **)(puVar1 + 6)) {
      if (*puVar1 == param_2) {
        free(*(void **)(puVar1 + 3));
        __size_00 = (uint)(byte)puVar1[1];
        if ((*(byte *)((int)puVar1 + 3) & 0x40) == 0) {
          __size = esp_zb_zcl_get_attribute_size(__size_00,param_3);
          pvVar3 = malloc(__size);
          puVar1[3] = (ushort)pvVar3;
          puVar1[4] = (ushort)((uint)pvVar3 >> 0x10);
          esp_zb_zcl_put_attribute_value((char)puVar1[1],param_3,__size);
        }
        else {
          pvVar3 = malloc(__size_00);
          puVar1[3] = (ushort)pvVar3;
          puVar1[4] = (ushort)((uint)pvVar3 >> 0x10);
          memcpy(pvVar3,param_3,__size_00);
        }
        return 0;
      }
    }
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: The requested update attribute ID:0x%x is not found\n",uVar2,
            0x10000,param_2);
    uVar2 = 0x105;
  }
  return uVar2;
}

