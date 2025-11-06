/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_read_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_nvram_app1_read_cb(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  ushort uVar9;
  uint uVar10;
  ushort *__ptr;
  int iVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  void *__dest;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  uint uVar18;
  
  if (param_3 < 2) {
    uVar12 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_SCENES","E (%lu) %s: %s(%d): The nvram data payload length error\n",
            uVar12,"ESP_ZIGBEE_ZCL_SCENES","zb_nvram_app1_read_cb",0x5c);
  }
  else if (s_nvram_app1_data == 0) {
    uVar12 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_SCENES","E (%lu) %s: %s(%d): The scenes table does not exist\n",uVar12
            ,"ESP_ZIGBEE_ZCL_SCENES","zb_nvram_app1_read_cb",0x5d);
  }
  else {
    __ptr = (ushort *)malloc(param_3);
    if (__ptr == (ushort *)0x0) {
      uVar12 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
              "E (%lu) %s: %s(%d): No memory to read scene table from NVRAM\n",uVar12,
              "ESP_ZIGBEE_ZCL_SCENES","zb_nvram_app1_read_cb",0x60);
    }
    else {
      iVar11 = zb_nvram_read_data(param_1,param_2,__ptr,param_3);
      if (iVar11 == 0) {
        uVar9 = *__ptr;
        uVar10 = 2;
        uVar18 = 0;
        while (uVar10 + 8 <= (uVar9 + 2 & 0xffff)) {
          puVar17 = (undefined1 *)((int)__ptr + uVar10);
          if (esp_zb_zcl_scenes_table_capacity <= uVar18) {
            uVar12 = esp_log_timestamp();
            esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
                    "E (%lu) %s: Scene table with a capacity of (%d) is full. Failed to restore additional scenes from NVRAM\n"
                    ,uVar12,"ESP_ZIGBEE_ZCL_SCENES",esp_zb_zcl_scenes_table_capacity);
            break;
          }
          puVar16 = (undefined1 *)(s_nvram_app1_data + uVar18 * 0xc);
          uVar2 = puVar17[1];
          uVar3 = puVar17[2];
          uVar4 = puVar17[3];
          uVar5 = puVar17[4];
          uVar6 = puVar17[5];
          uVar7 = puVar17[6];
          uVar8 = puVar17[7];
          *puVar16 = *puVar17;
          puVar16[1] = uVar2;
          puVar16[2] = uVar3;
          puVar16[3] = uVar4;
          puVar16[4] = uVar5;
          puVar16[5] = uVar6;
          puVar16[6] = uVar7;
          puVar16[7] = uVar8;
          uVar10 = uVar10 + 8;
          uVar14 = (uint)(byte)puVar17[7];
          puVar15 = (undefined1 *)0x0;
          while (uVar10 = uVar10 & 0xffff, uVar14 != 0) {
            puVar13 = (undefined1 *)malloc(0xc);
            *puVar13 = *(undefined1 *)((int)__ptr + uVar10);
            puVar13[1] = ((undefined1 *)((int)__ptr + uVar10))[1];
            bVar1 = *(byte *)((uVar10 + 2 & 0xffff) + (int)__ptr);
            puVar13[2] = bVar1;
            uVar10 = uVar10 + 3 & 0xffff;
            __dest = malloc((uint)bVar1);
            *(void **)(puVar13 + 4) = __dest;
            memcpy(__dest,(void *)((int)__ptr + uVar10),(uint)bVar1);
            uVar10 = uVar10 + (byte)puVar13[2];
            uVar14 = (uVar14 - 3 & 0xffff) - (uint)(byte)puVar13[2] & 0xffff;
            *(undefined4 *)(puVar13 + 8) = 0;
            if (puVar15 == (undefined1 *)0x0) {
              *(undefined1 **)(puVar16 + 8) = puVar13;
              puVar15 = puVar13;
            }
            else {
              *(undefined1 **)(puVar15 + 8) = puVar13;
              puVar15 = puVar13;
            }
          }
          if (*(short *)(puVar16 + 2) != -1) {
            zb_zcl_scenes_add_scene_count(*puVar17,1);
          }
          uVar18 = uVar18 + 1 & 0xff;
        }
      }
      else {
        uVar12 = esp_log_timestamp();
        esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
                "E (%lu) %s: %s(%d): Failed to read APP1 section of NVRAM\n",uVar12,
                "ESP_ZIGBEE_ZCL_SCENES","zb_nvram_app1_read_cb",99);
      }
      free(__ptr);
    }
  }
  return;
}

