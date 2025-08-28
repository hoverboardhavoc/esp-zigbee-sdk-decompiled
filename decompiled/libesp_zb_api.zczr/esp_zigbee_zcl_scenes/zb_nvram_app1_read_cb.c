/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_read_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_nvram_app1_read_cb(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  ushort *__ptr;
  int iVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  void *__dest;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  void *__dest_00;
  undefined1 *__src;
  uint __size;
  
  if (((param_3 < 2) || (s_nvram_app1_data == 0)) ||
     (__ptr = (ushort *)malloc(param_3), __ptr == (ushort *)0x0)) {
    return;
  }
  iVar5 = zb_nvram_read_data(param_1,param_2,__ptr,param_3);
  if (iVar5 == 0) {
    uVar3 = *__ptr;
    uVar4 = 2;
    uVar11 = 0;
    while (uVar9 = uVar4 + 8, uVar9 <= (uVar3 + 2 & 0xffff)) {
      __src = (undefined1 *)((int)__ptr + uVar4);
      if (esp_zb_zcl_scenes_table_capacity <= uVar11) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC2,uVar6,"ESP_ZIGBEE_ZCL_SCENES",
                      esp_zb_zcl_scenes_table_capacity);
        break;
      }
      __dest_00 = (void *)(s_nvram_app1_data + uVar11 * 0xc);
      memcpy(__dest_00,__src,8);
      uVar10 = (uint)(byte)__src[7];
      puVar8 = (undefined1 *)0x0;
      while (uVar4 = uVar9 & 0xffff, uVar10 != 0) {
        puVar7 = (undefined1 *)malloc(0xc);
        uVar1 = ((undefined1 *)((int)__ptr + uVar4))[1];
        *puVar7 = *(undefined1 *)((int)__ptr + uVar4);
        puVar7[1] = uVar1;
        bVar2 = *(byte *)((uVar4 + 2 & 0xffff) + (int)__ptr);
        __size = (uint)bVar2;
        puVar7[2] = bVar2;
        __dest = malloc(__size);
        uVar9 = uVar4 + 3 & 0xffff;
        *(void **)(puVar7 + 4) = __dest;
        memcpy(__dest,(void *)((int)__ptr + uVar9),__size);
        uVar9 = uVar9 + __size;
        *(undefined4 *)(puVar7 + 8) = 0;
        uVar10 = (uVar10 - 3 & 0xffff) - __size & 0xffff;
        if (puVar8 == (undefined1 *)0x0) {
          *(undefined1 **)((int)__dest_00 + 8) = puVar7;
          puVar8 = puVar7;
        }
        else {
          *(undefined1 **)(puVar8 + 8) = puVar7;
          puVar8 = puVar7;
        }
      }
      if (*(short *)((int)__dest_00 + 2) != -1) {
        zb_zcl_scenes_add_scene_count(*__src,1);
      }
      uVar11 = uVar11 + 1 & 0xff;
    }
  }
  free(__ptr);
  return;
}

