/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_store(undefined4 param_1,undefined2 param_2,undefined2 *param_3)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  void *__dest;
  undefined2 *puVar7;
  
  uVar4 = device_scenes_get_free_entry();
  if (uVar4 == 0xff) {
    iVar5 = -1;
  }
  else {
    iVar5 = -1;
    if (uVar4 < esp_zb_zcl_scenes_table_capacity) {
      iVar5 = esp_zb_zcl_scenes_table + uVar4 * 0xc;
      *(undefined2 *)(iVar5 + 4) = param_2;
      *(undefined1 *)(iVar5 + 7) = 0;
      if (*(int *)(iVar5 + 8) == 0) {
        zb_zcl_scenes_add_scene_count(param_1,1);
      }
      else {
        device_scene_free_fields();
        *(undefined4 *)(iVar5 + 8) = 0;
      }
      iVar5 = esp_zb_zcl_scenes_table + uVar4 * 0xc;
      puVar7 = *(undefined2 **)(iVar5 + 8);
      for (; param_3 != (undefined2 *)0x0; param_3 = *(undefined2 **)(param_3 + 4)) {
        puVar6 = (undefined2 *)malloc(0xc);
        cVar1 = *(char *)(param_3 + 1);
        *(char *)(iVar5 + 7) = *(char *)(iVar5 + 7) + '\x03' + cVar1;
        uVar3 = *param_3;
        *(char *)(puVar6 + 1) = cVar1;
        *(undefined4 *)(puVar6 + 4) = 0;
        *puVar6 = uVar3;
        bVar2 = *(byte *)(param_3 + 1);
        __dest = malloc((uint)bVar2);
        *(void **)(puVar6 + 2) = __dest;
        memcpy(__dest,*(void **)(param_3 + 2),(uint)bVar2);
        if (puVar7 == (undefined2 *)0x0) {
          *(undefined2 **)(iVar5 + 8) = puVar6;
        }
        else {
          *(undefined2 **)(puVar7 + 4) = puVar6;
        }
        puVar7 = puVar6;
      }
      iVar5 = zb_nvram_write_dataset(9);
      iVar5 = -(uint)(iVar5 != 0);
    }
  }
  return iVar5;
}

