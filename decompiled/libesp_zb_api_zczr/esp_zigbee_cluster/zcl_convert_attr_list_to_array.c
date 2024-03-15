/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> zcl_convert_attr_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_convert_attr_list_to_array(void *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  void *pvVar11;
  undefined4 uVar12;
  void *pvVar13;
  undefined1 *puVar14;
  uint uVar15;
  void *__nmemb;
  uint local_20;
  uint uStack_18;
  
  local_20 = local_20 & 0xffff0000;
  pvVar13 = param_1;
  if (param_1 == (void *)0x0) {
    uVar12 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC7,uVar12,"ESP_ZIGBEE_CLUSTER");
    uStack_18 = local_20;
  }
  else {
    while( true ) {
      pvVar13 = *(void **)((int)pvVar13 + 0xc);
      if (pvVar13 == (void *)0x0) break;
      local_20 = CONCAT22(local_20._2_2_,(short)local_20 + 1);
    }
    if ((local_20 & 0xffff) == 0) {
      uVar12 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CLUSTER",&_LC9,uVar12,"ESP_ZIGBEE_CLUSTER");
    }
    else {
      zcl_finish_attr_lists();
      uVar15 = (local_20 & 0xffff) + 1;
      __nmemb = (void *)(uVar15 & 0xffff);
      local_20 = CONCAT22(local_20._2_2_,(short)(uVar15 * 0x10000 >> 0x10));
      puVar10 = *(undefined1 **)((int)param_1 + 0xc);
      pvVar11 = calloc((size_t)__nmemb,10);
      if (pvVar11 == (void *)0x0) {
        pvVar11 = (void *)zb_assert("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c"
                                    ,0x66);
        goto _L0;
      }
      for (pvVar13 = (void *)0x0; pvVar13 < __nmemb; pvVar13 = (void *)((int)pvVar13 + 1U & 0xffff))
      {
_L0:
        puVar14 = (undefined1 *)((int)pvVar13 * 10 + (int)pvVar11);
        uVar1 = puVar10[1];
        uVar2 = puVar10[2];
        uVar3 = puVar10[3];
        uVar4 = puVar10[4];
        uVar5 = puVar10[5];
        uVar6 = puVar10[6];
        uVar7 = puVar10[7];
        uVar8 = puVar10[8];
        uVar9 = puVar10[9];
        *puVar14 = *puVar10;
        puVar14[1] = uVar1;
        puVar14[2] = uVar2;
        puVar14[3] = uVar3;
        puVar14[4] = uVar4;
        puVar14[5] = uVar5;
        puVar14[6] = uVar6;
        puVar14[7] = uVar7;
        puVar14[8] = uVar8;
        puVar14[9] = uVar9;
        puVar10 = *(undefined1 **)(puVar10 + 0xc);
      }
    }
    while (param_1 != (void *)0x0) {
      pvVar13 = *(void **)((int)param_1 + 0xc);
      free(param_1);
      param_1 = pvVar13;
    }
    uStack_18 = local_20;
  }
  return uStack_18;
}

