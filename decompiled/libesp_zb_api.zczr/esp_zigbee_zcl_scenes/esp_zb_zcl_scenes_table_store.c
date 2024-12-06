/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_store(undefined2 param_1,undefined2 *param_2)

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
  if (uVar4 < 0x10) {
    iVar5 = (&DAT_000115b0)[uVar4 * 3];
    (&DAT_000115ac)[uVar4 * 6] = param_1;
    (&DAT_000115af)[uVar4 * 0xc] = 0;
    if (iVar5 != 0) {
      device_scene_free_fields();
      (&DAT_000115b0)[uVar4 * 3] = 0;
    }
    puVar7 = (undefined2 *)(&DAT_000115b0)[uVar4 * 3];
    for (; param_2 != (undefined2 *)0x0; param_2 = *(undefined2 **)(param_2 + 4)) {
      puVar6 = (undefined2 *)malloc(0xc);
      cVar1 = *(char *)(param_2 + 1);
      (&DAT_000115af)[uVar4 * 0xc] = (&DAT_000115af)[uVar4 * 0xc] + '\x03' + cVar1;
      uVar3 = *param_2;
      *(char *)(puVar6 + 1) = cVar1;
      *(undefined4 *)(puVar6 + 4) = 0;
      *puVar6 = uVar3;
      bVar2 = *(byte *)(param_2 + 1);
      __dest = malloc((uint)bVar2);
      *(void **)(puVar6 + 2) = __dest;
      memcpy(__dest,*(void **)(param_2 + 2),(uint)bVar2);
      if (puVar7 == (undefined2 *)0x0) {
        (&DAT_000115b0)[uVar4 * 3] = puVar6;
      }
      else {
        *(undefined2 **)(puVar7 + 4) = puVar6;
      }
      puVar7 = puVar6;
    }
    iVar5 = zb_nvram_write_dataset(9);
    iVar5 = -(uint)(iVar5 != 0);
  }
  else {
    iVar5 = -1;
  }
  return iVar5;
}

